/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:41:31 by ogoman            #+#    #+#             */
/*   Updated: 2024/04/12 12:40:19 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This function updates the player's image based on the provided key character (key).
If the key is 'w', 's', 'd', or 'a', the function loads the corresponding rocket image
in the game. After that, the current player's image is destroyed, and then a new
rocket image is created using the mlx_xpm_file_to_image function.*/
static void	rocket_update_image(char key, t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_player);
	if (key == 'w')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "texture/rocket_up.xpm", &game->img_w, &game->img_h);
	else if (key == 's')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "texture/rocket_d.xpm", &game->img_w, &game->img_h);
	else if (key == 'd')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "texture/rocket_r.xpm", &game->img_w, &game->img_h);
	else if (key == 'a')
		game->img_player = mlx_xpm_file_to_image
			(game->mlx, "texture/rocket_l.xpm", &game->img_w, &game->img_h);
}

/*This function handles the player's movement upwards.
If the player is on a cell with the finish and has collected all items, the game ends.
If the player encounters a wall (WALLS) or the finish (MARS),
their position remains unchanged.
Otherwise, the player moves, and the map is updated and redrawn on the screen.*/
void	rocket_w(t_game *game)
{
	rocket_update_image('w', game);
	if (game->map[game->y_player][game->x_player] == MARS
		&& game->n_collect == 0)
	{
		game->moves++;
		game->endgame = 1;
		mlx_clear_window(game->mlx, game->win);
	}
	else if (game->map[game->y_player][game->x_player] == WALLS
			|| game->map[game->y_player][game->x_player] == MARS)
		game->y_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == ALIEN)
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = ROCKET;
		game->map[game->y_player + 1][game->x_player] = SPACES;
		game->moves++;
		map_draw(game);
	}
}

/*This function handles the player's movement downwards
If the player is on a cell with the finish and has collected all items, the game ends.
If the player encounters a wall (WALLS) or the finish (MARS),
their position remains unchanged.
Otherwise, the player moves, and the map is updated and redrawn on the screen.*/
void	rocket_s(t_game *game)
{
	rocket_update_image('s', game);
	if (game->map[game->y_player][game->x_player] == MARS
			&& game->n_collect == 0)
	{
		game->moves++;
		game->endgame = 1;
		mlx_clear_window(game->mlx, game->win);
	}
	else if (game->map[game->y_player][game->x_player] == WALLS
			|| game->map[game->y_player][game->x_player] == MARS)
		game->y_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == ALIEN)
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = ROCKET;
		game->map[game->y_player - 1][game->x_player] = SPACES;
		game->moves++;
		map_draw(game);
	}
}

/*This function handles the player's movement to the right
If the player is on a cell with the finish and has collected all items, the game ends.
If the player encounters a wall (WALLS) or the finish (MARS),
their position remains unchanged.
Otherwise, the player moves, and the map is updated and redrawn on the screen.*/
void	rocket_d(t_game *game)
{
	rocket_update_image('d', game);
	if (game->map[game->y_player][game->x_player] == MARS
			&& game->n_collect == 0)
	{
		game->moves++;
		game->endgame = 1;
		mlx_clear_window(game->mlx, game->win);
	}
	else if (game->map[game->y_player][game->x_player] == WALLS
			|| game->map[game->y_player][game->x_player] == MARS)
		game->x_player -= 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == ALIEN)
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = ROCKET;
		game->map[game->y_player][game->x_player - 1] = SPACES;
		game->moves++;
		map_draw(game);
	}
}

/*This function handles the player's movement to the left 
If the player is on a cell with the finish and has collected all items, the game ends.
If the player encounters a wall (WALLS) or the finish (MARS),
their position remains unchanged.
Otherwise, the player moves, and the map is updated and redrawn on the screen.*/
void	rocket_a(t_game *game)
{
	rocket_update_image('a', game);
	if (game->map[game->y_player][game->x_player] == MARS
			&& game->n_collect == 0)
	{
		game->moves++;
		game->endgame = 1;
		mlx_clear_window(game->mlx, game->win);
	}
	else if (game->map[game->y_player][game->x_player] == WALLS
			|| game->map[game->y_player][game->x_player] == MARS)
		game->x_player += 1;
	else
	{
		mlx_clear_window(game->mlx, game->win);
		if (game->map[game->y_player][game->x_player] == ALIEN)
			game->n_collect -= 1;
		game->map[game->y_player][game->x_player] = ROCKET;
		game->map[game->y_player][game->x_player + 1] = SPACES;
		game->moves++;
		map_draw(game);
	}
}
