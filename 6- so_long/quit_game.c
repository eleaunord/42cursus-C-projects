/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:01:51 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/05 18:31:10 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	matrix_delete(char **matrix)
{
	size_t	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	destroy_map(t_map *map)
{
	if (!map)
		return ;
	matrix_delete(map->body);
	free(map);
}

void	destroy_sprites(t_game *game)
{
	if (game->wall)
		mlx_destroy_image(game->graphics.mlx, game->wall);
	if (game->empty)
		mlx_destroy_image(game->graphics.mlx, game->empty);
	if (game->player)
		mlx_destroy_image(game->graphics.mlx, game->player);
	if (game->collectibles)
		mlx_destroy_image(game->graphics.mlx, game->collectibles);
	if (game->exit)
		mlx_destroy_image(game->graphics.mlx, game->exit);
}

void	destroy(t_game *game)
{
	if (!game)
		return ;
	if (game->wall || game->empty || game->player || game->collectibles
		|| game->exit)
		destroy_sprites(game);
	if (game->graphics.win)
		mlx_destroy_window(game->graphics.mlx, game->graphics.win);
	if (game->graphics.mlx)
		mlx_destroy_display(game->graphics.mlx);
	if (game->map)
		destroy_map(game->map);
	if (game->graphics.mlx)
		free(game->graphics.mlx);
}

int	quit_game(t_game *game)
{
	destroy(game);
	exit(EXIT_SUCCESS);
}

void	exit_error(char *s, t_game *game)
{
	destroy(game);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
