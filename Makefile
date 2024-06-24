# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycantin <ycantin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 18:51:44 by ycantin           #+#    #+#              #
#    Updated: 2024/06/06 16:30:32 by ycantin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
NAME = pipex

FLAGS = -Wall -Wextra -Werror -g
CC = cc
RM = rm -f

SRC = pipex_utils.c \
	  error_messages.c \
	  processes.c \
	  main.c \

all:$(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(SRC)
	@$(CC) $(FLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean: 
	@$(RM) $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean:	clean 
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT_DIR)

re:	fclean all 
