/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:24:52 by houssam           #+#    #+#             */
/*   Updated: 2025/08/20 22:20:54 by houssam          ###   ########.fr       */
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

enum		e_parsing
{
	COLOR,
	TEXTURE,
	IDENTIFIERS,
	MAP,
	FILE1,
	EMPTY,
	EXTENSION,
	ORDER,
};

typedef struct s_parse
{
	char	*path_s;
	char	*path_n;
	char	*path_e;
	char	*path_w;
	char	*floor_color;
	char	*celing_color;
	int		count_identifiers;
	int		flag;
	char	**map;
}			t_parse;

int			check_file(char *str);
void		struct_free(t_parse *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
int			check_extensions(char *str, t_parse *data);
void		ft_putstr_fd(char *s, int fd);
char		*get_next_line(int fd);
void		check_texture_syntax(t_parse *data);
char		**ft_free(char **tab);
void		ft_alloc_str(t_parse *data, int k, char c);
void		check_map(t_parse *data);
char		**ft_split(char const *s, char c);
void		print_error(enum e_parsing type, t_parse *data);
void		check_colors(t_parse *data);
int			ft_isspace(char c);
int			ft_isdigit(int c);
void		check_order(char *line, t_parse *data);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_atoi(const char *str);
char		**ft_return_map_game(char *str);

#endif
