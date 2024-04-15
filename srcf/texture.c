/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:40:31 by ogoman            #+#    #+#             */
/*   Updated: 2024/04/11 10:39:03 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Draws an image on the game window at the specified coordinates.*/
void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 64, y * 64);
}

/*Draws the player character on the game window at the specified coordinates,
and also updates the player's position in the game structure.*/
static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->x_player = x;
	game->y_player = y;
	img_draw(game, image, x, y);
}

/*Draws the exit object on the game window at the specified coordinates.
If all collectible objects have been collected (game->n_collect == 0),
it changes the exit image to a different one.*/
static void	exit_draw(t_game *game, int x, int y)
{
	if (game->n_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "texture/earth.xpm", &game->img_w, &game->img_h);
	}
	img_draw(game, game->img_exit, x, y);
}

/*Draws the entire game map on the window. */
int	map_draw(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALLS)
				img_draw(game, game->img_wall, x, y);
			else if (game->map[y][x] == SPACES)
				img_draw(game, game->img_backg, x, y);
			else if (game->map[y][x] == ROCKET)
				player_draw(game, game->img_player, x, y);
			else if (game->map[y][x] == ALIEN)
				img_draw(game, game->img_collect, x, y);
			else if (game->map[y][x] == MARS)
				exit_draw(game, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
