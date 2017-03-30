#!/bin/bash

rm /tmp/init-sql
rm /tmp/init.sql

mysqld&
apachectl start
tail -f /var/log/apache2/access.log
