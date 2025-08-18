/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:24:52 by houssam           #+#    #+#             */
/*   Updated: 2025/08/18 05:24:45 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_parse
{
	char	*path_s;
	char	*path_n;
	char	*path_e;
	char	*path_w;
	char	*floor_color;
	char	*celing_color;
	int		count_identifiers;
	char	**map;
}			t_parse;

int			check_file(char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
int			check_extensions(char *str, t_parse *data);
void		ft_putstr_fd(char *s, int fd);
char		*get_next_line(int fd);
char		**ft_free(char **tab);
void		ft_alloc_str(t_parse *data, int k, char c);
char		**ft_split(char const *s, char c);
int			ft_isspace(char c);
int			ft_atoi(const char *str);
char		**arr_to_2darray(char *map);
char    	**ft_return_map_game(char *str);

#endif
