/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:01:42 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/05 18:29:42 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		ft_printf("Error\nInvalid number of parameters. ");
	else if (!name_map(argv[1]))
		ft_printf("Error\nThe name of the map file is incorrect. ");
	else
	{
		ft_bzero(&game, sizeof(t_game));
		read_map(argv[1], &game);
		floodfill(&game);
		launch_game(&game);
		mlx_key_hook(game.graphics.win, &press, &game);
		mlx_hook(game.graphics.win, 17, (1L << 1), &quit_game, &game);
		mlx_loop(game.graphics.mlx);
	}
	return (0);
}
