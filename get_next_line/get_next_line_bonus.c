/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:34:02 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/27 18:27:40 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr_bonus(const char *str, int search_str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)search_str)
		{
			break ;
		}
		i++;
	}
	if (str[i] == (unsigned char)search_str)
	{
		return ((char *)str + i);
	}
	return (0);
}

static char	*keep_rest(char **temp, int start, int fd)
{
	char	*rest;
	int		len;

	len = ft_strlen_bonus(temp[fd]) - start;
	if (len <= 0)
	{
		free(temp[fd]);
		return (NULL);
	}
	rest = ft_substr_bonus(temp[fd], start, len);
	free(temp[fd]);
	return (rest);
}

static char	*extract_line(char **temp, int *start_next, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (temp[fd][i] && temp[fd][i] != '\n')
		i++;
	if (temp[fd][i] == '\n')
		*start_next = i + 1;
	else
	{
		*start_next = i;
		if (i == 0 && temp[fd][i] == '\0')
			return (NULL);
	}
	line = ft_substr_bonus(temp[fd], 0, *start_next);
	return (line);
}

static char	*new_line(int fd, char *buffer, char **temp)
{
	ssize_t	read_bytes;
	char	*new_temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr_bonus(temp[fd], '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(temp[fd]);
			return (NULL);
		}
		if (read_bytes == 0)
		{
			if (temp[fd] == NULL)
				return (NULL);
			return (temp[fd]);
		}
		buffer[read_bytes] = '\0';
		new_temp = ft_strjoin_bonus(temp[fd], buffer);
		free(temp[fd]);
		temp[fd] = new_temp;
	}
	return (temp[fd]);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*temp[OPEN_MAX];
	int			start_next;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!temp[fd])
		temp[fd] = ft_strdup_bonus("");
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	temp[fd] = new_line(fd, buffer, temp);
	free(buffer);
	if (!temp[fd])
		return (NULL);
	line = extract_line(temp, &start_next, fd);
	temp[fd] = keep_rest(temp, start_next, fd);
	return (line);
}

// int	main(void)
//{
//	char	*line1;
//	char	*line2;

//	int fd1, fd2;
//	line1 = NULL;
//	line2 = NULL;
//	fd1 = open("hello.txt", O_RDONLY);
//	if (fd1 < 0)
//	{
//		perror("Error opening roo.txt");
//		return (1);
//	}
//	fd2 = open("text.txt", O_RDONLY);
//	if (fd2 < 0)
//	{
//		perror("Error opening too.txt");
//		close(fd1);
//		return (1);
//	}
//	while (1)
//	{
//		line1 = get_next_line(fd1);
//		line2 = get_next_line(fd2);
//		if (line1 == NULL && line2 == NULL)
//			break ;
//		if (line1)
//		{
//			printf("File1: %s", line1);
//			free(line1);
//		}
//		if (line2)
//		{
//			printf("File2: %s", line2);
//			free(line2);
//		}
//	}
//	close(fd1);
//	close(fd2);
//	return (0);
//}
