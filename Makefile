#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtovey <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/27 22:33:18 by vtovey            #+#    #+#              #
#    Updated: 2016/07/27 23:26:12 by vtovey           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = bsq
FILES = ./files/main.c ./files/algo.c ./files/aux.c ./files/error.c
FILESO = main.o algo.o aux.o error.o
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(FILES)
	gcc $(FLAGS) $(FILESO) -o $(NAME)

clean:
	rm -f $(FILESO)

fclean: clean
	rm -f $(NAME)

re: fclean all