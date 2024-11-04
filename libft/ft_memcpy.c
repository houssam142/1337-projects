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
<<<<<<< HEAD
	unsigned char		*dest1;
	unsigned const char	*src1;

	if (n == 0)
		return (dest_str);
	dest1 = (unsigned char *)dest_str;
	src1 = (unsigned const char *)src_str;
=======
	char		*dest1;
	const char	*src1;

	dest1 = (char *)dest_str;
	src1 = (const char *)src_str;
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
<<<<<<< HEAD
	return (dest1);
=======
	return (dest_str);
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
}
