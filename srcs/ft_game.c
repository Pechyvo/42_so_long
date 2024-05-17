/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:36 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/17 19:19:18 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	ft_exit_game(void);

void	ft_init_game(t_game *game, char *path)
{
	int	x;
	int	y;

	ft_read_map(game, path);
	x = game->map.width * 64;
	y = game->map.height * 64;
	game->mlx_init = mlx_init();
	game->mlx_game = mlx_new_window(game->mlx_init, x, y, "Dungeon Master");
	mlx_hook(game->mlx_game, 17, 1L << 0, ft_exit_game, game);
	mlx_key_hook(game->mlx_game, ft_key_hooks, game);
	mlx_loop(game->mlx_init);
	free(game);
}

static int	ft_exit_game(void)
{
	exit(0);
	return (0);
}

void	ft_free_window(t_game game)
{
	mlx_destroy_window(game.mlx_init, game.mlx_game);
	exit(0);
}

void	ft_free_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[i])
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
	exit(1);
}
