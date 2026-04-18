#!/bin/bash
set -e

cd /var/www/html

if [ ! -f index.php ]; then

    curl -O https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    rm latest.tar.gz
    mv wordpress/* .
    rm -rf wordpress

    cp wp-config-sample.php wp-config.php

    sed -i "s/database_name_here/${WORDPRESS_DB_NAME}/" wp-config.php
    sed -i "s/username_here/${WORDPRESS_DB_USER}/" wp-config.php
    sed -i "s/password_here/${WORDPRESS_DB_PASSWORD}/" wp-config.php
    sed -i "s/localhost/${WORDPRESS_DB_HOST}/" wp-config.php

    chown -R www-data:www-data /var/www/html
    mkdir -p wp-content/plugins
    cd wp-content/plugins
    curl -L -o redis-cache.zip https://downloads.wordpress.org/plugin/redis-cache.zip
    unzip redis-cache.zip
    rm redis-cache.zip
fi

exec php-fpm8.2 -F
