all:
	g++ `pkg-config --cflags opencv` resizeImage.cpp myOpenCV.h -o resizeImage `pkg-config --libs opencv`
	g++ `pkg-config --cflags opencv` imageROI.cpp myOpenCV.h -o imageROI `pkg-config --libs opencv`
	g++ `pkg-config --cflags opencv` resizeVideo.cpp myOpenCV.h -o resizeVideo `pkg-config --libs opencv`
	g++ `pkg-config --cflags opencv` videoROI.cpp myOpenCV.h -o videoROI `pkg-config --libs opencv`
	g++ `pkg-config --cflags opencv` imageCLAHE.cpp myOpenCV.h -o imageCLAHE `pkg-config --libs opencv`
	g++ `pkg-config --cflags opencv` videoDetection.cpp myOpenCV.h -o videoDetection `pkg-config --libs opencv`
	g++ `pkg-config --cflags opencv` camDetect.cpp myOpenCV.h -o camDetect `pkg-config --libs opencv`
