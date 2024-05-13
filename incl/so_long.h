/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:03:48 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/14 00:03:15 by svalchuk         ###   ########.fr       */
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

# define TEXTURE_WALL "textures/Wall.xpm"
# define TEXTURE_FLOOR "textures/Floor.xpm"
# define TEXTURE_EXIT "textures/Exit.xpm"
# define TEXTURE_CHARACTER "textures/Character.xpm"
# define TEXTURE_COLLECTIBLE "textures/Collectible.xpm"

# define COLOR_RESET "\033[0m"
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_BLUE "\033[0;34m"
# define COLOR_CYAN "\033[0;36m"

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

typedef struct s_character
{
	int		x;
	int		y;
	int		moves;
	int		count;
}	t_character;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void		*mlx_init;
	void		*mlx_game;
	t_map		map;
	t_character	character;
	int			collectibles;
	int			exit;
}	t_game;

void	ft_init_game(t_game *game, char *path);
void	ft_read_map(t_game *game, char *path);
void	ft_validate_map(t_game *game);
void	ft_draw(t_game *game);
int		ft_key_hooks(int kc, t_game *game);
int		ft_check_pathfinder(t_game *game);
void	ft_free_window(t_game game);
void	ft_free_map(t_game *game);
void	ft_print_error(char *str);
void	ft_find_player(t_game *game);
int		ft_element_count(t_game *game, char element);
int		ft_strcmp(char *s1, char *s2);

#endif