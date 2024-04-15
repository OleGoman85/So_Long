/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:40:56 by ogoman            #+#    #+#             */
/*   Updated: 2024/04/12 12:39:43 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This function displays the number of steps (movements)
taken by the player on the screen.
It utilizes the MLX library to render text on the screen.*/
void	draw_step_count(t_game *game)
{
	char	*str;
	char	*step_str;
	char	*new_str;

	step_str = "Step Count: ";
	str = ft_itoa(game->moves);
	new_str = ft_strjoin(step_str, str);
	mlx_string_put(game->mlx, game->win, 30, 10, COLOR_GREEN, new_str);
	free(str);
	free(new_str);
}

/*This function displays the number of collected items on the screen.
It also uses the MLX library to render text on the screen.*/
void	draw_collect_count(t_game *game)
{
	char	*str;
	char	*collect_str;
	char	*new_str;

	collect_str = "Collect Count: ";
	str = ft_itoa(game->n_collect);
	new_str = ft_strjoin(collect_str, str);
	mlx_string_put(game->mlx, game->win, 150, 10, COLOR_GREEN, new_str);
	free(str);
	free(new_str);
}

/*This function handles keyboard events. Depending on the pressed key,
it updates the player's position.*/
static void	game_events(int keycode, t_game *game)
{
	if (keycode == KEY_W)
	{
		game->y_player -= 1;
		rocket_w(game);
	}
	else if (keycode == KEY_S)
	{
		game->y_player += 1;
		rocket_s(game);
	}
	else if (keycode == KEY_D)
	{
		game->x_player += 1;
		rocket_d(game);
	}
	else if (keycode == KEY_A)
	{
		game->x_player -= 1;
		rocket_a(game);
	}
}

/*This function handles keyboard key press events.
It is called upon each key press and invokes the
game_events function to update the game state.*/
static int	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	else if (!game->endgame)
	{
		game_events(keycode, game);
		printf("Moves: %d\n", game->moves);
		draw_step_count(game);
		draw_collect_count(game);
		if (game->endgame == 1)
		{
			exit_game(game);
		}
	}
	return (0);
}

/*This function sets up event handlers for the game window.*/
void	gameplay(t_game *game)
{
	mlx_hook(game->win, 2, 0, keypress, game);
	mlx_hook(game->win, 17, 0, exit_game, game);
}
