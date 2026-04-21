/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:30:54 by jslim             #+#    #+#             */
/*   Updated: 2025/09/16 10:34:09 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*accumulate(char *accumulated, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc (BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(accumulated, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		accumulated = ft_strjoin(accumulated, buffer);
	}
	free (buffer);
	return (accumulated);
}

char	*get_next_line(int fd)
{
	static char	*accumulated = NULL;
	char		*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	accumulated = accumulate(accumulated, fd);
	if (!accumulated)
		return (NULL);
	line = copy_line(accumulated);
	if (!line)
		return (free(accumulated), accumulated = NULL, NULL);
	temp = accumulated;
	accumulated = ft_strjoin(NULL, ft_strchr(accumulated, '\n'));
	if (accumulated && accumulated[0] == '\0')
	{
		free(accumulated);
		accumulated = NULL;
	}
	return (free(temp), line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	char *line;
// 	int fd;

// 	fd = open("text3.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return (0);
// }
