/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:36 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/05 19:59:07 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	ft_game_exit(void)
{
	exit(0);
	return (0);	
}

void	ft_game_init(t_game *game, char *path)
{
	game->mlx_init = mlx_init();
	ft_map_read(game, path);
	game->mlx_game = mlx_new_window(game->mlx_init, 500, 500, "Dungeon Master");
	mlx_hook(game->mlx_game, 17, 1L << 0, ft_game_exit, game);
	mlx_key_hook(game->mlx_game, ft_key_hooks, game);
	mlx_loop(game->mlx_init);
	free(game);
}
