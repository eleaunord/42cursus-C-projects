/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_characters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:47:49 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/05 15:27:08 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	final_char_check(t_game *game)
{
	if (game->map->exit == 0 || game->map->exit > 1
		|| game->map->player_pos == 0 || game->map->player_pos > 1
		|| game->map->collectibles == 0)
		return (false);
	else
		return (true);
}

void	set_player(t_game *game, int x, int y)
{
	game->map->player_pos++;
	game->player_pos = (t_point){x, y};
}

void	set_exit(t_game *game, int x, int y)
{
	game->map->exit++;
	game->exit_pos = (t_point){x, y};
}

void	init_count_char(t_game *game)
{
	game->map->collectibles = 0;
	game->map->exit = 0;
	game->map->player_pos = 0;
}

bool	check_characters(t_game *game)
{
	int	x;
	int	y;

	init_count_char(game);
	x = 0;
	while (x < game->map->rows)
	{
		y = 0;
		while (y < game->map->cols)
		{
			if (game->map->body[x][y] == 'C')
				game->map->collectibles++;
			else if (game->map->body[x][y] == 'E')
				set_exit(game, x, y);
			else if (game->map->body[x][y] == 'P')
				set_player(game, x, y);
			y++;
		}
		x++;
	}
	if (final_char_check(game) == false)
		return (false);
	return (true);
}
