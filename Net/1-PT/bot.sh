#!/bin/bash
HOST='localhost'
USER='john'
PASSWD=`cat ftp.pass`

while :
do
	echo "Starting a new run"
ftp -n $HOST << EOF
user $USER $PASSWD
quit
EOF
	echo "Sleeping"
	sleep 30
done
