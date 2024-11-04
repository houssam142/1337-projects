/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:56:20 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/26 14:16:22 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (len == 0)
		return ((char *)str);
	if (to_find[0] == '\0')
	{
		return ((char *)str);
	}
	while (str[i])
	{
		j = 0;
<<<<<<< HEAD
		while (str[i + j] == to_find[j] && i + j < len && str[i + j] && to_find[j])
=======
		while (str[i + j] == to_find[j] && i + j < len)
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
		{
			j++;
		}
		if (j == ft_strlen(to_find))
		{
			return ((char *)str + i);
		}
		i++;
	}
	return (NULL);
}
