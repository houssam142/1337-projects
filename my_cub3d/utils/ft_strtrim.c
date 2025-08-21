/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:33:13 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/21 08:23:19 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	search(char const *s2, char c)
{
	while (*s2 && c != *s2)
	{
		s2++;
	}
	return (c == *s2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	if (!s1)
		exit(1);
	len = ft_strlen(s1);
	i = 0;
	while (i < len && search(set, s1[i]))
		i++;
	if (i == len)
	{
		return (ft_strdup(""));
	}
	while (len > i && search(set, s1[len - 1]))
	{
		len--;
	}
	return (ft_substr(s1, i, len - i));
}
