# Car License Recognition System

## Purpose

Learn how to use OpenALPR to recognize a car license.

## Steps

On Raspberry Pi:

1.	`sudo apt-get update`
2.	`sudo apt-get upgrade`
3.	`sudo apt-get install autoconf automake libtool libleptonica-dev libicu-dev libpango1.0-dev libcairo2-dev cmake git libgtk2.0-dev pkg-config libavcodec-dev libavformat-dev libswscale-dev python-dev python-numpy libjpeg-dev libpng-dev libtiff-dev libjasper-dev libdc1394-22-dev virtualenvwrapper liblog4cplus-dev libcurl4-openssl-dev`
4.	`sudo apt-get install libjpeg-dev libtiff5-dev libpng12-dev gcc make`
5.	`wget http://www.leptonica.com/source/leptonica-1.74.4.tar.gz`
6.	`tar zxvf leptonica-1.74.4.tar.gz`
7.	`cd leptonica-1.74.4`
8.	`./configure`
9.	`make -j 3`
10.	`sudo make install`
11.	`sudo apt-get install ca-certificates git`
12.	`sudo apt-get install autoconf automake libtool`
13.	`sudo apt-get install autoconf-archive`
14.	`sudo apt-get install pkg-config`
15.	`sudo apt-get install libicu-dev`
16.	`sudo apt-get install libpango1.0-dev`
17.	`sudo apt-get install libcairo2-dev`
18.	`git clone https://github.com/tesseract-ocr/tesseract.git`
19.	`cd /tesseract`
20.	`git checkout 3.04.01`
21.	`./autogen.sh`
22.	`./configure --enable-debug`
23.	`make -j 3`
24.	`sudo make install`
25.	`sudo ldconfig`
26.	`apt-cache search opencv`
27.	`apt-get install libcv2.4 libcvaux2.4 libhighgui2.4 --reinstall`, if the cached version is not 2.4, install the cached version.
28.	`apt-get install libcv-dev libcvaux-dev libhighgui-dev --reinstall`
29.	`sudo apt-get install libopencv-dev --reinstall`
30.	`sudo apt-get install cmake`
31.	`sudo apt-get install liblog4cplus-dev libcurl3-dev`
32.	`sudo apt-get install beanstalkd`
33.	`export JAVA_HOME=/usr/lib/jvm/`***Java directory***
34.	`git clone https://github.com/openalpr/openalpr.git`
35.	`cd openalpr/src`
36.	`mkdir build`
37.	`cd build`
38.	`cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr -DCMAKE_INSTALL_SYSCONFDIR:PATH=/etc ../`
39.	`make -j 3`
40.	`sudo make install`
41.	Find a picture which contains a car license plate.
42.	`alpr [target picture]`

## Problems

1.	There were some problems related OpenCV. Reinstalling OpenCV components fixed the problems.
