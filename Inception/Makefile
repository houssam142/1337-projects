
all:
	@sudo docker compose -f srcs/docker-compose.yml up --build -d
clean:
	@docker compose -f srcs/docker-compose.yml up --build -d

fclean: clean
	@docker compose -f srcs/docker-compose.yml down

re: fclean all

.PHONY: re fclean all clean
