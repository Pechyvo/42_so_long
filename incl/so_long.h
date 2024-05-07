/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:03:48 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/07 22:16:16 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../ft_printf/ft_printf.h"
# include <sys/time.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define MAP_SIZE 100

# define KEY_ESC 65307
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_Q 113
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void	*mlx_init;
	void	*mlx_game;
	t_map	map;
	t_map	map_copy;
}	t_game;

void	ft_init_game(t_game *game, char *path);
int		ft_key_hooks(int kc, t_game *game);
int	ft_strcmp(char *s1, char *s2);
void	ft_render_map(t_game *game, char *path);

#endif