/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctremino <ctremino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:43:01 by ctremino          #+#    #+#             */
/*   Updated: 2024/07/17 13:22:23 by ctremino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*data_store;
	char		*line_file;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return ((NULL));
	data_store = ft_fd_reader(fd, data_store);
	if (!data_store)
		return (NULL);
	line_file = ft_line_buffer(data_store);
	data_store = ft_update_buffer_aline(data_store);
	return (line_file);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	return (len);
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
/*#include <stdio.h>

 int	main(void)
 {
 	int	fd = open("text_1.txt", O_RDONLY); // = 0;
 	char *line;

	if (fd == -1)
 	{
 	printf("Error opening file\n");
 	return (1);
  }
 	line = get_next_line(fd);
 	printf("%s\n",line);
 	free(line);
 	//int i = 0;
 	while (line) //i++ < 50
 	{
		line = get_next_line(fd);
		printf("%s",line);
 		free(line); 
 	}
 	close(fd);

 	return(0);
 }*/