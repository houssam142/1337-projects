#!/bin/bash

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld
chown -R mysql:mysql /var/lib/mysql

DB_PASSWORD=$(cat /run/secrets/db_password)
DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)

# Initialize database if empty
if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=mysql --ldata=/var/lib/mysql
fi

# Start temporary server
mysqld --user=mysql --skip-networking &

# Wait until MariaDB is ready
until mysqladmin ping --silent; do
    sleep 1
done

# Create database and user
mysql -u root -p"$DB_ROOT_PASSWORD" <<EOF
CREATE DATABASE IF NOT EXISTS ${DB_DATABASE};
DROP USER IF EXISTS '${DB_USER}'@'%';
CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_DATABASE}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF

mysql -u root -p"$DB_ROOT_PASSWORD" << EOF
USE ${DB_DATABASE};
CREATE TABLE uploads (
    id INT AUTO_INCREMENT PRIMARY KEY,
    filename VARCHAR(255),
    filepath VARCHAR(255),
    user_id INT,
    upload_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
EOF

mysqladmin shutdown

exec mysqld --user=mysql
