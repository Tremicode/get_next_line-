/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctremino <ctremino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:41:45 by ctremino          #+#    #+#             */
/*   Updated: 2024/05/08 18:34:52 by ctremino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* save used for the whole text,
buff small part of the text until buffer size */
char	*ft_fd_reader(int fd, char *save)
{
	int		b_reader;
	char	*buff;

	b_reader = 1;
	buff = (char *)malloc(sizeof(char) * (1 + BUFFER_SIZE));
	if (!buff)
		return (NULL);
	while (!(ft_check_endtext(save)) && b_reader != 0)
	{
		b_reader = read(fd, buff, BUFFER_SIZE);
		if (b_reader == -1)
		{
			free(buff);
			if (save)
				free(save);
			return (NULL);
		}
		buff[b_reader] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

/* read char by char until \n or fullstop*/
int	ft_check_endtext(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/* read line char by char until\n and allocated in buffer,
 keep reading until endtext */
char	*ft_line_buffer(char *buff)
{
	size_t	i;
	char	*new_line;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	new_line = malloc(sizeof(char) * i + 2);
	if (!new_line)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		new_line[i] = buff[i];
		i++;
	}
	if (buff[i] && buff[i] == '\n')
		new_line[i++] = '\n';
	new_line[i] = '\0';
	return (new_line);
}

/* start to read from the \n or end text 
store the rest of the text*/
char	*ft_update_buffer_aline(char *str)
{
	int		i;
	int		j;
	char	*rest_of_str;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	rest_of_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest_of_str)
		return (NULL);
	i++;
	while (str[i])
		rest_of_str[j++] = str[i++];
	rest_of_str[j] = '\0';
	free(str);
	return (rest_of_str);
}
