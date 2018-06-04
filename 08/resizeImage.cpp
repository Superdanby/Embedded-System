#include "myOpenCV.h"

int main(int argc, char **argv)
{
	IplImage* pImage = NULL;
	CvSize dst_size;
	IplImage* big = NULL;

	if (argc <= 1)
		return 1;
	char* test = argv[1];
	pImage = cvLoadImage(test);
	if (!(pImage))
	{
		printf("Cannot open file ");
	}

	cvNamedWindow("graphwin", 1);
	cvShowImage("graphwin", pImage);
	cvNamedWindow("graphwin2", 1);
	float N = 1.5;
	dst_size.width = pImage->width * N;
	dst_size.height = pImage->height * N;
	big = cvCreateImage(cvSize(dst_size.width,dst_size.height), pImage->depth, pImage->nChannels);
	cvResize(pImage, big, CV_INTER_AREA);
	cvShowImage("graphwin2", big);
	cvWaitKey(0);
	cvReleaseImage(&pImage);
	cvDestroyWindow("graphwin");
	cvDestroyWindow("graphwin2");
	return 0;
}
