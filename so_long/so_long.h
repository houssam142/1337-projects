/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:53:01 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/23 23:02:19 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

# define W 119
# define S 115
# define D 100
# define A 97

typedef struct s_win
{
	int		x_player;
	int		sum_of_collec;
	char	**map;
	int		y_player;
	int		e;
	int		collected;
	int		x_ext;
	int		y_ext;
	int		p;
	int		height;
	int		moves;
	int		c;
	int		width;
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*win;
	void	*img;
	void	*door;
	void	*player;
	void	*floor;
	void	*wall;
	void	*collec;
}			t_win;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		error_check(t_win *w);
void		free_all(t_win *w);
int			ft_putchar(char c);
int			ft_printf(const char *w, ...);
long		print_int(long int n);
void		get_position(t_win *game, int *x, int *y, char asset);
int			plays(int key, t_win *game, void *img);
int			line_all_ones(char *line, char one);
void		ft_close(t_win *win);
void		flood_fill(char **map, int x, int y, t_win *w);
int			first_and_last(char *str);
int			tab_length(char **arr);
char		*get_map_characters(char *map);
int			check_map_characters(char *characters, t_win *w);
int			check_wall(char **map);
void		raise_error(void);
int			check_map_walls(char **map);
void		size_of_win(t_win *game);
void		ft_join_and_free(char **str, void *buf);
int			check_length_walls(char **map);
int			count_collectibles(t_win *game);
int			check_file(char *file);
void		draw_map(t_win *game, void *img, char c);
char		**ft_split(char const *s, char c);
void		new_window(t_win *w);
char		**ft_free(char **tab);
void		init_param(t_win *w);
char		**check_map(char *map, t_win *w);
void		render_images(t_win *game);
void		render(t_win *w);
void		draw_img(t_win *game, int i, int j, void *img);
int			collecting(t_win *game);
void		close_win_1(t_win *win);
void		error_mov(t_win *w);

#endif
