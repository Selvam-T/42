# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 14:02:39 by sthiagar          #+#    #+#              #
#    Updated: 2023/12/17 14:02:44 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

NAME = pipex
SOURCE = pipex.c pipex_utils.c
OBJECT = $(patsubst %.c,%.o, $(SOURCE))
HEADER = ./pipex.h

LIBFT_MAKEFILE = ./libft/Makefile

all: $(NAME)

$(NAME):	$(OBJECT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECT) -L./libft -lft

$(OBJECT):	%.o : %.c $(HEADER) $(LIBFT_MAKEFILE)
	make -C ./libft
	$(CC) $(CFLAGS) -c $< -o $@ -I./libft
	
#$(OBJECT):	$(SOURCE) $(HEADER) $(LIBFT_MAKEFILE)
#	make -C ./libft
#	$(CC) $(CFLAGS) -c $(SOURCE) -I./libft -o $(OBJECT)

clean:
	make -C ./libft clean
	rm -f $(OBJECT)

fclean: clean
		make -C ./libft fclean
		rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
