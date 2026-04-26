#!/bin/bash
set -e

ADMIN_USER=$(grep admin_user /run/secrets/credentials | cut -d = -f2)
ADMIN_PASS=$(grep admin_password /run/secrets/credentials | cut -d = -f2)
ADMIN_EMAIL=$(grep admin_email /run/secrets/credentials | cut -d = -f2)
WP_USER="user2"
WP_PASSWORD="1234"
WP_EMAIL="hello@gmail.com"
WORDPRESS_DB_PASSWORD=$(cat /run/secrets/db_password)
cd /var/www/html

if [ ! -f index.php ]; then

    curl -O https://wordpress.org/latest.tar.gz
    tar -xzf latest.tar.gz
    rm latest.tar.gz
    mv wordpress/* .
    rm -rf wordpress

    cp wp-config-sample.php wp-config.php

    sed -i "s/database_name_here/${WORDPRESS_DB_NAME}/" wp-config.php
    sed -i "s/username_here/${WORDPRESS_USER}/" wp-config.php
    sed -i "s/password_here/${WORDPRESS_DB_PASSWORD}/" wp-config.php
    sed -i "s/localhost/${WORDPRESS_DB_HOST}/" wp-config.php

    chown -R www-data:www-data /var/www/html
    mkdir -p wp-content/plugins
    cd wp-content/plugins
    curl -L -o redis-cache.zip https://downloads.wordpress.org/plugin/redis-cache.zip
    unzip redis-cache.zip
    rm redis-cache.zip
    wp core install \
	--url="$DOMAIN_NAME" \
	--title="Inception" \
	--admin_user="$ADMIN_USER" \
	--admin_password="$ADMIN_PASS" \
	--admin_email="$ADMIN_EMAIL" \
	--path="/var/www/html" \
	--allow-root

    wp user create $WP_USER $WP_EMAIL \
	--allow-root \
	--user_pass="$WP_PASSWORD" \
	--path="/var/www/html"
    wp config set WP_REDIS_HOST redis --allow-root
    
    wp config set WP_REDIS_PORT 6379 --allow-root   
    wp plugin install redis-cache \
	--activate \
	--allow-root

    wp redis enable \
	--allow-root
fi

exec php-fpm8.2 -F
