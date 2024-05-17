/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 22:19:21 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/17 18:38:03 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	ft_check_form(t_game *game);
static int	ft_check_walls(t_game *game);
static int	ft_check_elements(t_game *game);
static int	ft_check_count(t_game *game);

void	ft_validate_map(t_game *game)
{
	if (ft_check_form(game))
	{
		ft_print_error("Map has invalid form!");
		ft_free_map(game);
	}
	if (ft_check_walls(game))
	{
		ft_print_error("Map is not closed!");
		ft_free_map(game);
	}
	if (ft_check_elements(game))
	{
		ft_print_error("Map has invalid elements!");
		ft_free_map(game);
	}
	if (ft_check_count(game))
	{
		ft_print_error("Map has invalid number of elements!");
		ft_free_map(game);
	}
	if (ft_pathfinder(game))
	{
		ft_print_error("Player cannot reach exit!");
		ft_free_map(game);
	}
}

static int	ft_check_form(t_game *game)
{
	int				i;
	unsigned long	j;

	i = 0;
	while (game->map.map[i + 1])
	{
		if (ft_strlen(game->map.map[i]) != ft_strlen(game->map.map[i + 1]))
		{
			j = ft_strlen(game->map.map[i + 1]);
			if (game->map.map[i + 2] == NULL \
				&& ft_strlen(game->map.map[i]) - 1 == j)
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	ft_check_walls(t_game *game)
{
	int				i;
	unsigned long	j;

	i = 0;
	j = ft_strlen(game->map.map[i]) - 1;
	while (game->map.map[i])
	{
		if (game->map.map[i][0] != '1' || game->map.map[i][j - 1] != '1')
			return (1);
		i++;
	}
	j = 0;
	while (j < ft_strlen(game->map.map[0]) - 1)
	{
		if (game->map.map[0][j] != '1' || game->map.map[i - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

static int	ft_check_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] != '0' \
				&& game->map.map[i][j] != '1' \
				&& game->map.map[i][j] != 'C' \
				&& game->map.map[i][j] != 'E' \
				&& game->map.map[i][j] != 'P' \
				&& game->map.map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_check_count(t_game *game)
{
	if (ft_element_count(game, game->map.map, 'P') != 1 \
		|| ft_element_count(game, game->map.map, 'E') != 1 \
		|| ft_element_count(game, game->map.map, 'C') < 1)
		return (1);
	return (0);
}
