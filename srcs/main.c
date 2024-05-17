/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:35:46 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/17 19:36:08 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	ft_check_extension(const char *argv);

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_print_error("Wrong number of arguments!");
		exit(1);
	}
	if (!(ft_check_extension(argv[1])))
	{
		ft_print_error("Wrong file extension!");
		exit(1);
	}
	if (argc == 2 && ft_check_extension(argv[1]))
	{
		game = ft_calloc(sizeof(t_game), 1);
		game->character.moves = 0;
		game->collectibles = 0;
		ft_init_game(game, argv[1]);
	}
	return (0);
}

static int	ft_check_extension(const char *argv)
{
	char	*ext;

	ext = ft_strrchr(argv, '.');
	if (ext)
		return (ft_strcmp(ext, ".ber") == 0);
	return (0);
}
