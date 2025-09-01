/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:43:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/01 09:46:03 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*split_and_join(char **arr, char *tmp2)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = ft_strdup("");
	if (!tmp2)
		tmp2 = ft_strjoin(tmp, arr[0]);
	while (arr[i] != NULL)
		tmp2 = ft_strjoin(tmp2, arr[i++]);
	return (tmp2);
}

void	check_order(char *line, t_parse *data)
{
	int	len;

	len = (int)ft_strlen(line);
	if (line[0] == '1' && line[len - 2] == '1'
		&& data->count_identifiers != 6)
		data->flag = 1;
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
