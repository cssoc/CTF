#!/bin/bash

rm /tmp/init-sql
rm /tmp/init.sql
rm /tmp/cars.txt
rm /tmp/phpbb.txt

mysqld&
apachectl start
tail -f /var/log/apache2/access.log
