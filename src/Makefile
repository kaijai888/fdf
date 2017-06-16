# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kzeng <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 17:30:45 by kzeng             #+#    #+#              #
#    Updated: 2017/04/19 17:30:46 by kzeng            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfdf.a
CC = gcc
FLAG = -c -Wall -Wextra -Werror

SRC = ft_draw.c \
		ft_draw2.c \
		ft_draw3.c \
		ft_draw_handler.c \
		ft_helper.c \
		ft_helper2.c \
		ft_helper3.c \
		ft_parse_input.c \
		ft_printf.c \
		get_next_line.c \

OBJ = $(SRC:.c=.o)

INC = -I fdf.h
AR = ar rc
RM = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(FLAG) $(INC) -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
