/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:26:44 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/02 14:54:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str)
	{
		while (str[i] != '\0')
		{
			while (str[i] != c && str[i] != '\0')
				i++;
			if (str[i] == c || str[i] == '\0')
			{
				count++;
				if (str[i] != '\0')
					i++;
			}
		}
	}
	return (count);
}

static int	l_words(char const *str, int i, char c)
{
	int	l;

	l = 0;
	if (str)
	{
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			l++;
		}
	}
	return (l);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_words(s, c) + 1));

	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			k = 0;
			tab[j] = malloc(sizeof(char) * (l_words(s, i, c) + 1));
			if (!tab[j])
				return (ft_free(tab));
			while (s[i] != c && s[i] != '\0')
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
//int main()
//{
//    const char *str = "Hello world this is a test";
//    char delimiter = ',';    
//    char **result = ft_split(str, delimiter);
//    for (int i = 0; result[i]; i++) {
//        printf("%s", result[i]);
//		free(result[i]);
//    }

//    free(result);
//    return 0;
//}
