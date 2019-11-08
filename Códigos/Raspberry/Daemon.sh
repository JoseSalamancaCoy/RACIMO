#!/bin/bash
cd /home/pi/Weather_Station/
daq=$(ps aux | grep WeatherStation.py | grep -v grep | awk '{print $2}')

if [ -f /home/pi/Weather_Station/Metadata.txt ]; then

	if [ "X${daq}" == "X" ]; then

		python /home/pi/Weather_Station/Cloudiness.py &
		sleep 1m
		python /home/pi/Weather_Station/WeatherStation.py &
	fi
fi
