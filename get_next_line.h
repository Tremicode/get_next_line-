/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctremino <ctremino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:42:06 by ctremino          #+#    #+#             */
/*   Updated: 2024/04/28 01:58:31 by ctremino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <stddef.h> // Para size_t
# include <stdlib.h> //malloc
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_fd_reader(int fd, char *save);
char	*ft_update_buffer_aline(char *str);
char	*ft_line_buffer(char *buff);

char	*ft_strjoin(char *s1, char *s2); // basic functions
size_t	ft_strlen(const char *s);
int		ft_check_endtext(char *str);

#endif