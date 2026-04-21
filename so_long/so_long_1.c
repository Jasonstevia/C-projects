/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:07:35 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 14:01:13 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_key(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == 119)
		move(game, game->x, game->y - 1);
	else if (keycode == 97)
		move(game, game->x - 1, game->y);
	else if (keycode == 115)
		move(game, game->x, game->y + 1);
	else if (keycode == 100)
		move(game, game->x + 1, game->y);
	else if (keycode == 65307)
	{
		destroy_mlx(game);
		free_tiles(game);
		exit(0);
	}
	mlx_clear_window(game->mlx, game->win);
	draw_map(game);
	return (0);
}

void	move(t_game *game, int next_x, int next_y)
{
	if (next_x < 0 || next_y < 0 || next_y >= game->height
		|| next_x >= game->width || game->map[next_y][next_x] == '1')
		return ;
	else if (game->map[next_y][next_x] == 'C')
		game->collectibles++;
	else if ((game->map[next_y][next_x] == 'E'
		&& game->total_c == game->collectibles))
	{
		game->moves++;
		destroy_mlx(game);
		free_tiles(game);
		exit(0);
	}
	else if (game->map[next_y][next_x] == 'E')
		return ;
	game->map[game->y][game->x] = '0';
	game->map[next_y][next_x] = 'P';
	game->y = next_y;
	game->x = next_x;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

void	load_textures(t_game *game)
{
	int	w;
	int	h;

	w = TILE;
	h = TILE;
	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"textures/player_down.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
}

void	draw_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if (tile == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_wall, x * TILE, y * TILE);
	else if (tile == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_floor, x * TILE, y * TILE);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_exit, x * TILE, y * TILE);
	else if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img_collect, x * TILE, y * TILE);
	else if (tile == 'P')
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
