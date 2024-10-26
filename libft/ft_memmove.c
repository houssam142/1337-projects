/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:39:40 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/24 21:13:56 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_str, const void *src_str, size_t numBytes)
{
	size_t	i;
	char	*dest;
	char	*src;

	dest = (char *)dest_str;
	src = (char *)src_str;
	i = 0;
	if (i < 1)
	{
		while (src[i] != '\0' && i < numBytes)
		{
			dest[i] = src[i];
			i++;
		}
	}
	else
	{	
		while (i > 0)
		{
			dest[i - 1] = src[i - 1];
			i--;
		}
	}	
	return (dest);
}
