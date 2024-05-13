/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathfinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 23:55:45 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/14 00:16:00 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	ft_flood_fill();

int	ft_check_pathfinder(t_game *game)
{
	if (!ft_flood_fill(game, game->character.x, game->character.y))
		return (1);
	return (0);
}

static int	ft_flood_fill()
{

}
