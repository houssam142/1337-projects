FROM debian:bookworm

RUN apt-get update && \
	apt-get install -y \
	php-fpm \
	php-mysql \
	php-curl \
	php-redis \
	php-gd \
	mariadb-client \
	unzip \
	curl && \
	rm -rf /var/lib/apt/lists/*

RUN sed -i 's|^listen = .*|listen = 0.0.0.0:9000|' /etc/php/8.2/fpm/pool.d/www.conf

WORKDIR /var/www/html

COPY tool/setup.sh /setup.sh

RUN chmod +x /setup.sh

EXPOSE 9000

ENTRYPOINT ["/setup.sh"]
