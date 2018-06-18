# Alarm Clock

A simple alarm clock.

## Requirements

-	[omxplayer](https://www.raspberrypi.org/documentation/raspbian/applications/omxplayer.md)

## Steps

On Raspberry Pi:

1.	Connect 3 LEDs' positive to GPIO 4, GPIO 22, and GPIO 27 respectively with their negative to GND.
2.	Run `alarm.sh` with root privileges.

## Usage

-	`final [minutes]`: set the alarm `[minutes]` minutes later.
-	`final [minutes] [MP3 file]`: set the alarm `[minutes]` minutes later, and use `[MP3 file]` as the alarm.

Once the alarm starts ringing, type in the number of the lit LEDs. If you input the correct number and is lucky enough, the alarm will stop.

## Demo

[https://youtu.be/4ktO3VBib5s](https://youtu.be/4ktO3VBib5s)
