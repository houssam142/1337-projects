
all:
	@sudo mkdir -p /home/hounejja/data/mariadb_data
	@sudo mkdir -p /home/hounejja/data/wordpress_data
	@sudo docker compose -f srcs/docker-compose.yml up --build -d

down: 
	@sudo docker compose -f srcs/docker-compose.yml down -v --rmi all


.PHONY: down all
