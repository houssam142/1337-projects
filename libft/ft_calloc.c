/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 17:11:26 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/24 12:27:37 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*res;
	size_t	sum;

	sum = (size * nitems);
	res = malloc(sum);
	if (!res)
	{
		return (0);
	}
	ft_bzero(res, sum);
	return (res);
}
