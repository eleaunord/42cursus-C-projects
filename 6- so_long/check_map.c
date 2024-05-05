/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:56:48 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/05 15:19:16 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static bool	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map->rows)
	{
		if (game->map->body[i][0] != '1' || game->map->body[i][game->map->cols
			- 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < game->map->cols)
	{
		if (game->map->body[0][i] != '1' || game->map->body[game->map->rows
			- 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

static bool	check_rectangle(t_game *game)
{
	int	i;
	int	first_len;

	i = 0;
	first_len = get_len(game->map->body[0]);
	while (i < game->map->rows)
		if (get_len(game->map->body[i++]) != first_len)
			return (false);
	game->map->cols = first_len;
	return (true);
}

static bool	invalid_key(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->rows)
	{
		y = 0;
		while (y < game->map->cols)
		{
			if (game->map->body[x][y] != '1' && game->map->body[x][y] != 'C'
				&& game->map->body[x][y] != 'E' && game->map->body[x][y] != 'P'
				&& game->map->body[x][y] != '0')
				return (false);
			y++;
		}
		x++;
	}
	return (true);
}

void	check_map(t_game *game)
{
	if (game->map->rows == 0)
		exit_error("Map is empty.", game);
	if (check_rectangle(game) == false)
		exit_error("Map is not a rectangle.", game);
	if (check_walls(game) == false)
		exit_error("Map is not correctly bounded.", game);
	if (check_characters(game) == false)
		exit_error("Map has an invalid number of entities. ", game);
	if (invalid_key(game) == false)
		exit_error("The map is not composed of the correct characters. ", game);
}
