/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctremino <ctremino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:34:08 by ctremino          #+#    #+#             */
/*   Updated: 2024/05/01 15:37:10 by ctremino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*data_store[FD_MAX];
	char		*line_file;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	data_store[fd] = ft_fd_reader(fd, data_store[fd]);
	if (!data_store[fd])
		return (NULL);
	line_file = ft_line_buffer(data_store[fd]);
	data_store[fd] = ft_update_buffer_aline(data_store[fd]);
	return (line_file);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	pos1;
	size_t	pos2;
	size_t	len1;
	size_t	len2;

	pos1 = -1;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = (char *)malloc(len1 + len2 + 1);
	if (!new_str)
		return (NULL);
	while (++pos1 < len1)
		new_str[pos1] = s1[pos1];
	pos2 = -1;
	while (++pos2 < len2)
		new_str[pos1 + pos2] = s2[pos2];
	new_str[pos1 + pos2] = '\0';
	free(s1);
	return (new_str);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
/*#include <stdio.h>
void	leaks_cheker()
{
	system("leaks -q a.out");
}
int main(void)
{
	int fd1 = open ("textgnl.txt", O_RDONLY);
	int fd2 = open ("text3.txt", O_RDONLY);
	int fd3 = open ("txt2gnl.txt", O_RDONLY);
	
	char *line_file1;
	char *line_file2;
	char *line_file3;

	atexit(leaks_cheker);

	line_file1 = get_next_line (fd1);
	printf(" f1 %s\n", line_file1);
	free(line_file1);
	
	line_file2 = get_next_line (fd2);
	printf(" f2 %s\n", line_file2);
	free(line_file2);
	
	line_file3 = get_next_line (fd3);
	printf("f3 %s\n", line_file3);
	free(line_file3);

	close(fd1);
	close(fd2);
	close(fd3);
	return(0);
}*/