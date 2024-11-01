/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:30:09 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/23 14:45:31 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;
	char	*str1;

	str1 = (char *)str;
	while (str1[i] != '\0' && i < n)
	{
		str1[i] = c;
		i++;
	}
	return ((void *)str);
}
