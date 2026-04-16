#!/bin/bash

set -e
if ! id "$FTP_USER" &>/dev/null; then 
	useradd -m -s /bin/bash $FTP_USER
fi
echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

mkdir -p /var/run/vsftpd/empty

usermod -d /var/www/html "$FTP_USER"

chown -R $FTP_USER:$FTP_USER /var/www/html

exec /usr/sbin/vsftpd /etc/vsftpd.conf
