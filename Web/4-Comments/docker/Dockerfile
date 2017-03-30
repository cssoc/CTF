FROM debian:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install mysql-server mysql-client apache2 \
php5 php5-mysql libapache2-mod-php5
ADD entry.sh init-sql schema.sql /tmp/
RUN /tmp/init-sql
RUN mkdir /var/www/html/css
RUN mkdir /var/www/html/js
RUN mkdir /var/www/html/images
ADD files/css/style.css /var/www/html/css
ADD files/images/background.jpg /var/www/html/images
ADD files/images/home_1.jpg /var/www/html/images
ADD files/images/home_2.jpg /var/www/html/images
ADD files/images/transparent.png /var/www/html/images
ADD files/js/image_slide.js /var/www/html/js
ADD files/js/jquery.min.js /var/www/html/js
ADD files/index.php /var/www/html
ADD files/login.php /var/www/html
ADD files/flag.php /var/www/html
ADD files/profile.php /var/www/html
ADD files/logout.php /var/www/html
RUN rm /var/www/html/index.html
ADD files/contact.html /var/www/html
ADD files/ourwork.html /var/www/html
ADD files/projects.html /var/www/html
ADD files/testimonials.html /var/www/html

CMD /tmp/entry.sh

EXPOSE 80
