/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:10:02 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 14:06:23 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->y = y;
				game->x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	flood_fill(t_game *game, int y, int x, int *count_E)
{
	if (y < 0 || x < 0 || y >= game->height || x >= game->width)
		return ;
	if (game->map[y][x] == 'V' || game->map[y][x] == '1')
		return ;
	if (game->map[y][x] == 'C')
		game->collectibles++;
	if (game->map[y][x] == 'E')
	{
		*count_E = 1;
		return ;
	}
	game->map[y][x] = 'V';
	flood_fill(game, y, x + 1, count_E);
	flood_fill(game, y, x - 1, count_E);
	flood_fill(game, y + 1, x, count_E);
	flood_fill(game, y - 1, x, count_E);
}

int	check_for_path(t_game *game)
{
	t_game	copy;
	int		i;
	int		count_c;
	int		count_e;

	count_e = 0;
	copy = *game;
	copy.collectibles = 0;
	copy.map = malloc(sizeof(char *) * (game->height + 1));
	i = 0;
	while (i < game->height)
	{
		copy.map[i] = ft_strdup(game->map[i]);
		i++;
	}
	copy.map[game->height] = NULL;
	start_position(&copy);
	count_c = check_for_count_helper(*game, 'C');
	flood_fill(&copy, copy.y, copy.x, &count_e);
	if (copy.collectibles == count_c && count_e == 1)
		return (free_tiles(&copy), 0);
	return (free_tiles(&copy), 1);
}
