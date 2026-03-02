FROM debian:bookworm

RUN apt-get update && \
	apt-get install -y \
	php-fpm \
	php-mysql \
	php-curl \
	php-xml \
	php-mbstring \
	php-gd \
	curl && \
	rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

COPY tool/setup.sh /setup.sh

RUN chmod +x /setup.sh

EXPOSE 9000

CMD ["/setup.sh"]
