#!/bin/bash

openssl req -x509 -nodes -days 365 \
        -newkey rsa:2048 \
        -keyout /etc/ssl/private/hounejja.key \
        -out /etc/ssl/certs/hounejja.crt \
        -subj "/C=MA/ST=KH/L=KH/O=42/OU=42/CN=hounejja.42.fr"

nginx -g "daemon off;"
