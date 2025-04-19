/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 17:02:00 by hounejja          #+#    #+#             */
/*   Updated: 2025/03/23 00:03:17 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "/usr/include/minilibx-linux/mlx.h"
# include <stdlib.h>
# include "get_next_line.h"
# include <fcntl.h>
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
	void	*bkg;
	int		collected;
	int		x_ext;
	int		y_ext;
	char	*str;
	int		p;
	int		height;
	int		enemy_x;
	int		enemy_y;
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
	void	*sprite[3];
	void	*floor;
	void	*wall;
	void	*collec;
	void	*enemy;
	int		frame_count;
	int		curr_frame;
}			t_game;

int			ft_strncmp_bonus(const char *s1, const char *s2, size_t n);
void		error_check_bonus(t_game *w);
int			update_anim(t_game *w);
void		destroy_anim(t_game *w);
int			ft_putchar(char c);
void		get_position(t_game *game, int *x, int *y, char asset);
int			plays(int key, t_game *game, void *img);
int			line_all_ones_b(char *line, char one);
void		close_win_1_bonus(t_game *win);
void		ft_close(t_game *win);
long		print_int(long int n);
int			ft_printf1(const char *w, ...);
int			first_and_last_b(char *str);
void		declare_sprites(t_game *w);
int			tab_length_b(char **arr);
void		error_mov_bonus(t_game *w);
char		*get_map_characters_b(char *map);
int			check_map_characters(char *characters, t_game *w);
int			check_wall_b(char **map);
void		raise_error_bonus(void);
int			check_map_walls(char **map);
void		size_of_win(t_game *game);
void		ft_join_and_free_b(char **str, void *buf);
int			check_length_walls_b(char **map);
int			count_collectibles(t_game *game);
int			check_file_b(char *file);
void		draw_map(t_game *game, void *img, char c);
void		flood_fill_bonus(char **map, int x, int y, t_game *w);
char		**ft_split_bonus(char const *s, char c);
void		new_window_bonus(t_game *w);
char		**ft_free(char **tab);
void		init_param(t_game *w);
char		**check_map(char *map, t_game *w);
void		render_images(t_game *game);
void		render_bonus(t_game *w);
void		draw_img(t_game *game, int i, int j, void *img);
int			collecting(t_game *game);
char		*ft_itoa(int n);
void		put(t_game *w);
void		free_all(t_game *w);

#endif
