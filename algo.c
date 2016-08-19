/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:25:17 by flevesqu          #+#    #+#             */
/*   Updated: 2015/12/14 22:27:31 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	resolve(t_tetri *s, t_map *map)
{
	char	ret;

	s->y = 0;
	while (s->y + s->size_y < map->size)
	{
		s->x = 0;
		while (s->x + s->size_x < map->size)
		{
			if (check_map(s, map))
			{
				if (s->next)
					ret = resolve(s->next, map);
				if (!s->next || ret == 0)
					return (0);
				del_tetri(s, map);
			}
			s->x += 1;
		}
		s->y += 1;
	}
	return (1);
}

char	check_map(t_tetri *s, t_map *map)
{
	unsigned char y;
	unsigned char x;
	unsigned char counter;

	counter = 0;
	y = 0;
	while (y <= s->size_y)
	{
		x = 0;
		while (x <= s->size_x)
		{
			if (map->map[s->y + y][s->x + x] == '.'
					&& s->map[y][x] == s->letter)
				counter++;
			if (counter == 4)
			{
				write_in_map(s, map);
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	del_tetri(t_tetri *s, t_map *map)
{
	unsigned char y;
	unsigned char x;

	y = 0;
	while (y <= s->size_y)
	{
		x = 0;
		while (x <= s->size_x)
		{
			if (map->map[s->y + y][s->x + x] == s->letter)
				map->map[s->y + y][s->x + x] = '.';
			x++;
		}
		y++;
	}
}

void	write_in_map(t_tetri *s, t_map *map)
{
	unsigned char	y;
	unsigned char	x;

	y = 0;
	while (y <= s->size_y)
	{
		x = 0;
		while (x <= s->size_x)
		{
			if (s->map[y][x] == s->letter)
				map->map[s->y + y][s->x + x] = s->letter;
			x++;
		}
		y++;
	}
}
