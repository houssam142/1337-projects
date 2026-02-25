FROM debian:bookworm

RUN apt-get update && apt install php-fpm -y \
	&& apt install wordpress -y && rm -rf /var/lib/apt/lists/*

COPY conf/wp-config.php /var/www/html/wp-config.php

EXPOSE 9000

CMD ["php-fpm8.2", "-F"]
