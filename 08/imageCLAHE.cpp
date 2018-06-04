#include "myOpenCV.h"

using namespace cv;

int main(int argc, char **argv)
{
	IplImage* pImage = NULL;
	CvSize dst_size;
	Ptr<CLAHE> clahe;

	if (argc != 2)
		return 1;
	char* test = argv[1];
	pImage = cvLoadImage(test);
	if (!(pImage))
	{
		printf("Cannot open file ");
	}
	Mat bgr = cv::cvarrToMat(pImage);
	Mat lab;
	cvtColor(bgr, lab, CV_BGR2Lab);

	vector<Mat> lab_planes(3);
	split(lab, lab_planes);

	cvNamedWindow("graphwin", 1);
	cvNamedWindow("graphwinCLAHE", 1);

	double clipLimit=10.0;

	clahe = createCLAHE(clipLimit, cvSize(8, 8));
	Mat clahed;
	clahe->apply(lab_planes[0], clahed);
	clahed.copyTo(lab_planes[0]);
	merge(lab_planes, lab);

	Mat clahed_bgr;
	cvtColor(lab, clahed_bgr, CV_Lab2BGR);

	IplImage* pClahed = new IplImage(clahed_bgr);
	cvShowImage("graphwin", pImage);
	cvShowImage("graphwinCLAHE", pClahed);
	cvWaitKey(0);
	cvReleaseImage(&pImage);
	cvDestroyWindow("graphwin");
	cvDestroyWindow("graphwinCLAHE");
	return 0;
}
