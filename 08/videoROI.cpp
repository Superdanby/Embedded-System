#include "myOpenCV.h"

int main(int argc, char **argv)
{
	IplImage* pImage = NULL;
	CvCapture* pCapture = NULL;
	CvPoint VertexOne, VertexThree;
	CvScalar Color;
	int Thickness;
	int Shift;

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
			VertexOne = cvPoint(50, 50);
			VertexThree = cvPoint(150, 150);
			Color = CV_RGB(255, 0, 0);
			Thickness = 2;
			Shift = 0;
			cvRectangle(pImage, VertexOne, VertexThree, Color, Thickness, CV_AA, Shift);

			cvShowImage("winPlayer", pImage);

			if(cvWaitKey(10) >= 0)
				break;
		}
	}

	cvReleaseCapture(&pCapture);
	cvDestroyWindow("winPlayer");
	return 0;
}
