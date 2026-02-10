
all:
	@sudo docker compose -f srcs/docker-compose.yml up --build -d
clean:
	@sudo docker compose -f srcs/docker-compose.yml up --build -d

fclean: clean
	@sudo docker compose -f srcs/docker-compose.yml down

re: fclean all

.PHONY: re fclean all clean
