/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:26:02 by hounejja          #+#    #+#             */
/*   Updated: 2024/11/27 21:00:26 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 1024
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# if defined(BUFFER_SIZE) && (BUFFER_SIZE > INT_MAX - 1)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 2147483646
# endif

char	*get_next_line(int fd);
char	*ft_strdup_bonus(const char *str);
char	*ft_strjoin_bonus(char const *s1, char const *s2);
size_t	ft_strlen_bonus(const char *str);
char	*ft_substr_bonus(char const *s, unsigned int start, size_t len);

#endif
