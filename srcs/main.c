/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:35:46 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/07 18:12:45 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static int	ft_check_extension(const char *argv)
{
	char	*ext;

	ext = ft_strrchr(argv, '.');
	if (ext)
		return (ft_strcmp(ext, ".ber") == 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of arguments\n");
		exit(0);
	}
	if (!(ft_check_extension(argv[1])))
	{
		ft_printf("Error\nWrong file extension\n");
		exit(0);
	}
	if (argc == 2 && ft_check_extension(argv[1]))
	{
		game = ft_calloc(sizeof(t_game), 1);
		ft_init_game(game, argv[1]);
	}
	return (0);
}
