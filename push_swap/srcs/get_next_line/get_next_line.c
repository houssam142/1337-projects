/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:21:05 by hounejja          #+#    #+#             */
/*   Updated: 2025/01/28 12:09:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/get_next_line.h"

static char	*ft_strchr_two(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i + 1]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (0);
}

static char	*locate(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[j] != '\n' && str[j])
		j++;
	tmp = malloc((sizeof(char) * j) + 1);
	if (!tmp)
		return (NULL);
	while (i < j)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static int	join(char *buffer, char **save, char **line, int fd)
{
	char	*tmp;
	char	*s;

	s = save[fd];
	save[fd] = ft_strjoin(save[fd], buffer);
	free(s);
	tmp = save[fd];
	s = ft_strchr_two(save[fd], '\n');
	if (s)
	{
		*line = locate(save[fd]);
		save[fd] = ft_strdup(s);
		free(tmp);
		return (1);
	}
	return (0);
}

int	rest(char **line, char **save, int fd)
{
	char	*tmp;
	char	*s;

	tmp = save[fd];
	s = ft_strchr_two(save[fd], '\n');
	if (s)
	{
		*line = locate(save[fd]);
		save[fd] = ft_strdup(s);
		free(tmp);
		return (1);
	}
	else if (save[fd])
	{
		*line = save[fd];
		save[fd] = NULL;
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[4864];
	int			i;
	char		*buffer;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > 4864)
		return (-1);
	if (!save[fd])
		save[fd] = ft_strdup("");
	buffer = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!buffer)
		return (-1);
	i = read(fd, buffer, BUFFER_SIZE);
	while (i > 0)
	{
		buffer[i] = '\0';
		if (join(buffer, save, line, fd))
		{
			free(buffer);
			return (1);
		}
	}
	free(buffer);
	if (i < 0)
		return (-1);
	return (rest(line, save, fd));
}
