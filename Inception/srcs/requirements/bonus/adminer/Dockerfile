FROM debian:bookworm

RUN apt update && \
	apt install -y \
	php \
	php-mysql \
	mariadb-client \
	curl \
	adminer && \
	rm -rf /var/lib/apt/lists/*

COPY tools/setup.sh /setup.sh

RUN chmod +x /setup.sh

EXPOSE 8080

ENTRYPOINT ["/setup.sh"]

