FROM debian:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get install -y python

ADD server.py home/
ADD groot.wav home/
ADD hack.sh home/

CMD home/hack.sh

EXPOSE 4446
