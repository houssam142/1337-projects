#!/bin/bash

mkdir -p /var/www/html

if [ ! -f /var/www/html/index.php ]; then
	curl -L "https://github.com" -o /var/www/html/index.php
fi

chown -R www-data:www-data /var/www/html

php -S [::]:8080 -t /var/www/html
