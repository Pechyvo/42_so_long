/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:31:45 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/13 23:44:53 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static void	ft_check_empty(char **map);
static void	ft_textures(t_game *game, char *path, int x, int y);

void	ft_read_map(t_game *game, char *path)
{
	int		fd;
	int		h;

	h = 0;
	game->map.map = malloc(sizeof(char *) * MAP_SIZE);
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
		if (!game->map.map[h])
			break ;
		h++;
	}
	game->map.map[h] = NULL;
	close(fd);
	ft_check_empty(game->map.map);
	game->map.height = h;
	game->map.width = ft_strlen(game->map.map[0]) - 1;
	ft_validate_map(game);
}

static void	ft_check_empty(char **map)
{
	if (!map[0])
	{
		ft_print_error("Map is empty!");
		exit(1);
	}
}

void	ft_draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				ft_textures(game, TEXTURE_FLOOR, x, y);
			else if (game->map.map[y][x] == '0')
				ft_textures(game, TEXTURE_WALL, x, y);
			else if (game->map.map[y][x] == 'E')
				ft_textures(game, TEXTURE_EXIT, x, y);
			else if (game->map.map[y][x] == 'P')
				ft_textures(game, TEXTURE_CHARACTER, x, y);
			else if (game->map.map[y][x] == 'C')
				ft_textures(game, TEXTURE_COLLECTIBLE, x, y);
			x++;
		}
		y++;
	}
	ft_find_player(game);
}

static void	ft_textures(t_game *game, char *path, int x, int y)
{
	void	*img;
	int		i;

	i = 64;
	img = mlx_xpm_file_to_image(game->mlx_init, path, &i, &i);
	mlx_put_image_to_window(game->mlx_init, game->mlx_game, img, x * i, y * i);
}
