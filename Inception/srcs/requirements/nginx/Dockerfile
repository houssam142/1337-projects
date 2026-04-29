FROM debian:bookworm 

RUN 	apt-get update &&  \
	apt-get install nginx -y && \
	apt install openssl iputils-ping -y && \
   	rm -rf /var/lib/apt/lists/*

COPY conf/nginx.conf /etc/nginx/nginx.conf
COPY tools/entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh

EXPOSE 443

ENTRYPOINT ["/entrypoint.sh"]
