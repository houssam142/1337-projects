FROM debian:bookworm

RUN apt-get update && \
	apt install php-fpm -y && \
	apt install -y php-mysqli && \
	apt install -y php-curl && \
	apt install -y php-xml && \
	apt install -y php-mbstring && \
	apt install -y php-gd && \
	rm -rf /var/lib/apt/lists/*

WORKDIR /var/www/html

COPY conf/wp-config.php /var/www/html/wp-config.php

EXPOSE 9000

CMD ["php-fpm8.2", "-F"]
