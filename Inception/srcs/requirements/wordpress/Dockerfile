FROM wordpress:6.4.2-php8.1-fpm

RUN apt-get update && rm -rf /var/lib/apt/lists/*

COPY conf/wp-config.php /var/www/html/wp-config.php

EXPOSE 9000
