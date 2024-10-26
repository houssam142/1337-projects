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
	size_t	i;
	char	*dest1;
	char	*src1;

	dest1 = (char *)dest_str;
	src1 = (char *)src_str;
	i = 0;
	while (src1[i] != '\0' && i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	dest1[i] = '\0';
	return (dest1);
}
