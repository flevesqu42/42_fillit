/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 08:37:06 by flevesqu          #+#    #+#             */
/*   Updated: 2015/12/11 01:05:33 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			get_mv_to_topleft(t_tetri *s)
{
	unsigned char	y;
	unsigned char	y_move;
	unsigned char	x;
	unsigned char	x_move;

	y = 0;
	x_move = 4;
	y_move = 4;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s->map[y][x] == s->letter && (x_move > x))
				x_move = x;
			if (s->map[y][x] == s->letter && (y_move > y))
				y_move = y;
			x++;
		}
		y++;
	}
	move_to_topleft(s, y_move, x_move);
}

void			move_to_topleft(t_tetri *s, unsigned char y_move,
		unsigned char x_move)
{
	unsigned char	y;
	unsigned char	x;

	y = 0;
	s->size_x = 0;
	s->size_y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (s->map[y][x] == s->letter)
			{
				if (y_move || x_move)
				{
					s->map[y - y_move][x - x_move] = s->letter;
					s->map[y][x] = '.';
				}
				s->size_x = x - x_move > s->size_x ? x - x_move : s->size_x;
				s->size_y = y - y_move > s->size_y ? y - y_move : s->size_y;
			}
			x++;
		}
		y++;
	}
}

int				end(t_tetri **first)
{
	if (*first)
		free_tetri(*first);
	return (1);
}

void			free_tetri(t_tetri *first)
{
	if (first->next)
		free_tetri(first->next);
	free(first);
	first = NULL;
}
