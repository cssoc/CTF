FROM debian:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install mysql-server mysql-client apache2 \
php5 php5-mysql libapache2-mod-php5
ADD entry.sh init-sql init.sql phpbb.txt cars.txt /tmp/
RUN /tmp/init-sql
ADD toUpload/index.php /var/www/html
ADD toUpload/login.php /var/www/html
ADD toUpload/flag.php /var/www/html
ADD toUpload/.htaccess /var/www/html
RUN rm /var/www/html/index.html
CMD /tmp/entry.sh

EXPOSE 80
