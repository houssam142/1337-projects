FROM mariadb:10.11 

COPY conf/create_db.sh /docker-entrypoint-initdb.d/create_db.sh

RUN chmod +x /docker-entrypoint-initdb.d/create_db.sh

EXPOSE 3306

