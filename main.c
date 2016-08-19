/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 03:25:17 by flevesqu          #+#    #+#             */
/*   Updated: 2015/12/14 22:26:53 by flevesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc != 2 || sub_function(argv[1]))
		write(1, "error\n", 6);
	return (0);
}

int	sub_function(char *file)
{
	unsigned char	*nb_tetri;
	int				fd;
	int				ret;
	char			buffer[BUF_SIZE + 1];
	t_tetri			**first;

	nb_tetri = (unsigned char*)malloc(sizeof(unsigned char));
	if ((fd = open(file, O_RDONLY)) == -1 || !nb_tetri)
		return (1);
	if ((ret = read(fd, buffer, BUF_SIZE)) == -1)
		return (1);
	if (close(fd) == -1)
		return (1);
	if (ret > 545)
		return (1);
	buffer[ret] = '\0';
	if (!(first = (t_tetri**)malloc(sizeof(t_tetri*))))
		return (2);
	ret = 'A';
	if (get_tetri(buffer, first, nb_tetri, ret) || get_map(first, nb_tetri))
		return (1);
	end(first);
	free(nb_tetri);
	return (0);
}

int	get_tetri(char *s, t_tetri **first, unsigned char *nb_tetri, int letter)
{
	t_tetri			*minos;

	if (!(minos = (t_tetri*)malloc(sizeof(t_tetri))))
		return (2);
	minos->letter = letter;
	if (convert_tetri(&s, minos) || check_tetri(minos))
		return (1);
	*first = minos;
	while (*s)
	{
		letter++;
		if (*s != '\n')
			return (1);
		s += 1;
		if (!*s)
			return (1);
		if (!(minos->next = (t_tetri*)malloc(sizeof(t_tetri))))
			return (2);
		minos = minos->next;
		minos->letter = letter;
		if (convert_tetri(&s, minos) || check_tetri(minos))
			return (1);
	}
	*nb_tetri = letter + 1 - 'A';
	return (0);
}

int	convert_tetri(char **buffer, t_tetri *minos)
{
	unsigned char	x;
	unsigned char	y;
	unsigned char	count;

	y = 0;
	count = 0;
	minos->next = NULL;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			**buffer == '#' ? count++ : count;
			if ((**buffer != '.' && **buffer != '#') || count > 4)
				return (1);
			minos->map[y][x] = **buffer == '#' ? minos->letter : '.';
			x++;
			*buffer += 1;
		}
		if (**buffer != '\n')
			return (1);
		*buffer += 1;
		y++;
	}
	return (count != 4 ? 1 : 0);
}
