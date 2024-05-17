/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svalchuk <svalchuk@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 22:07:14 by svalchuk          #+#    #+#             */
/*   Updated: 2024/05/17 18:37:40 by svalchuk         ###   ########.fr       */
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

int	ft_element_count(t_game *game, char **map, char element)
{
	int	i;
	int	j;
	int	elements;

	j = 0;
	elements = 0;
	while (j < game->map.height)
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == element)
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

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	dst = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dst)
		return (NULL);
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
