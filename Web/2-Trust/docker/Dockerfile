FROM debian:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install mysql-server mysql-client apache2 \
php5 php5-mysql libapache2-mod-php5
ADD entry.sh init-sql schema.sql /tmp/
RUN /tmp/init-sql
RUN rm /var/www/html/index.html
ADD files/index.php /var/www/html
ADD files/login.php /var/www/html
ADD files/profile.php /var/www/html
ADD files/logout.php /var/www/html
ADD files/failregister.php /var/www/html
ADD files/register.php /var/www/html
ADD files/registered.php /var/www/html
ADD files/changepassword.php /var/www/html
ADD files/newpassword.php /var/www/html
ADD files/adminprofile.php /var/www/html
ADD files/names.txt /var/www/html
RUN chmod 777 /var/www/html/names.txt

CMD /tmp/entry.sh

EXPOSE 80

