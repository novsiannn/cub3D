/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsas <dsas@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:47:35 by dsas              #+#    #+#             */
/*   Updated: 2023/01/26 16:42:17 by dsas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*merge(char *buffer, char *tmp_buffer)
{
	char	*new_buff;

	new_buff = ft_strjoin(buffer, tmp_buffer);
	if (buffer != NULL)
		free(buffer);
	return (new_buff);
}

char	*read_till_nl(int fd, char *buffer)
{
	char	*tmp_buffer;
	int		symb_read;

	symb_read = 1;
	tmp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp_buffer)
		return (NULL);
	symb_read = 1;
	while (symb_read > 0)
	{
		symb_read = read(fd, tmp_buffer, BUFFER_SIZE);
		if (symb_read == -1)
		{
			free(tmp_buffer);
			free(buffer);
			return (NULL);
		}
		tmp_buffer[symb_read] = 0;
		buffer = merge(buffer, tmp_buffer);
		if (ft_strchr_line(buffer, '\n') != -1)
			break ;
	}
	free(tmp_buffer);
	return (buffer);
}

char	*trim_before_nl(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	if (i == 0 && ! buffer[i])
		return (NULL);
	if (buffer[i])
		i++;
	line = (char *)malloc(i + 1);
	ft_memmove(line, buffer, i);
	line[i] = 0;
	return (line);
}

char	*update_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*new_buff;

	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			break ;
	}
	if (! buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	j = ft_strlen(buffer + i + 1);
	new_buff = (char *)malloc(j + 1);
	ft_memmove(new_buff, buffer + i + 1, j);
	new_buff[j] = 0;
	free(buffer);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer[2048];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd] != NULL)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	buffer[fd] = read_till_nl(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = trim_before_nl(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
//     char * line;

//     int fd = open("giant_line_nl.txt", O_RDONLY);
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
// }
