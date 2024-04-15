# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/10 13:36:11 by sthiagar          #+#    #+#              #
#    Updated: 2024/04/08 15:45:49 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc =	cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = minishell
SOURCE = minishell.c wildcard.c builtin_cmd_utils.c print.c\
	input_parser.c memory_mgmt.c echo.c builtin_cmd.c \
	cd.c env_variable.c pwd.c env.c export.c unset.c\
	input_reformat_utils.c struct_conv_utils.c validate.c cleanup.c\
	env_variable_utils.c file.c input_parser_utils.c wildcard_utils.c\
	validate_utils.c input_reformat.c\

OBJECT	= ./$(SOURCE:.c=.o)
HEADER = ./minishell.h

LIBFT_MAKEFILE = ./libft/Makefile

all:	$(NAME)

$(NAME):	$(OBJECT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECT) -lreadline -L./libft -lft

$(OBJECT):	%.o : %.c $(HEADER) $(LIBFT_MAKEFILE)
	make -C ./libft
	$(CC) $(CFLAGS) -c $< -o $@ -I./libft

clean:
	make -C ./libft clean
	rm -f $(OBJECT)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
