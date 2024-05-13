/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:07:14 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/13 23:54:18 by svalchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_print_error(char *str)
{
	ft_printf(COLOR_RED"\n  ERROR » "COLOR_RESET \
			COLOR_BLUE"%s\n\n"COLOR_RESET, str);
}

void	ft_find_player(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map.height)
	{
		i = 0;
		while (game->map.map[j][i])
		{
			if (game->map.map[j][i] == 'P')
			{
				game->character.x = i;
				game->character.y = j;
				break ;
			}
			i++;
		}
		j++;
	}
}

int	ft_element_count(t_game *game, char element)
{
	int	i;
	int	j;
	int	elements;

	j = 0;
	elements = 0;
	while (j < game->map.height)
	{
		i = 0;
		while (game->map.map[j][i])
		{
			if (game->map.map[j][i] == element)
				elements++;
			i++;
		}
		j++;
	}
	return (elements);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}
