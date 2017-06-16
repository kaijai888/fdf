# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzeng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/23 17:30:45 by kzeng             #+#    #+#              #
#    Updated: 2017/03/23 17:30:46 by kzeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAG = -Wall -Wextra -Werror
LINK1 = -L ./src/ -lfdf
LINK2 = -L./minilibx -lmlx -framework OpenGL -framework AppKit

SRC = ./src/main.c

RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	make -C src/
	$(CC) $(FLAG) $(SRC) -o $(NAME) $(LINK1) $(LINK2)

clean:
	make -C src/ clean
	make -C src/ clean

fclean: clean
	$(RM) $(NAME)
	make -C src/ fclean
	make -C src/ fclean

re: fclean all
