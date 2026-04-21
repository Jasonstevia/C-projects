/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:08:11 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 13:59:17 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * TILE, y * TILE);
	else if (game->map[y][x] == 'D')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_defender, x * TILE, y * TILE);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, x * TILE, y * TILE);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x * TILE, y * TILE);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collect, x * TILE, y * TILE);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_player, x * TILE, y * TILE);
}

void	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_tile(game, x, y);
			x++;
		}
		y++;
	}
}

void	destroy_mlx(t_game *game)
{
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_player_down)
		mlx_destroy_image(game->mlx, game->img_player_down);
	if (game->img_player_up)
		mlx_destroy_image(game->mlx, game->img_player_up);
	if (game->img_player_left)
		mlx_destroy_image(game->mlx, game->img_player_left);
	if (game->img_player_right)
		mlx_destroy_image(game->mlx, game->img_player_right);
	if (game->img_defender)
		mlx_destroy_image(game->mlx, game->img_defender);
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
			game->height * TILE, "so_long_bonus");
	load_textures(game);
	draw_map(game);
	draw_moves(game);
	mlx_key_hook(game->win, handle_key, (void *)game);
	mlx_hook(game->win, 17, 0, close_window, (void *)game);
	mlx_loop(game->mlx);
	return (0);
}
