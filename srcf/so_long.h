/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:42:04 by ogoman            #+#    #+#             */
/*   Updated: 2024/04/12 12:40:43 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../helper_functions/minilibx42/mlx.h"
# include "../helper_functions/ft_printf/libft/libft.h"
# include "../helper_functions/ft_printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_collect;
	void	*img_exit;
	void	*img_losing;
	int		map_w;
	int		map_h;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		x_player;
	int		y_player;
	int		moves;
	int		endgame;
}	t_game;

# define KEY_ESC 53

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define ROCKET 'P'
# define MARS 'E'
# define WALLS '1'
# define SPACES '0'
# define ALIEN 'C'

# define COLOR_GREEN	0x00FF00

//texture.c
void	img_draw(t_game *game, void *image, int x, int y);
int		map_draw(t_game *game);

//gameplay.c
void	gameplay(t_game *game);
void	draw_step_count(t_game *game);
void	draw_collect_count(t_game *game);

//game_init.c
void	game_init(t_game *game);

//exit_game.c
void	free_map(char **map);
int		exit_game(t_game *game);

//action.c
void	rocket_w(t_game *game);
void	rocket_d(t_game *game);
void	rocket_s(t_game *game);
void	rocket_a(t_game *game);

//read_map.c
char	**read_map(char *path);

//map_checking.c
int		check_map_structure(char **map);
int		check_walls(char **map);
int		count_map_items(t_game *game);
int		check_game_field(char **map);
int		correct_file(char *str, char *suffix);

//so_long.c
int		main(int argc, char **argv);
int		map_checking(t_game *game);

#endif