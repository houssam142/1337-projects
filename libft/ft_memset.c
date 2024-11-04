/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:30:09 by hounejja          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/30 14:17:52 by hounejja         ###   ########.fr       */
=======
/*   Updated: 2024/11/02 11:37:03 by hounejja         ###   ########.fr       */
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*str1;

	str1 = str;
	i = 0;
	while (i < n)
	{
		str1[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
