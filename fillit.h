/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 04:27:15 by flevesqu          #+#    #+#             */
/*   Updated: 2015/12/11 09:10:38 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUF_SIZE (4 * 5 * 26 + 25 + 1)

typedef struct	s_map
{
	char			**map;
	unsigned char	size;
}				t_map;

typedef struct	s_tetri
{
	char			letter;
	unsigned char	size_y;
	unsigned char	size_x;
	unsigned char	y;
	unsigned char	x;
	char			map[4][4];
	struct s_tetri	*next;
}				t_tetri;

int				sub_function(char *file);

int				get_tetri(char *s, t_tetri **first, unsigned char *nb, int c);
int				convert_tetri(char **buf, t_tetri *minos);
void			get_mv_to_topleft(t_tetri *s);
void			move_to_topleft(t_tetri *s, unsigned char my, unsigned char mx);
int				check_tetri(t_tetri *minos);
unsigned char	check_next(t_tetri *s, unsigned char y, unsigned char x);
unsigned char	check_valid(t_tetri *s, unsigned char y, unsigned char x);

int				get_map(t_tetri **first, unsigned char *nb);
unsigned char	get_sq_min(unsigned char nb, t_tetri **first);
t_map			*create_and_init_map(unsigned char size);

char			resolve(t_tetri *minos, t_map *map);
char			check_map(t_tetri *minos, t_map *map);
void			write_in_map(t_tetri *minos, t_map *map);
void			del_tetri(t_tetri *minos, t_map *map);

void			display_map(t_map *map);
void			ft_putchar(char c);
int				end(t_tetri **first);
void			free_tetri(t_tetri *first);

#endif
