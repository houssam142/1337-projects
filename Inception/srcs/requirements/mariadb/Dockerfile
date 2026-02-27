FROM debian:bookworm

RUN apt-get update && \
	apt-get install -y mariadb-server && \
	rm -rf /var/lib/apt/lists/*

COPY tools/create_db.sh /create_db.sh

RUN chmod +x /create_db.sh

EXPOSE 3306

ENTRYPOINT ["/create_db.sh"]

CMD ["mysqld_safe"]

