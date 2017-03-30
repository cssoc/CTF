FROM debian:latest

ARG DEBIAN_FRONTEND=noninteractive
ARG zonedir=/etc/bind/named.conf.default-zones

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install bind9
RUN sed -i "s/OPTIONS=\"/OPTIONS=\"-4 /" /etc/default/bind9
RUN printf "\nzone \"sec5.hax.\" {" >> $zonedir && \
printf "\n\ttype master;\n\tfile \"/etc/bind/db.hax\";" >> $zonedir && \
printf "\n};" >> $zonedir
ADD db.hax /etc/bind/
ADD named.conf.log /etc/bind/
CMD /etc/init.d/bind9 start && \
/bin/bash

EXPOSE 53
