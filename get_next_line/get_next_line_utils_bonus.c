/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:48:15 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/20 15:03:00 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_bonus(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_bonus(char const *s1, char const *s2)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen_bonus(s1) + ft_strlen_bonus(s2) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (NULL);
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

char	*ft_strdup_bonus(const char *str)
{
	size_t	i;
	char	*copy;
	size_t	l;

	l = ft_strlen_bonus(str) + 1;
	copy = malloc(sizeof(char) * l);
	i = 0;
	if (copy == NULL)
	{
		return (NULL);
	}
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return ((char *)copy);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen_bonus(src);
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

char	*ft_substr_bonus(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen_bonus(s))
	{
		return (ft_strdup_bonus(""));
	}
	if (ft_strlen_bonus(s) - start < len)
	{
		len = ft_strlen_bonus(s) - start;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(str, start + s, len + 1);
	return (str);
}