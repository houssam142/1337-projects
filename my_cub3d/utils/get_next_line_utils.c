/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:25:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/13 19:25:33 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		exit(1);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_malloc(len);
	if (!res)
		exit(1);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	return (res[i] = '\0', res);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*copy;
	int		l;

	l = ft_strlen(str) + 1;
	copy = ft_malloc(sizeof(char) * l);
	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	i;
	int	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;

	if (!s)
		exit(1);
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (ft_strlen(s) - start < len)
	{
		len = ft_strlen(s) - start;
	}
	str = ft_malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		exit(1);
	ft_strlcpy(str, start + s, len + 1);
	return (str);
}
