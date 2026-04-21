/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:09:17 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 14:03:42 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_for_rect(t_game game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game.height)
	{
		x = 0;
		while (game.map[y][x])
			x++;
		if (x != game.width)
			return (1);
		y++;
	}
	return (0);
}

int	check_for_char_walls(t_game game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game.height)
	{
		x = 0;
		while (x < game.width)
		{
			if (game.map[y][x] != '1' && game.map[y][x] != '0'
				&& game.map[y][x] != 'E' && game.map[y][x] != 'P'
				&& game.map[y][x] != 'C' && game.map[y][x] != 'D')
				return (1);
			if ((game.map[0][x] != '1') || (game.map[game.height - 1][x] != '1')
				|| (game.map[y][game.width - 1] != '1')
				|| (game.map[y][0]) != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_for_count_helper(t_game game, char character)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (y < game.height)
	{
		x = 0;
		while (x < game.width)
		{
			if (game.map[y][x] == character)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	check_for_count(t_game game)
{
	int	count_p;
	int	count_e;
	int	count_c;

	count_c = check_for_count_helper(game, 'C');
	count_p = check_for_count_helper(game, 'P');
	count_e = check_for_count_helper(game, 'E');
	if ((count_p != 1) || (count_e != 1) || (count_c == 0))
		return (1);
	return (0);
}
