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

NAME = 			cub3D

SRCS_DIR = 		srcs/
OBJS_DIR = 		objs/
SRC =			cub3D.c image.c free.c init.c

SRCS = 			$(addprefix $(SRCS_DIR), $(SRC))
OBJS = 			$(addprefix $(OBJS_DIR), $(SRC:.c=.o))

HEADERS = 		./incs/cub3D.h 

LIBFT_MAKEFILE = 	./libft/Makefile

MINILIBX_PATH = 	minilibx-linux
MINILIBX_FLAGS = 	-L$(MINILIBX_PATH) -lmlx -lXext -lX11 -lm
CC = 			cc
CFLAGS = 		-Wall -Werror -Wextra

all:			$(NAME)

$(NAME):		$(OBJS) $(HEADERS)
			test -d minilibx-linux && $(MAKE) -C minilibx-linux || true
			test -f libft/libft.a && true || $(MAKE) -C libft
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME) \
			-L$(MINILIBX_PATH) $(MINILIBX_FLAGS) -L./libft -lft

$(OBJS_DIR)%.o: 	$(SRCS_DIR)%.c $(HEADERS) $(LIBFT_MAKEFILE)
			mkdir -p $(OBJS_DIR)
			make -C ./libft
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			make -C ./libft clean
			rm -f $(OBJS)
fclean:			clean
			make -C ./libft fclean
			rm -f $(NAME)

re:			fclean all

minilibx:
			$(MAKE) -C $(MINILIBX_PATH)

libft:
			make -C ./libft

.PHONY:=		all clean fclean re
