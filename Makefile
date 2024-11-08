# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimao <asimao@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/08 08:37:30 by asimao            #+#    #+#              #
#    Updated: 2024/11/08 12:40:59 by asimao           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_LIBF = libft.a
PATH_LIBF = libft/
NAME = minishell
CFLAGS = -Wall -Wextra -Werror
CC = cc
SRC = main.c init/init.c print_error.c print_error2.c

OBJ = $(SRC:.c=.o)
LIBS = -lreadline -lncurses

all: $(NAME)
$(NAME) : $(NAME_LIBF) $(OBJ)
				$(CC) $(FLAGS) $(OBJ) $(PATH_LIBF)/libft.a -o $(NAME) $(LIBS)
$(NAME_LIBF):  
			@make -C $(PATH_LIBF)
clean:
				rm -f $(OBJ)
				@make clean -C $(PATH_LIBF)
fclean: clean
				rm -f $(NAME)
				@make fclean -C $(PATH_LIBF)
re: fclean all
.PHONY: all clean fclean re