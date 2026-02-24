FROM wordpress:6.4.2-php8.1-fpm

RUN apt-get update && apt-get install curl -y && apt-get install -y iputils-ping && rm -rf /var/lib/apt/lists/*

COPY conf/wp-config.php /var/www/html/wp-config.php

EXPOSE 9000
