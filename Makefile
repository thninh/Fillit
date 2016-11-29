# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thninh <thninh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 22:26:18 by thninh            #+#    #+#              #
#    Updated: 2016/11/29 11:14:56 by thninh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= ./algo.c \
		 ./tools.c \
		 ./check_tetris.c \
		 ./create_tetris.c \
		 ./grid_op.c \
		 ./main.c \
		 ./read_file.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

CC		= gcc

HEADER	= ./fillit.h

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(CFLAGS) -c $(SRC) -I $(HEADER)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./libft -lft

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@make -C libft clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
