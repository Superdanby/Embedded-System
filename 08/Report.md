# Pedestrian Detection System

## Purpose

Learn how to use OpenCV to do some multimedia tasks on Raspberry Pi.

## Steps

1.	`wget http://director.downloads.raspberrypi.org/NOOBS/images/NOOBS-2018-04-24/NOOBS_v2_8_1.zip`
2.	Format the SD card as FAT32
3.	Extract `NOOBS_v2_8_1.zip` to the SD card
4.	Plug the SD card back on Raspberry Pi and go through the installation proccess.
5.	`sudo rpi-update`
6.	`sudo apt-get update`
7.	`sudo apt-get upgrade`
8.	`reboot`
9.	`sudo apt-get install build-essential git cmake pkg-config`
10.	`sudo apt-get install aptitude`
11.	`sudo apt-get install libjpeg-dev`
12.	`sudo aptitude install libjpeg8-dev libtiff5-dev libjasper-dev libpng12-dev`
13.	`sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libv4l-dev`
14.	`sudo apt-get install libxvidcore-dev libx264-dev`
15.	`sudo apt-get install libgtk2.0-dev`
16.	`sudo apt-get install libatlas-base-dev gfortran`
17.	`apt-cache search opencv`
18.	`apt-get install libcv2.4 libcvaux2.4 libhighgui2.4`, if the cached version is not 2.4, install the cached version.
19.	`apt-get install libcv-dev libcvaux-dev libhighgui-dev`
20.	`sudo apt-get install libopencv-dev`
21.	`curl http://www.linux-projects.org/listing/uv4l_repo/lrkey.asc | sudo apt-key add -`
22.	`echo "deb http://www.linux-projects.org/listing/uv4l_repo/raspbian/ wheezy main" | sudo tee --append /etc/apt/sources.list`
23.	`sudo apt-get update`
24.	`sudo apt-get install uv4l uv4l-raspicam`
25.	`sudo apt-get install uv4l-raspicam-extras`
26.	`sudo service uv4l_raspicam restart`
27.	`sudo rpi-update`
28.	`v4l2-ctl || sudo apt-get install v4l-utils`
29.	Connect the webcam and reboot.
30.	`v4l2-ctl --list-devices`
31.	`sudo apt-get install fswebcam`
32.	Take a picture directly with `fswebcam image.jpg`
33.	Create a script to take a picture, `mkdir $HOME/web && echo "\
#!/bin/bash
DATE=\$(date +"%Y-%m-%d_%H%M")
fswebcam --no-banner $HOME/web/\$DATE.jpg" | tee $HOME/web/webcam.sh && chmod +x $HOME/web/webcam.sh`
34.	`$HOME/web/webcam.sh`
35. `wget https://ecourse.ccu.edu.tw/50531/textbook/LAB9/998_763_14_35.xml`
36. Execute the makefile with `make`
37.	The following programs can do different things:
	-	`resizeImage [target image]`: open and resize an image
	-	`imageROI [target image]`: select region of interest of an image
	-	`resizeVideo [target video]`: open and resize a video
	-	`videoROI [target video]`: select region of interest of a video
	-	`imageCLAHE [target image]`: apply CLAHE on an image
	-	`videoDetection [target video]`: detect humans within a video
	-	`camDetect [target video]`: detect humans from the webcam

## Problems
1.	After editing `/etc/apt/sources.list`, `sudo apt-get update` will get the following error:
```sh
Hit:1 http://raspbian.raspberrypi.org/raspbian stretch InRelease    
Hit:2 http://archive.raspberrypi.org/debian stretch InRelease      
Get:3 http://www.linux-projects.org/listing/uv4l_repo/raspbian wheezy InRelease [1,155 B]
Ign:3 http://www.linux-projects.org/listing/uv4l_repo/raspbian wheezy InRelease
Fetched 1,155 B in 1s (611 B/s)
Reading package lists... Done
W: GPG error: http://www.linux-projects.org/listing/uv4l_repo/raspbian wheezy InRelease: The following signatures were invalid: 88E8F32F724468BA39585D4099DA5D2AFCE635A4
W: The repository 'http://www.linux-projects.org/listing/uv4l_repo/raspbian wheezy InRelease' is not signed.
N: Data from such a repository can\'t be authenticated and is therefore potentially dangerous to use.
N: See apt-secure(8) manpage for repository creation and user configuration details.
```
