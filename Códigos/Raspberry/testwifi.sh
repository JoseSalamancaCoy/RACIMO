#!/bin/bash

TESTIP=192.168.0.1

ping -c4 ${TESTIP} > /dev/null

if [ $? != 0 ]
then
	echo "WiFi seem down, restarting"
	sudo ifup wlan0
else
	echo "WiFi seems up"
fi
