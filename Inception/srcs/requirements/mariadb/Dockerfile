FROM debian:bookworm

RUN apt-get update && apt install mariadb-server -y

COPY conf/create_db.sh /docker-entrypoint-initdb.d/create_db.sh

RUN chmod +x /docker-entrypoint-initdb.d/create_db.sh \
	&& rm -rf /var/lib/apt/lists/*

EXPOSE 3306

CMD ["mysqld_safe"]
