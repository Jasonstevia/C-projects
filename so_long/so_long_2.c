/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:08:00 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 14:01:06 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_mlx(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collect)
		mlx_destroy_image(game->mlx, game->img_collect);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}

int	close_window(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	destroy_mlx(game);
	free_tiles(game);
	exit(0);
	return (0);
}

int	run_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, game->width * TILE,
			game->height * TILE, "so_long");
	load_textures(game);
	draw_map(game);
	mlx_key_hook(game->win, handle_key, (void *)game);
	mlx_hook(game->win, 17, 0, close_window, (void *)game);
	mlx_loop(game->mlx);
	return (0);
}

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
