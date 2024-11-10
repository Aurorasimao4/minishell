# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimao <asimao@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 08:37:30 by asimao            #+#    #+#              #
#    Updated: 2024/11/10 17:55:45 by asimao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBF = libft.a
PATH_LIBF = libft/
NAME = minishell
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = main.c init/init.c print_error.c print_error2.c\
		echo.c cd.c

OBJ = $(SRC:.c=.o)
LIBS = -lreadline -lncurses

MAKEFLAGS += -s

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

all: $(NAME)
$(NAME) : $(NAME_LIBF) $(OBJ)
				$(CC) $(FLAGS) $(OBJ) $(PATH_LIBF)/libft.a -o $(NAME) $(LIBS)
				@echo "$(GREEN)compilacao concluida :)!$(RESET)"
$(NAME_LIBF):  
			@make -C $(PATH_LIBF)
			@echo "$(GREEN)Executavel gerado: $@$(RESET)"

clean:
				rm -f $(OBJ)
				@make clean -C $(PATH_LIBF)
				@echo "$(RED)Arquivos objeto removidos.$(RESET)"
fclean: clean
				rm -f $(NAME)
				@make fclean -C $(PATH_LIBF)
				@echo "$(RED)Executável removido.$(RESET)"
re: fclean all
.PHONY: all clean fclean re