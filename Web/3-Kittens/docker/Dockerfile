FROM debian:latest

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install mysql-server mysql-client apache2 \
php5 php5-mysql libapache2-mod-php5
ADD entry.sh init-sql schema.sql /tmp/
RUN /tmp/init-sql
RUN rm /var/www/html/index.html
RUN mkdir /var/www/html/css
RUN mkdir /var/www/html/fonts
RUN mkdir /var/www/html/images
RUN mkdir /var/www/html/js
ADD files/index.php /var/www/html
ADD files/login.php /var/www/html
ADD files/profile.php /var/www/html
ADD files/logout.php /var/www/html
ADD files/answer.php /var/www/html
ADD files/register.php /var/www/html
ADD files/registered.php /var/www/html
ADD files/failregister.php /var/www/html
ADD files/css/style.css /var/www/html/css
ADD files/js/image_slide.js /var/www/html/js
ADD files/js/jquery.min.js /var/www/html/js
ADD files/js/modernizr-1.5.min.js /var/www/html/js
ADD files/fonts/NewsCycle-Regular.eot /var/www/html/fonts
ADD files/fonts/NewsCycle-Regular.ttf /var/www/html/fonts
ADD files/ourwork.html /var/www/html
ADD files/testimonials.html /var/www/html
ADD files/contact.html /var/www/html
ADD files/projects.html /var/www/html
ADD files/transferform.php /var/www/html
ADD files/transfer.php /var/www/html
ADD files/images/home_1.jpg /var/www/html/images
ADD files/images/home_2.jpg /var/www/html/images
ADD files/images/transparent.png /var/www/html/images
CMD /tmp/entry.sh

EXPOSE 80

