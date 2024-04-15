/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:41:06 by ogoman            #+#    #+#             */
/*   Updated: 2024/04/11 09:10:37 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Creates images used in the game.*/
static void	img_init(t_game *game)
{
	game->img_backg = mlx_xpm_file_to_image
		(game->mlx, "texture/spaces_s.xpm", &game->img_w, &game->img_h);
	game->img_wall = mlx_xpm_file_to_image
		(game->mlx, "texture/walls.xpm", &game->img_w, &game->img_h);
	game->img_player = mlx_xpm_file_to_image
		(game->mlx, "texture/rocket_r.xpm", &game->img_w, &game->img_h);
	game->img_collect = mlx_xpm_file_to_image
		(game->mlx, "texture/alien.xpm", &game->img_w, &game->img_h);
	game->img_exit = mlx_xpm_file_to_image
		(game->mlx, "texture/mars.xpm", &game->img_w, &game->img_h);
}

/*Initializes the size of the game window (map_w and map_h)
based on the size of the game map.*/
static void	size_window_init(t_game *game)
{
	int	i;

	game->map_w = ft_strlen(game->map[0]) * 64;
	i = 0;
	while (game->map[i] != NULL)
		i++;
	game->map_h = i * 64;
}

/*
Function initializes the game as a whole. It does the following:

*Initializes the MLX subsystem using the mlx_init function.
 *Defines the window size using size_window_init.
  *Creates a new window using mlx_new_window.
   *Initializes the moves counter and the endgame flag.
    *Initializes images using img_init.
     *Draws a map using the map_draw function.
*/
void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	size_window_init(game);
	game->win = mlx_new_window(game->mlx, game->map_w, game->map_h, "So_Long");
	game->moves = 0;
	game->endgame = 0;
	img_init(game);
	map_draw(game);
}
