/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:27:07 by eleroty           #+#    #+#             */
/*   Updated: 2024/04/05 16:41:05 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

char	*trim(char const *s1, char const *set)
{
	char	*new;
	size_t	end;
	size_t	start;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	new = ft_substr(s1, start, (end - start) + 1);
	if (!new)
		return (NULL);
	return (new);
}

int	get_num_lines(char *path, t_game *game)
{
	int		fd;
	int		lines;
	char	*tmp;

	lines = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Map cannot be opened.", game);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
		{
			break ;
		}
		lines++;
		free(tmp);
	}
	close(fd);
	return (lines);
}

t_map	*map_new(int cols, int rows)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->body = ft_calloc(rows + 1, sizeof(char *));
	if (!map->body)
	{
		return (NULL);
	}
	map->cols = cols;
	map->rows = rows;
	return (map);
}

void	read_map(char *path, t_game *game)
{
	int fd;
	char *tmp;
	int i;

	i = 0;
	game->map = map_new(0, get_num_lines(path, game));
	if (!game->map)
		exit_error("Allocation error on map. ", game);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("Map cannot be opened.", game);
	while (i < game->map->rows)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			exit_error("Allocation failed on map lines. ", game);
		game->map->body[i] = trim(tmp, "\n");
		if (!game->map->body[i])
			exit_error("Allocation failed on map lines 2.", game);
		free(tmp);
		i++;
	}
	close(fd);
	check_map(game);
}

// int	count_line(char *nom_map, t_data *data)
// {
// 	int		count;
// 	int		fd;
// 	int		ret;
// 	char	buff[2];

// 	count = 0;
// 	fd = open(nom_map, O_RDONLY);
// 	if (fd == -1)
// 	{
// 		write(1, "ERROR", 5);
// 		exit(0);
// 	}
// 	ret = 1;
// 	while (ret)
// 	{
// 		ret = read(fd, buff, 1);
// 		buff[ret] = '\0';
// 		if (buff[0] == '\n' || buff[0] == '\0')
// 			count++;
// 	}
// 	close(fd);
// 	data->nb_line = count;
// 	return (count);
// }
// int	empty_map(t_game *game, int fd)
// {
// 	free(game->map);
// 	write (1, "ERROR\n", 6);//
// 	close(fd);
// 	exit(0);
// }

// void	read_map(char *path, t_game *game)
// {
// 	int		fd;
// 	int		count_on_line;
// 	int		ret;
// 	char	buff[2];

// 	game->map = malloc(sizeof(char *) * (count_line(path, game) + 1));
// 	if (game->map == NULL)
// 		exit_error("Allocation error on map. ", game);
// 	fd = open(path, O_RDONLY);
// 	ret = 1;
// 	count_on_line = 0;
// 	while (1)
// 	{
// 		ret = read(fd, buff, 1);
// 		buff[ret] = '\0';
// 		if (buff[0] == '\n' || buff[0] == '\0')
// 			break ;
// 		count_on_line++;
// 	}
// 	if (count_on_line == 0)
// 		empty_map(game, fd);
// 	close(fd);
// 	game->map->rows = count_on_line;
// }