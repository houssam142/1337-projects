#!/bin/bash

if [ ! -f /var/www/html/index.php ]; then
    echo "Installing WordPress..."
    cd /var/www/html
    curl -O https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    rm latest.tar.gz
    mv wordpress/* .
    rm -rf wordpress
    chown -R www-data:www-data /var/www/html
fi

exec php-fpm8.2 -F
