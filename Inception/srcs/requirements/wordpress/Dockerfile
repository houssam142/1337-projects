FROM debian:bookworm

RUN apt-get update && \
	apt-get install -y \
	php-fpm \
	php-mysqli \
	php-curl \
	php-xml \
	php-mbstring \
	php-gd \
	curl && \
	rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

RUN curl -O https://wordpress.org/latest.tar.gz && \
    tar -xzf latest.tar.gz && \
    rm latest.tar.gz && \
    mv wordpress/* . && \
    rm -rf wordpress

RUN chown -R www-data:www-data /var/www/html

EXPOSE 9000

CMD ["php-fpm8.2", "-F"]
