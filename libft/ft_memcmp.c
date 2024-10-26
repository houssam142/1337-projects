/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:54:42 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/23 17:19:30 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;
	char	*str3;
	char	*str4;

	str3 = (char *)str1;
	str4 = (char *)str2;
	i = 0;
	while (str3[i] != '\0' && str4[i] != '\0')
	{
		if (str3[i] != str4[i] && i < n)
		{
			return (str3[i] - str4[i]);
		}
		i++;
	}
	return (str3[i] - str4[i]);
}
