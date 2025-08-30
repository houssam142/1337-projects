/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:24:52 by houssam           #+#    #+#             */
/*   Updated: 2025/08/30 19:13:44 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define TEX_WIDTH 64
# define TEX_HEIGHT 64

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
	PLAYER,
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

typedef struct s_img
{
	void	*tex_img_n;
	char	*tex_addr_n;
	int		tex_width_n;
	int		tex_height_n;
	int		tex_bpp_n;
	int		tex_line_size_n;
	int		tex_endian_n;

	void	*tex_img_s;
	char	*tex_addr_s;
	int		tex_width_s;
	int		tex_height_s;
	int		tex_bpp_s;
	int		tex_line_size_s;
	int		tex_endian_s;

	void	*tex_img_e;
	char	*tex_addr_e;
	int		tex_width_e;
	int		tex_height_e;
	int		tex_bpp_e;
	int		tex_line_size_e;
	int		tex_endian_e;

	void	*tex_img_w;
	char	*tex_addr_w;
	int		tex_width_w;
	int		tex_height_w;
	int		tex_bpp_w;
	int		tex_line_size_w;
	int		tex_endian_w;
}			t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	char	*tex_addr;
	double	x_player;
	double	y_player;
	int		dir_x;
	double	delta_dist_x;
	double	delta_dist_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	perp_dist;
	int		dir_y;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	double	side_dist_x;
	double	side_dist_y;
	double	wall_x;
	int		tex_x;
	int		step_x;
	int		step_y;
	int		endian;
	int		bpp;
	char	*tex;
	int		line_size;
	int		map_width;
	int		map_height;
	int		ceiling_color;
	int		floor_color;
	t_parse	*parse;
	t_img	*imgs;
}			t_data;

int			check_file(char *str);
void		parse_free(char **arr, char *tmp, char *tmp2, char *line);
void		get_map_dimension(t_data *data);
void		ft_draw(t_data *data, int x, int side);
void		perform_dda(t_data *data, int *pos_x, int *pos_y, int *side);
void		init_play_pos_and_oreat(t_data *data);
void		calculate_perp_and_drawing(t_data *data, int pos_x,
				int pos_y, int side);
char		*split_and_join(char **arr, char *tmp, char *tmp2);
void		calculate_side_dist(t_data *data, int pos_x, int pos_y);
int			key_press(int key, t_data *data);
int			rgb_string_to_int(t_data *data, char c);
void		player_dir_setup(t_data *data);
void		ft_mlx_put_pixel(t_data *data, int x, int y, int color);
void		struct_free(t_parse *data);
void		start_game(t_data *data, t_parse *parse);
char		**only_2d_map(char **map);
int			line_all_ones(char *line, char one);
void		check_map(char **map, t_parse *data);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *str);
void		get_player_pos(t_data *data);
int			check_extensions(char *str, t_parse *data);
void		ft_putstr_fd(char *s, int fd);
char		*get_next_line(int fd);
void		check_texture_syntax(t_parse *data);
void		compute_camera_x(t_data *data);
char		**ft_free(char **tab);
void		ft_alloc_str(t_parse *data, int k, char c);
char		**ft_split(char const *s, char c);
void		print_error(enum e_parsing type, t_parse *data);
void		check_colors(t_parse *data);
int			ft_isspace(char c);
int			ft_isdigit(int c);
void		check_order(char *line, t_parse *data);
char		*ft_strtrim(char const *s1, char const *set);
int			ft_atoi(const char *str);
char		**ft_return_map_game(char *str, t_parse *data);

#endif
