FROM debian:bookworm

RUN apt-get update && \
	apt install -y \
	vsftpd && \
	rm -rf /var/lib/apt/lists/*

COPY conf/vsftpd.conf /etc/vsftpd.conf
COPY tools/setup.sh /setup.sh

RUN chmod +x /setup.sh

CMD ["/setup.sh"]

