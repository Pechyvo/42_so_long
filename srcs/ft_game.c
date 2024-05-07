/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:59:36 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/07 21:54:15 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	ft_exit_game(void)
{
	exit(0);
	return (0);
}

void	ft_init_game(t_game *game, char *path)
{
	ft_render_map(game, path);
	game->mlx_init = mlx_init();
	game->mlx_game = mlx_new_window(game->mlx_init, 500, 500, "Dungeon Master");
	mlx_hook(game->mlx_game, 17, 1L << 0, ft_exit_game, game);
	mlx_key_hook(game->mlx_game, ft_key_hooks, game);
	mlx_loop(game->mlx_init);
	free(game);
}
