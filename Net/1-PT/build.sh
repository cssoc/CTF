#!/bin/bash
cat flag.txt > .sekrit
docker build --build-arg FTP_PASS=`cat ftp.pass` -t crack/net1 .
rm .sekrit
