FROM debian:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install mysql-server mysql-client apache2 \
php5 php5-mysql libapache2-mod-php5
ADD entry.sh init-sql init.sql /tmp/
RUN /tmp/init-sql
ADD toUpload/index.html /var/www/html
ADD toUpload/login.php /var/www/html
ADD toUpload/flag.php /var/www/html
CMD /tmp/entry.sh

EXPOSE 80
