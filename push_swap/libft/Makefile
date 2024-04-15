# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 11:25:38 by sthiagar          #+#    #+#              #
#    Updated: 2023/09/22 13:39:53 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SOURCE = ft_isdigit.c ft_atoi.c ft_lstnew.c ft_lstlast.c\
	ft_lstadd_back.c ft_lstadd_front.c ft_strlen.c\
	ft_is_strdigit.c ft_strncmp.c ft_split.c ft_strchr.c\
	ft_calloc.c ft_substr.c ft_bzero.c ft_memcpy.c

OBJECT = ./$(SOURCE:.c=.o)
HEADER = ./libft.h

all: $(NAME)

$(NAME):	$(OBJECT)
			ar rc $(NAME) $(OBJECT)

./%.o: ./%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJECT)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:= all clean fclean re
