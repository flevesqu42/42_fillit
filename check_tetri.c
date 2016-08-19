/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 23:00:15 by flevesqu          #+#    #+#             */
/*   Updated: 2015/12/10 23:10:17 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				check_tetri(t_tetri *s)
{
	unsigned char	y;
	unsigned char	x;
	int				ret;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s->map[y][x] == s->letter)
				if (!(ret = check_valid(s, y, x))
						|| (ret == 1 && check_next(s, y, x)))
					return (1);
			x++;
		}
		y++;
	}
	get_mv_to_topleft(s);
	return (0);
}

unsigned char	check_next(t_tetri *s, unsigned char y, unsigned char x)
{
	if (x < 3 && s->map[y][x + 1] == s->letter)
		if (check_valid(s, y, x + 1) < 2)
			return (1);
	if (x && s->map[y][x - 1] == s->letter)
		if (check_valid(s, y, x - 1) < 2)
			return (1);
	if (y < 3 && s->map[y + 1][x] == s->letter)
		if (check_valid(s, y + 1, x) < 2)
			return (1);
	if (y && s->map[y - 1][x] == s->letter)
		if (check_valid(s, y - 1, x) < 2)
			return (1);
	return (0);
}

unsigned char	check_valid(t_tetri *s, unsigned char y, unsigned char x)
{
	unsigned char	counter;

	counter = 0;
	if (x < 3 && s->map[y][x + 1] == s->letter)
		counter++;
	if (x && s->map[y][x - 1] == s->letter)
		counter++;
	if (y < 3 && s->map[y + 1][x] == s->letter)
		counter++;
	if (y && s->map[y - 1][x] == s->letter)
		counter++;
	return (counter);
}
