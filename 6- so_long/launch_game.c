/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:30:25 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/05 18:25:39 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_images_to_window2(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->rows)
	{
		y = 0;
		while (y < game->map->cols)
		{
			if (game->map->body[x][y] == 'C')
				mlx_put_image_to_window(game->graphics.mlx, game->graphics.win,
					game->collectibles, 32 * y, 32 * x);
			else if (game->map->body[x][y] == 'E')
				mlx_put_image_to_window(game->graphics.mlx, game->graphics.win,
					game->exit, 32 * y, 32 * x);
			else if (game->map->body[x][y] == 'P')
				mlx_put_image_to_window(game->graphics.mlx, game->graphics.win,
					game->player, 32 * y, 32 * x);
			y++;
		}
		x++;
	}
}

void	put_images_to_window(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map->rows)
	{
		y = 0;
		while (y < game->map->cols)
		{
			if (game->map->body[x][y] == '1')
				mlx_put_image_to_window(game->graphics.mlx, game->graphics.win,
					game->wall, 32 * y, 32 * x);
			else if (game->map->body[x][y] == '0')
				mlx_put_image_to_window(game->graphics.mlx, game->graphics.win,
					game->empty, 32 * y, 32 * x);
			y++;
		}
		x++;
	}
}

void	launch_graphics(t_game *game)
{
	int	img_width;
	int	img_cols;

	img_width = 32;
	img_cols = 32;
	game->wall = mlx_xpm_file_to_image(game->graphics.mlx,
			"./textures/wall.xpm", &img_width, &img_cols);
	game->collectibles = mlx_xpm_file_to_image(game->graphics.mlx,
			"./textures/collectibles.xpm", &img_width, &img_cols);
	game->exit = mlx_xpm_file_to_image(game->graphics.mlx,
			"./textures/exit.xpm", &img_width, &img_cols);
	game->player = mlx_xpm_file_to_image(game->graphics.mlx,
			"./textures/player.xpm", &img_width, &img_cols);
	game->empty = mlx_xpm_file_to_image(game->graphics.mlx,
			"./textures/empty.xpm", &img_width, &img_cols);
	if (!game->wall || !game->collectibles || !game->player || !game->exit
		|| !game->empty)
		exit_error("Failed xpm allocation. ", game);
	put_images_to_window(game);
	put_images_to_window2(game);
}

void	launch_game(t_game *game)
{
	game->graphics.mlx = mlx_init();
	game->moves = -1;
	if (!game->graphics.mlx)
		exit_error("There is a problem with initializing the minilibx. ", game);
	game->graphics.win = mlx_new_window(game->graphics.mlx, game->map->cols
			* 32, game->map->rows * 32, "./so_long");
	if (!game->graphics.win)
		exit_error("There is a problem with initializing the game window. ",
			game);
	launch_graphics(game);
}
