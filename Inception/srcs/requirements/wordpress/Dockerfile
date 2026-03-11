FROM debian:bookworm

RUN apt-get update && \
	apt-get install -y \
	php-fpm \
	php-mysql \
	mariadb-client \
	php-curl \
	php-xml \
	php-mbstring \
	php-gd \
	iproute2 \
	netcat-openbsd \
	vim \
	curl && \
	rm -rf /var/lib/apt/lists/*

RUN sed -i 's|^listen = .*|listen = 0.0.0.0:9000|' /etc/php/8.2/fpm/pool.d/www.conf \
    && echo "listen.allowed_clients = 0.0.0.0" >> /etc/php/8.2/fpm/pool.d/www.conf

WORKDIR /var/www/html

COPY tool/setup.sh /setup.sh

RUN chmod +x /setup.sh

EXPOSE 9000

CMD ["/setup.sh"]

