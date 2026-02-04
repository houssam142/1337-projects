#include <cstdlib>
#include <fcntl.h>
#include <iostream>
#include <linux/in.h>
#include "netinet/in.h"
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

/*
void handle_sigint(int sig)
{
	(void)sig;
}
*/

int	main(int ac, char **av)
{
	int			fd;
	sockaddr_in	serverAddress;
	int			clientSocket;
	char		buff[1024] = {0};

	(void)ac;
	(void)av;
	fd = socket(AF_INET, SOCK_STREAM, 0);
	if (fd < 0)
		std::cout << "failed" << std::endl;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(8080);
	serverAddress.sin_addr.s_addr = INADDR_ANY;
	bind(fd, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
	listen(fd, 5);
	clientSocket = accept(fd, NULL, NULL);
	recv(clientSocket, buff, sizeof(buff), 0);
	std::cout << "Message from client: " << buff << std::endl;
	close(fd);
	return (0);
}
