/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:31:45 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/07 22:50:00 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_render_map(t_game *game, char *path)
{
	int		fd;
	int		w;
	int		h;

	h = 0;
	game->map.map= malloc(sizeof(char *) * MAP_SIZE);
	if (ft_strnstr(path, "maps/", 5))
		fd = open(path, O_RDONLY);
	else
	{
		path = ft_strjoin("maps/", path);
		fd = open(path, O_RDONLY);
	}
	while (fd)
	{
		game->map.map[h] = get_next_line(fd);
		if(!game->map.map[h])
			break;
		h++;
	}
	game->map.map[h] = NULL;
	w = ft_strlen(game->map.map[0]);
	close(fd);
	//ft_validate_map(game, game->map.width = w, game->map.height = h);
}
