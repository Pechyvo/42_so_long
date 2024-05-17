/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:55:45 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/17 19:29:02 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static void	ft_fill(char **map, t_check size, t_check start, char to_fill[]);
static int	ft_check_path(t_game *game, char **map_check);

int	ft_pathfinder(t_game *game)
{
	t_check	size;
	t_check	start;
	char	**map_check;
	int		i;

	ft_find_player(game);
	i = 0;
	size.x = game->map.width;
	size.y = game->map.height;
	start.x = game->character.x;
	start.y = game->character.y;
	map_check = malloc(sizeof(char *) * (size.y + 1));
	while (i < size.y)
	{
		map_check[i] = ft_strcpy(map_check[i], game->map.map[i]);
		i++;
	}
	map_check[i] = NULL;
	ft_fill(map_check, size, start, "P0CE");
	return (ft_check_path(game, map_check));
}

static void	ft_fill(char **map, t_check size, t_check start, char to_fill[])
{
	char	c;
	int		i;

	if (start.y < 0 || start.y >= size.y || start.x < 0 || start.x >= size.x)
		return ;
	i = 0;
	c = map[start.y][start.x];
	while (i < 4)
	{
		if (c == to_fill[i])
		{
			map[start.y][start.x] = 'X';
			if (to_fill[i] == 'E')
				return ;
			ft_fill(map, size, (t_check){start.x - 1, start.y}, to_fill);
			ft_fill(map, size, (t_check){start.x + 1, start.y}, to_fill);
			ft_fill(map, size, (t_check){start.x, start.y - 1}, to_fill);
			ft_fill(map, size, (t_check){start.x, start.y + 1}, to_fill);
			break ;
		}
		i++;
	}
}

static int	ft_check_path(t_game *game, char **map_check)
{
	int	i;

	i = 0;
	if (ft_element_count(game, map_check, 'E') != 0 \
		|| ft_element_count(game, map_check, 'C') != 0)
	{
		while (map_check[i])
		{
			free(map_check[i]);
			i++;
		}
		free(map_check);
		return (1);
	}
	else
	{
		while (map_check[i])
		{
			free(map_check[i]);
			i++;
		}
		free(map_check);
	}
	return (0);
}
