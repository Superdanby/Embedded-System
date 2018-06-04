#include "myOpenCV.h"

using namespace cv;

static CvMemStorage* storage = 0;
static CvHaarClassifierCascade* cascade = 0;
CvSeq* detect(IplImage* roi);
void draw(IplImage* img, CvSeq* ped);

CvSeq* detect(IplImage* roi)
{
	CvSeq* ped = NULL;
	cvClearMemStorage(storage);
	cascade = (CvHaarClassifierCascade*) cvLoad("./998_763_14_35.xml", 0, 0, 0);
	if(cascade)
		ped = cvHaarDetectObjects(roi, cascade, storage, 1.1, 2, 0, cvSize(14, 35));
	return ped;
}

void draw(IplImage* img, CvSeq* ped)
{
	int i;
	double scale = 1;
	for(i = 0; i < (ped ? ped->total : 0); i++)
	{
		CvRect* r = (CvRect*)cvGetSeqElem(ped, i);
		cvRectangle(img, cvPoint((int)((r->x) * scale), (int)((r->y) * scale)), cvPoint((int)((r->x + r->width) * scale), (int)((r->y + r->height) * scale)), CV_RGB(255, 0, 0), 2, 8, 0);
	}
}

int main(int argc, char **argv)
{
	storage = cvCreateMemStorage(0);
	CvSeq* ped;
	IplImage* pImage = NULL;
	CvCapture* pCapture = NULL;
	CvSize dst_size;
	IplImage* GImage = NULL;
	int nFrmNum = 0;
	int fps, frameH, frameW, fourcc;
	CvVideoWriter *writer;


	if (argc <= 1)
		return 1;
	char* testvideo = argv[1];
	pCapture = cvCaptureFromFile(testvideo);
	if (!(pCapture))
	{
		printf("Cannot open video file %s\n", argv[1]);
	}

	cvNamedWindow("winPlayer", 1);

	float N = 1.5;
	Ptr<CLAHE> clahe;

	while(pImage = cvQueryFrame(pCapture))
	{
		++nFrmNum;

		if(nFrmNum == 1)
		{
			fps = cvGetCaptureProperty(pCapture, CV_CAP_PROP_FPS);
			frameW = cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_WIDTH);
			frameH = cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_HEIGHT);
			fourcc = cvGetCaptureProperty(pCapture, CV_CAP_PROP_FOURCC);

			int AviColor = 1;

			writer = cvCreateVideoWriter("./out.avi", CV_FOURCC('D', 'I', 'V', '3'), fps, cvSize(340, 320), AviColor);
		}
		else
		{
			Mat bgr = cv::cvarrToMat(pImage);
			Mat lab;
			cvtColor(bgr, lab, CV_BGR2Lab);

			vector<Mat> lab_planes(3);
			split(lab, lab_planes);
			double clipLimit=10.0;

			clahe = createCLAHE(clipLimit, cvSize(8, 8));
			Mat clahed;
			clahe->apply(lab_planes[0], clahed);
			clahed.copyTo(lab_planes[0]);
			merge(lab_planes, lab);

			Mat clahed_bgr;
			cvtColor(lab, clahed_bgr, CV_Lab2BGR);

			IplImage* pClahed = new IplImage(clahed_bgr);

			ped = detect(pClahed);
			draw(pClahed, ped);

			cvShowImage("winPlayer", pClahed);

			if(cvWaitKey(10) >= 0)
				break;
		}
	}

	cvReleaseCapture(&pCapture);
	cvDestroyWindow("winPlayer");
	return 0;
}
