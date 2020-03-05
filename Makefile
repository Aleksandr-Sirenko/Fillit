# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asirenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/26 18:33:38 by asirenko          #+#    #+#              #
#    Updated: 2018/11/29 21:37:47 by asirenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c backtrack.c chains.c get_next_line.c map.c save.c solve.c \
	 validate.c 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@gcc $(CFLAGS) $(OBJ) -o $(NAME) -l ft -I libft -L libft

%.o: %.c
	@gcc $(CFLAGS) -c $< -o $@ -I libft

clean:
	@rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all
