#include "myOpenCV.h"

int main(int argc, char **argv)
{
	IplImage* pImage = NULL;
	CvCapture* pCapture = NULL;
	CvSize dst_size;
	IplImage* big = NULL;

	int nFrmNum = 0;
	int fps, frameH, frameW, fourcc;

	if (argc <= 1)
		return 1;
	char* testvideo = argv[1];
	pCapture = cvCaptureFromFile(testvideo);
	if (!(pCapture))
	{
		printf("Cannot open video file %s\n", argv[1]);
	}

	cvNamedWindow("winPlayer", 1);
	cvNamedWindow("winPlayer2", 1);

	float N = 1.5;

	while(pImage = cvQueryFrame(pCapture))
	{
		++nFrmNum;

		if(nFrmNum == 1)
		{
			fps = cvGetCaptureProperty(pCapture, CV_CAP_PROP_FPS);
			frameW = cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_WIDTH);
			frameH = cvGetCaptureProperty(pCapture, CV_CAP_PROP_FRAME_HEIGHT);
			fourcc = cvGetCaptureProperty(pCapture, CV_CAP_PROP_FOURCC);
		}
		else
		{
			cvShowImage("winPlayer", pImage);
			dst_size.width = pImage->width * N;
			dst_size.height = pImage->height * N;
			big = cvCreateImage(cvSize(dst_size.width, dst_size.height), pImage->depth, pImage->nChannels);
			cvResize(pImage, big, CV_INTER_AREA);
			cvShowImage("winPlayer2", big);
			if(cvWaitKey(10) >= 0)
				break;
		}
	}

	cvReleaseCapture(&pCapture);
	cvDestroyWindow("winPlayer");
	cvDestroyWindow("winPlayer2");
	return 0;
}
