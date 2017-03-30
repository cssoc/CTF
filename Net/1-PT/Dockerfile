FROM debian:latest

ARG DEBIAN_FRONTEND=noninteractive
ARG FTP_PASS=123456

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install proftpd-basic

RUN sed -i 's/UseIPv6 /#UseIPv6/' /etc/proftpd/proftpd.conf && \
sed -i 's/# DefaultRoot/DefaultRoot/' /etc/proftpd/proftpd.conf && \
sed -i 's/# PassivePorts .*/PassivePorts 3000 3010/' /etc/proftpd/proftpd.conf && \
sed -i 's/# Auth/Auth/' /etc/proftpd/proftpd.conf

RUN useradd -m john && \
echo "john:$FTP_PASS" | chpasswd

ADD .sekrit /home/john/
RUN chmod 444 /home/john/.*
RUN chmod +x /home /home/john

CMD proftpd -n

EXPOSE 21 3000-3010
