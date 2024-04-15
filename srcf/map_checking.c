/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogoman <ogoman@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 08:41:16 by ogoman            #+#    #+#             */
/*   Updated: 2024/04/11 09:16:48 by ogoman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//Function checking map structure(that all map lines are the same length)
int	check_map_structure(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

//Function checking map walls(that all map walls are equel 1)
int	check_walls(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i] != NULL)
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != WALLS || map[i - 1][j] != WALLS)
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i] != NULL)
	{
		if (map[i][0] != WALLS || map[i][len - 1] != WALLS)
			return (0);
		i++;
	}
	return (1);
}

/*The function count_map_items is responsible for counting the number of
items in the game map and ensuring that the number of
items meets the requirements.*/
int	count_map_items(t_game *game)
{
	int	i;
	int	j;

	game->n_collect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	i = 0;
	while (game->map[i] != NULL)
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == ROCKET)
				game->n_player++;
			else if (game->map[i][j] == MARS)
				game->n_exit++;
			else if (game->map[i][j] == ALIEN)
				game->n_collect++;
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_exit != 1 || game->n_collect == 0)
		return (0);
	return (1);
}

/*The function checking the playing field for the presence of allowed items*/
int	check_game_field(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != ROCKET && map[i][j] != MARS && map[i][j] != ALIEN
				&& map[i][j] != SPACES && map[i][j] != WALLS)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// checkig for the .ber
int	correct_file(char *str, char *suffix)
{
	int	str_len;
	int	suffix_len;

	str_len = ft_strlen(str);
	suffix_len = ft_strlen(suffix);
	if (str_len < suffix_len)
		return (0);
	return (ft_strncmp(str + (str_len - suffix_len), suffix, suffix_len) == 0);
}
