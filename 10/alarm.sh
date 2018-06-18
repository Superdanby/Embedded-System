#!/bin/bash

# check arguments

if [[ $# != 1 && $# != 2 ]]; then
	printf "final [minutes]\n"
	printf "final [minutes] [MP3 file]\n"
	exit 1
fi
exit 2

# gpio

# initialization
total=3
fir=4
sec=22
third=27
song=nyanpass.mp3
if [[ $# == 2]]; then
	song=$2
fi
echo "$fir" > /sys/class/gpio/export
echo "$sec" > /sys/class/gpio/export
echo "$third" > /sys/class/gpio/export
echo "out" > /sys/class/gpio/gpio$fir/direction
echo "out" > /sys/class/gpio/gpio$sec/direction
echo "out" > /sys/class/gpio/gpio$third/direction


# gpio control
gpio () {
	if [[ $2 == up ]]; then
		echo "1" | sudo tee /sys/class/gpio/gpio$1/value
	elif [[ $2 == down ]]; then
		echo "0" | sudo tee /sys/class/gpio/gpio$1/value
	fi
}

light () {
	used[1]=false
	used[2]=false
	used[3]=false
	cnt=$1
	while [[ $cnt != 0 ]]; do
		case $(( $RANDOM % $total + 1 )) in
			1)
				if [[ ${used[1]} == false ]]; then
					gpio $fir up
					used[1]=true
					cnt=$(( $cnt - 1 ))
				fi
				;;
			2)
				if [[ ${used[2]} == false ]]; then
					gpio $sec up
					used[2]=true
					cnt=$(( $cnt - 1 ))
				fi
				;;
			3)
				if [[ ${used[3]} == false ]]; then
					gpio $third up
					used[3]=true
					cnt=$(( $cnt - 1 ))
				fi
				;;
		esac
	done
}

zero () {
	for i in $fir $sec $third; do
		gpio $i down
	done
}

# main

seconds=$(( $1 * 60 ))
sleep $seconds

(
	omxplayer --loop --vol -1500 $song
) &
subid=$!

zero
randnum=$(( $RANDOM % $total + 1 ))
light $randnum
read inp

while true; do

	if [[ $inp == $randnum && $(( $RANDOM % 3 )) == 0 ]]; then
		break
	fi

	zero
	randnum=$(( $RANDOM % $total + 1 ))
	light $randnum
	read inp

done

# finalization

ps --ppid $subid -o pid= | xargs kill
zero
echo "$fir" > /sys/class/gpio/unexport
echo "$sec" > /sys/class/gpio/unexport
echo "$third" > /sys/class/gpio/unexport
clear
echo "Nyanpasu!"
