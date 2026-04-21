/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:07:07 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 13:12:06 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count(t_game *game)
{
	int		fd;
	char	*line;

	game -> height = 0;
	fd = open(game->path, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		game -> height++;
	}
	close(fd);
	return (game -> height);
}

char	**parsing(t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	game->height = count(game);
	game->map = malloc(sizeof(char *) * game->height);
	fd = open(game->path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		game->map[i] = ft_strtrim(line, "\n");
		free(line);
		i++;
	}
	game->width = ft_strlen(game->map[0]);
	close(fd);
	return (game->map);
}

void	free_tiles(t_game *game)
{
	int	i;

	i = 0;
	while (i < game-> height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}
