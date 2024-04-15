# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 19:28:59 by sthiagar          #+#    #+#              #
#    Updated: 2024/01/29 13:43:04 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = 		gcc
CFLAGS = 	-g -Wall -Wextra -Werror

NAME = 		push_swap
SOURCE = 	push_swap.c push_swap_utils.c push_swap_ops.c \
		push_swap_ops_utils.c \
		ps_sort6.c ps_sort3.c \
		ps_multisort.c ps_multisort_costs.c \
		ps_multisort_utility.c ps_multisort_moves.c

OBJECT = 	$(patsubst %.c, %.o, $(SOURCE))
HEADER = 	./push_swap.h

LIBFT_MAKEFILE = ./libft/Makefile

all:		$(NAME)

$(NAME):	$(OBJECT)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJECT) -L./libft -lft

$(OBJECT):	%.o : %.c $(HEADER) $(LIBFT_MAKEFILE)
		make -C ./libft
		$(CC) $(CFLAGS) -c $< -o $@ -I./libft

clean:
		make -C ./libft clean
		rm -f $(OBJECT)

fclean:		clean
		make -C ./libft fclean
		rm -f $(NAME)

re:		fclean all

.phony:=	all clean fclean re
