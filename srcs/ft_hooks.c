/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_hooks.c										 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/05/01 23:09:13 by svalchuk		  #+#	#+#			 */
/*   Updated: 2024/05/13 22:38:34 by svalchuk		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	ft_movement(int kc, t_game *game, int x, int y);
static int	ft_check_exit(int kc, t_game *game, int x, int y);
static int	ft_move_check(t_game *game, int x, int y, int flag);
static int	ft_condition(t_game *game, int x, int y, int flag);

int	ft_key_hooks(int kc, t_game *game)
{
	if (kc == KEY_ESC || kc == KEY_Q)
	{
		ft_printf(COLOR_PURPLE"\n  Game was closed.\n\n"COLOR_RESET);
		ft_free_window(*game);
	}
	if (kc == KEY_UP || kc == KEY_W \
		|| kc == KEY_LEFT || kc == KEY_A \
		|| kc == KEY_DOWN || kc == KEY_S \
		|| kc == KEY_RIGHT || kc == KEY_D)
	{
		if (ft_check_exit(kc, game, game->character.x, game->character.y) == 1)
		{
			ft_printf(COLOR_GREEN"\n  Victory!!!\n\n"COLOR_RESET);
			ft_free_window(*game);
		}
		if (ft_movement(kc, game, game->character.x, game->character.y) == 1)
		{
			game->character.moves++;
			ft_printf(COLOR_CYAN"Moves: %d\n" \
					COLOR_RESET, game->character.moves);
		}
	}
	ft_draw(game);
	return (0);
}

static	int	ft_movement(int kc, t_game *game, int x, int y)
{
	if ((kc == KEY_W || kc == KEY_UP) && ft_move_check(game, x, y, 1))
	{
		game->map.map[y--][x] = '0';
		game->map.map[y][x] = 'P';
		return (1);
	}
	else if ((kc == KEY_A || kc == KEY_LEFT) && ft_move_check(game, x, y, 2))
	{
		game->map.map[y][x--] = '0';
		game->map.map[y][x] = 'P';
		return (1);
	}
	else if ((kc == KEY_S || kc == KEY_DOWN) && ft_move_check(game, x, y, 3))
	{
		game->map.map[y++][x] = '0';
		game->map.map[y][x] = 'P';
		return (1);
	}
	else if ((kc == KEY_D || kc == KEY_RIGHT) && ft_move_check(game, x, y, 4))
	{
		game->map.map[y][x++] = '0';
		game->map.map[y][x] = 'P';
		return (1);
	}
	return (0);
}

static int	ft_move_check(t_game *game, int x, int y, int flag)
{
	if (flag == 1 && game->map.map[y - 1][x] != '1' \
		&& game->map.map[y - 1][x] != 'E')
		return (1);
	if (flag == 2 && game->map.map[y][x - 1] != '1' \
		&& game->map.map[y][x - 1] != 'E')
		return (1);
	if (flag == 3 && game->map.map[y + 1][x] != '1' \
		&& game->map.map[y + 1][x] != 'E')
		return (1);
	if (flag == 4 && game->map.map[y][x + 1] != '1' \
		&& game->map.map[y][x + 1] != 'E')
		return (1);
	return (0);
}

static int	ft_check_exit(int kc, t_game *game, int x, int y)
{
	if ((kc == KEY_W || kc == KEY_UP) && ft_condition(game, x, y, 1))
	{
		ft_movement(kc, game, x, y);
		return (1);
	}
	else if ((kc == KEY_A || kc == KEY_LEFT) && ft_condition(game, x, y, 2))
	{
		ft_movement(kc, game, x, y);
		return (1);
	}
	else if ((kc == KEY_S || kc == KEY_DOWN) && ft_condition(game, x, y, 3))
	{
		ft_movement(kc, game, x, y);
		return (1);
	}
	else if ((kc == KEY_D || kc == KEY_RIGHT) && ft_condition(game, x, y, 4))
	{
		ft_movement(kc, game, x, y);
		return (1);
	}
	return (0);
}

static int	ft_condition(t_game *game, int x, int y, int flag)
{
	game->collectibles = ft_element_count(game, game->map.map, 'C');
	if (flag == 1 && game->map.map[y - 1][x] == 'E' \
		&& game->collectibles == 0)
		return (1);
	if (flag == 2 && game->map.map[y][x - 1] == 'E' \
		&& game->collectibles == 0)
		return (1);
	if (flag == 3 && game->map.map[y + 1][x] == 'E' \
		&& game->collectibles == 0)
		return (1);
	if (flag == 4 && game->map.map[y][x + 1] == 'E' \
		&& game->collectibles == 0)
		return (1);
	return (0);
}
