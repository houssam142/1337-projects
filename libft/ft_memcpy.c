/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 21:09:36 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/25 21:10:50 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	size_t		i;
	unsigned char		*dest1;
	unsigned const char	*src1;

	if (!dest_str && !src_str)
		return (NULL);
	dest1 = (unsigned char *)dest_str;
	src1 = (unsigned const char *)src_str;
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
