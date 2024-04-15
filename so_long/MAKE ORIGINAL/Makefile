# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:57:21 by sthiagar          #+#    #+#              #
#    Updated: 2024/01/09 13:40:32 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = 	-g -Wall -Werror -Wextra
NAME = 		so_long
SOURCE = 	map.c map_utils.c so_long.c so_long_utils.c images.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJECT = 	$(patsubst %.c,%.o, $(SOURCE))

HEADERS = 	./so_long.h ./get_next_line/get_next_line.h

LIBFT_MAKEFILE = 	./libft/Makefile
#LIBFT_PATH = libft

MINILIBX_PATH = 	minilibx-linux
MINILIBX_FLAGS = 	-L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm

all:		$(NAME)

$(NAME):	$(OBJECT) $(HEADERS) | minilibx #| libft
		$(CC) $(CFLAGS) $(OBJECT) -o $(NAME) \
		-L$(MINILIBX_PATH) $(MINILIBX_FLAGS) -L./libft -lft

./%.o:		./%c  $(HEADERS) $(LIBFT_MAKEFILE)
		make -C ./libft
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		make -C ./libft clean
		rm -f $(OBJECT)
fclean:	clean
		make -C ./libft fclean
		rm -f $(NAME)

re:		fclean all

minilibx:
		$(MAKE) -C $(MINILIBX_PATH)

#libft:
#		$(MAKE) -C $(LIBFT_PATH)

.PHONY:=	all clean fclean re
