/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:45:44 by aoussama          #+#    #+#             */
/*   Updated: 2025/07/11 20:58:52 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*reslt;
	size_t	j;

	if (!s1)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	reslt = (char *)malloc((j + 1) * sizeof(char));
	if (reslt == NULL)
		return (NULL);
	ft_strlcpy(reslt, s1, ft_strlen(s1) + 1);
	ft_strlcat(reslt, s2, j + 1);
	return (reslt);
}
