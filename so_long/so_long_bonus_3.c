/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:58:55 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 14:01:01 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	game.path = argv[1];
	game.map = parsing(&game);
	start_position(&game);
	game.total_c = check_for_count_helper(game, 'C');
	if (check_for_rect(game) || check_for_char_walls(game)
		|| check_for_count(game) || check_for_path(&game)
		|| (argc != 2))
		return (free_tiles(&game), -1);
	run_mlx(&game);
	free_tiles(&game);
	return (0);
}
