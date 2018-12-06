# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgerber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 10:48:12 by mgerber           #+#    #+#              #
#    Updated: 2018/07/28 14:32:54 by mgerber          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = poseidon.filler
SRCS = ./srcs/*.c
INC = -I ./includes/
CC = gcc -o
CFLAGS = -Wall -Wextra -Werror

$(NAME):
	@make -C ./libft/
	@mv ./libft/libft.a .
	@$(CC) $(NAME) $(SRCS) $(CFLAGS) $(INC) libft.a
	@mv poseidon.filler resources/players

all: $(NAME)

clean:
	@make clean -C ./libft/

fclean: clean
	@make fclean -C ./libft/
	@rm -rf libft.a
	@rm -rf $(NAME)

re: fclean all
