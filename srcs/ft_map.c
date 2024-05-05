/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:31:45 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/03 23:41:06 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_map_read(t_game *game, char *path)
{
	int		fd;
	char	c;
	
	// if (path == "map/")
	// 	fd = open(path, O_RDONLY);
	// else
	// 	fd = open("map/" + *path, O_RDONLY);
	fd = open(path, O_RDONLY);
	while (fd)
	{
		
	}
}
