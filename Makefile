# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flevesqu <flevesqu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/08 16:22:10 by flevesqu          #+#    #+#              #
#    Updated: 2015/12/14 22:28:45 by flevesqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra
INCLUDES = ./
SRC = display.c\
	  algo.c\
	  main.c\
	  map.c\
	  move_tetri.c\
	  check_tetri.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -c $(SRC) -I$(INCLUDES)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES)

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : re fclean clean all
