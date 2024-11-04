/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:16:10 by hounejja          #+#    #+#             */
/*   Updated: 2024/10/25 18:34:59 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

<<<<<<< HEAD
	if (!s)
		return (NULL);
=======
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
	if (start >= ft_strlen(s))
	{
		return (ft_strdup(""));
	}
	if (ft_strlen(s) - start < len)
	{
		len = ft_strlen(s) - start;
	}
	str = malloc(sizeof(char) * (len + 1));
<<<<<<< HEAD
	if (!str)
		return (NULL);
=======
	if (str == NULL)
	{
		return (NULL);
	}
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
	ft_strlcpy(str, start + s, len + 1);
	return (str);
}
