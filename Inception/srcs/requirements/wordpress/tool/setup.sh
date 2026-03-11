#!/bin/bash
set -e

# Wait for MariaDB (ensure mysqladmin is installed)
until mysqladmin ping -h"$WORDPRESS_DB_HOST" --silent; do
    echo "Waiting for MariaDB..."
    sleep 2
done

cd /var/www/html

if [ ! -f index.php ]; then
    echo "Installing WordPress..."
    curl -O https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    mv wordpress/* .
    rm -rf wordpress latest.tar.gz
    cp wp-config-sample.php wp-config.php
    sed -i "s/database_name_here/${WORDPRESS_DB_NAME}/" wp-config.php
    sed -i "s/username_here/${WORDPRESS_DB_USER}/" wp-config.php
    sed -i "s/password_here/${WORDPRESS_DB_PASSWORD}/" wp-config.php
    sed -i "s/localhost/${WORDPRESS_DB_HOST}/" wp-config.php
    chown -R www-data:www-data /var/www/html
    chmod -R 755 /var/www/html
fi

# Start PHP-FPM in foreground
exec php-fpm8.2 -F
