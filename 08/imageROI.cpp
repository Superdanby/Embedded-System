#include "myOpenCV.h"

int main(int argc, char **argv)
{
	IplImage* pImage = NULL;
	CvPoint VertexOne, VertexThree;
	CvScalar Color;
	int Thickness;
	int Shift;

	if (argc <= 1)
		return 1;
	char* test = argv[1];
	pImage = cvLoadImage(test);
	if (!(pImage))
	{
		printf("Cannot open file ");
	}

	cvNamedWindow("graphwin", 1);

	VertexOne = cvPoint(50, 50);
	VertexThree = cvPoint(150, 150);
	Color = CV_RGB(255, 0, 0);
	Thickness = 2;
	Shift = 0;
	cvRectangle(pImage, VertexOne, VertexThree, Color, Thickness, CV_AA, Shift);

	cvShowImage("graphwin", pImage);

	cvWaitKey(0);
	cvReleaseImage(&pImage);
	cvDestroyWindow("graphwin");
	return 0;
}
