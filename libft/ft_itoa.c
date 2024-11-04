/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:38:11 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/02 15:23:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	o;

	o = n;
	i = numlen(n);
	res = malloc(sizeof(char) * (i + 1));
<<<<<<< HEAD
	if (!res)
		return (NULL);
=======
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
	res[i--] = '\0';
	if (o < 0)
	{
		res[0] = '-';
		o *= -1;
	}
	if (o == 0)
		res[i] = '0';
	while (o > 0)
	{
		res[i] = o % 10 + 48;
		o /= 10;
		i--;
	}
	return (res);
}
//int main()
//{
<<<<<<< HEAD
//	printf("%s", ft_itoa(2147483647));
=======
//	printf("%s", ft_itoa(2147483649));
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
//}
