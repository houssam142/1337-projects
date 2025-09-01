/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:31:19 by hounejja          #+#    #+#             */
/*   Updated: 2025/09/01 19:26:17 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "cub3d.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

char	*get_next_line(int fd);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *str, int search_str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, int start, int len);
int		ft_strlcpy(char *dst, const char *src, int size);

#endif
