/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 20:26:44 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/14 11:57:13 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_free(char **tab)
{
	unsigned int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static int	word_count(const char *s)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*extract_word(const char **s)
{
	const char	*start;
	char		*word;

	int (len), i;
	len = 0;
	i = 0;
	while (**s && ft_isspace(**s))
		(*s)++;
	start = *s;
	while (**s && !ft_isspace(**s))
	{
		len++;
		(*s)++;
	}
	word = (char *)malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(const char *s)
{
	char	**result;

	int (words), i;
	if (!s)
		return (NULL);
	words = word_count(s);
	i = 0;
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	while (i < words)
	{
		result[i] = extract_word(&s);
		if (!result[i])
		{
			ft_free(result);
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}
