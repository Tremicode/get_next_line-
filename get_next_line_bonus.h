/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctremino <ctremino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:38:01 by ctremino          #+#    #+#             */
/*   Updated: 2024/04/28 02:39:29 by ctremino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2); // basic functions
size_t	ft_strlen(const char *s);

char	*ft_fd_reader(int fd, char *save);
char	*ft_update_buffer_aline(char *str);
char	*ft_line_buffer(char *buff);
int		ft_check_endtext(char *str);

#endif