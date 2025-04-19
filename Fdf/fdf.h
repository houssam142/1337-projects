/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 09:39:32 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/23 10:23:25 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIN_W 800
# define WIN_H 800
# define COLOR_WHITE 0xFFFFFF
# define M_PI 3.14159265358979323846

typedef struct s_pt
{
	int				x;
	int				y;
	int				z;
}					t_pt;

typedef struct s_win
{
	char			*map_name;
	char			**map;
	int				rows;
	int				map_width;
	int				columns;
	int				map_height;
	int				total_points;
	int				width;
	int				height;
	double			scaling;
	int				center_x;
	int				center_y;
	void			*mlx;
	void			*window;
	void			*img_ptr;
	int				bits;
	int				min_height;
	int				max_height;
	int				lsize;
	int				endian;
	int				*data;
}					t_win;

typedef struct s_struct
{
	t_win			*infa;
	int				x_map;
	int				y_map;
	double			z_map;
	int				x_pixel;
	int				y_pixel;
	unsigned long	color;
	t_pt			pt;
	struct s_struct	*go_right;
	struct s_struct	*go_down;
	struct s_struct	*next;
	struct s_struct	*tail;
}					t_struct;

void				check_and_count(t_struct *head, t_win *info_map);
int					get_color(int z);
int					color_zed(char *input, t_struct *new_node);
void				create_list(t_struct **head, int x, int y, char *str);
void				set_height_range(t_win *map, t_pt *cur);
int					check_commas(char *str, t_struct *head);
int					increment_and_free(int count, char *str, char **map);
void				draw_point(t_win *info, int x, int y, int color);
void				draw_lines(t_win *info, t_struct **head);
void				info_to_list(t_win *data, t_struct **head);
void				free_list(t_struct **list);
void				space_and_scale(t_win *inf);
char				*check_the_fd(char *file_name);
void				bresenham(t_win *info, t_struct *start, t_struct *end);
void				int_to_isometric_pixel(t_win *info, t_struct **head);
int					point_connect(t_struct **head);
void				new_windows(t_win *win, t_struct **head);
int					check_the_map(char *file_name, t_struct **head);
char				*ft_strchr(const char *str, int search_str);
char				**ft_free(char **tab);
int					ft_isspace(char c);
char				**ft_split(const char *s);
int					interpret_colors(int z, t_struct *head);
int					ft_atoi(const char *str);
void				add_back(t_struct **lst, t_struct *new);
char				*ft_strchr(const char *str, int search_str);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
