/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:43:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/12/01 21:12:31 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	fill_lines_w_spaces(char **map, int max_len)
{
	char	*new_line;
	int		i;
	int		len;
	int		j;

	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		new_line = ft_malloc(sizeof(char) * (max_len + 1));
		j = 0;
		while (j < max_len)
		{
			if (j < len)
				new_line[j] = map[i][j];
			else
				new_line[j] = '1';
			j++;
		}
		new_line[max_len] = '\0';
		map[i] = new_line;
		i++;
	}
}

int	find_longest_line(char **map)
{
	int		max_len;
	int		i;
	int		len;
	char	*line;

	max_len = 0;
	i = 0;
	len = 0;
	while (map[i])
	{
		line = ft_strtrim(map[i], "\n");
		len = ft_strlen(line);
		if (max_len < len)
			max_len = len;
		i++;
	}
	return (max_len);
}

char	*split_and_join(char **arr, char *tmp2)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_strdup("");
	if (!tmp2)
		tmp2 = ft_strjoin(tmp, arr[0]);
	if (!tmp2)
		return (NULL);
	while (arr[i] != NULL)
		tmp2 = ft_strjoin(tmp2, arr[i++]);
	return (tmp2);
}

void	check_texture_syntax(t_parse *data)
{
	int (len_1), (len_2), (len_3), (len_4);
	if (data->path_e)
	{
		len_1 = (int)ft_strlen(data->path_e);
		if (ft_strncmp(&data->path_e[len_1 - 4], ".xpm", 3))
			print_error(TEXTURE);
	}
	if (data->path_w)
	{
		len_2 = (int)ft_strlen(data->path_w);
		if (ft_strncmp(&data->path_w[len_2 - 4], ".xpm", 3))
			print_error(TEXTURE);
	}
	if (data->path_s)
	{
		len_3 = (int)ft_strlen(data->path_s);
		if (ft_strncmp(&data->path_s[len_3 - 4], ".xpm", 3))
			print_error(TEXTURE);
	}
	if (data->path_n)
	{
		len_4 = (int)ft_strlen(data->path_n);
		if (ft_strncmp(&data->path_n[len_4 - 4], ".xpm", 3))
			print_error(TEXTURE);
	}
}
