/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houssam <houssam@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 19:24:52 by houssam           #+#    #+#             */
/*   Updated: 2025/08/16 19:28:34 by houssam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_h

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include <unistd.h>

typedef struct s_parse
{
	char	*path_s;
	char	*path_n;
	char	*path_e;
	char	*path_w;
	int		fd;
}t_parse;

int	check_file(char *str, t_parse *data);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
char	*get_next_line(int fd);

#endif
