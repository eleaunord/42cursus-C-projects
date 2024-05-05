/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:29:58 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/05 18:18:07 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_map(char *file_name)
{
	int	i;

	i = 0;
	while (file_name[i])
		i++;
	i -= 1;
	if (file_name[i] == 'r' && file_name[i - 1] == 'e'
		&& file_name[i - 2] == 'b' && file_name[i - 3] == '.')
		return (1);
	else
		return (0);
}

char	*ft_stdup(char *src)
{
	char	*new;
	int		i;
	int		size;

	size = 0;
	while (src[size])
		size++;
	new = malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**mapcopy(t_game *game)
{
	int		i;
	char	**new;

	i = 0;
	while (game->map->body[i])
		i++;
	new = malloc(sizeof(char *) * (i + 1));
	if (new == NULL)
		exit_error("Error with the map copy.", game);
	i = 0;
	while (game->map->body[i])
	{
		new[i] = ft_stdup(game->map->body[i]);
		i++;
	}
	new[i] = 0;
	return (new);
}
