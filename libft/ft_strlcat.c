/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:51:52 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/25 11:38:42 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dest_len;
	size_t	to_copy;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen((const char *)dest);
	if (size <= dest_len)
		return (size + src_len);
	to_copy = size - dest_len - 1;
	if (to_copy > src_len)
		to_copy = src_len;
	while (i < to_copy)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + to_copy] = '\0';
	return (dest_len + src_len);
}
