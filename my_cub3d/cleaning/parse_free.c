/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 18:34:05 by hounejja          #+#    #+#             */
/*   Updated: 2025/08/30 18:35:59 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	parse_free(char **arr, char *tmp, char *tmp2, char *line)
{
	ft_free(arr);
	free(line);
	free(tmp);
	free(tmp2);
}
