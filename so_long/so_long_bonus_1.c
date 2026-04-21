/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:07:49 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 14:00:55 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_moves(t_game *game)
{
	char	*str;
	char	*moves_str;
	char	*prefix;

	prefix = ft_strdup("Moves: ");
	moves_str = ft_itoa(game->moves);
	str = ft_strjoin(prefix, moves_str);
	mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, str);
	free(moves_str);
	free(str);
}

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
	draw_moves(game);
	return (0);
}

void	sprites(t_game *game, int next_y, int next_x)
{
	if (next_x < game->x)
		game->img_player = game->img_player_left;
	else if (next_x > game->x)
		game->img_player = game->img_player_right;
	else if (next_y < game->y)
		game->img_player = game->img_player_up;
	else if (next_y > game->y)
		game->img_player = game->img_player_down;
}

void	move(t_game *game, int next_x, int next_y)
{
	if (next_x < 0 || next_y < 0 || next_y >= game->height
		|| next_x >= game->width || game->map[next_y][next_x] == '1')
		return ;
	else if (game->map[next_y][next_x] == 'C')
		game->collectibles++;
	else if ((game->map[next_y][next_x] == 'E'
		&& game->total_c == game->collectibles)
		|| game->map[next_y][next_x] == 'D')
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
	sprites(game, next_y, next_x);
	game->y = next_y;
	game->x = next_x;
	game->moves++;
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
	game->img_defender = mlx_xpm_file_to_image(game->mlx,
			"textures/defender.xpm", &w, &h);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	game->img_player_up = mlx_xpm_file_to_image(game->mlx,
			"textures/player_up.xpm", &w, &h);
	game->img_player_down = mlx_xpm_file_to_image(game->mlx,
			"textures/player_down.xpm", &w, &h);
	game->img_player_left = mlx_xpm_file_to_image(game->mlx,
			"textures/player_left.xpm", &w, &h);
	game->img_player_right = mlx_xpm_file_to_image(game->mlx,
			"textures/player_right.xpm", &w, &h);
	game->img_player = game->img_player_down;
}
