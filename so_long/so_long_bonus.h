/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jslim <jslim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 13:08:31 by jslim             #+#    #+#             */
/*   Updated: 2025/11/05 14:00:48 by jslim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define TILE 64

# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		x;
	int		y;
	int		collectibles;
	int		total_c;
	int		moves;
	void	*img_wall;
	void	*img_floor;
	void	*img_exit;
	void	*img_collect;
	void	*img_player;
	void	*img_defender;
	char	*path;
	void	*img_player_up;
	void	*img_player_down;
	void	*img_player_right;
	void	*img_player_left;
}	t_game;

int		check_for_rect(t_game game);
int		check_for_char_walls(t_game game);
int		check_for_count_helper(t_game game, char character);
int		check_for_count(t_game game);
int		check_for_path(t_game *game);
void	start_position(t_game *game);
void	flood_fill(t_game *game, int y, int x, int *seen_E);
int		count(t_game *game);
char	**parsing(t_game *game);
void	free_tiles(t_game *game);
void	draw_moves(t_game *game);
int		handle_key(int keycode, void *param);
void	sprites(t_game *game, int next_y, int next_x);
void	move(t_game *game, int next_x, int next_y);
void	load_textures(t_game *game);
void	destroy_mlx(t_game *game);
void	draw_map(t_game *game);
int		run_mlx(t_game *game);

#endif
