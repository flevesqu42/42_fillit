/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 09:07:24 by flevesqu          #+#    #+#             */
/*   Updated: 2015/12/09 18:40:25 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_map(t_map *map)
{
	int x;
	int	y;

	y = 0;
	while (y < map->size)
	{
		x = 0;
		while (x < map->size)
		{
			ft_putchar(map->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		free(map->map[y]);
		y++;
	}
	free(map->map);
}
