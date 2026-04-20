FROM debian:bookworm

RUN apt update && \
	apt install -y \
	git \
	make \
	vim \
	jq \
	wget \
	npm \
	golang-go \
	curl && \
	rm -rf /var/lib/apt/lists/*

COPY tools/setup.sh /setup.sh

RUN chmod +x /setup.sh

EXPOSE 9443 8999

ENTRYPOINT ["/setup.sh"]
