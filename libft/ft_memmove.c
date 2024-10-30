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
	if (!dest || !src)
		return (NULL);
	if (i < 1)
	{
		ft_memcpy(dest, src, numBytes);
	}
	else
	{
		while (numBytes--)
			*((unsigned char *)(dest + numBytes)) = *((unsigned char *)(src + numBytes));	
	}	
	return (dest);
}
int main()
{
	char str[] = "hello worldk";
	printf("%s\n", (char *)ft_memmove(str + 2, str, 5));
	printf("\n%s", (char *)memmove(str + 2, str, 5));
}
