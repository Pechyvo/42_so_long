/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:09:13 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/07 21:46:08 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

	//printf("Keycode: %d\n", kc);
int	ft_key_hooks(int kc, t_game *game)
{
	(void)game;
	(void)kc;	
	// if (kc == KEY_ESC || kc == KEY_Q)
	// 	ft_game_exit(game);
	// if (kc == KEY_LEFT || kc == KEY_A)
	// {
	// }
	return (0);
}
// # define KEY_ESC 65307
// # define KEY_LEFT 65361
// # define KEY_UP 65362
// # define KEY_RIGHT 65363
// # define KEY_DOWN 65364
// # define KEY_Q 113
// # define KEY_W 119
// # define KEY_A 97
// # define KEY_S 115
// # define KEY_D 100