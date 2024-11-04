/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:26:44 by hounejja          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/10/29 18:36:40 by hounejja         ###   ########.fr       */
=======
/*   Updated: 2024/11/02 14:54:34 by hounejja         ###   ########.fr       */
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static char	**if_error(char **tab)
=======
static char	**ft_free(char **tab)
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

<<<<<<< HEAD
static int	count_words(const char *str, char c)
=======
static int	count_words(char const *str, char c)
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
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

<<<<<<< HEAD
static int	ft_word(const char *s1, int index, char c)
{
	int	i;

	i = 0;
	if (s1)
	{
		while (s1[index] != c && s1[index] != '\0')
		{
			index++;
			i++;
		}
	}
	return (i);
=======
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
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
}

char	**ft_split(char const *s, char c)
{
<<<<<<< HEAD
	char	**arr;
	int		index;
	int		i;
	int		p;
=======
	int		i;
	int		j;
	int		k;
	char	**tab;
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de

	i = 0;
<<<<<<< HEAD
	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	while (s[i] != '\0')
	{
		if (s[i] != '\0')
		{
			p = 0;
			arr[index] = malloc(sizeof(char) * (ft_word(s, i, c)));
			if (!arr[index])
				return (if_error(arr));
			while (s[i] != c && s[i] != '\0')
				arr[index][p++] = s[i++];
			arr[index++][p] = '\0';
		}
		i++;
	}
	arr[index] = '\0';
	return (arr);
}
/*
int main()
{
        const char str[] = "";
        char set = ',';
        int i = 0;
        char **res = ft_split(str, set);
        while (res[i])
        {
                printf("%s", res[i]);
                free(res[i]);
                i++;
        }
        free(res);
        return 0;
}*/
=======
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
>>>>>>> b24c59b3ce0ed13393269951ba5fd487e0be51de
