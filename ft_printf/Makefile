# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 14:14:33 by sthiagar          #+#    #+#              #
#    Updated: 2023/10/02 15:15:16 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
#NAME = a.out
SOURCE = ft_printf.c ft_putchar.c ft_putstr.c ft_putint.c ft_putnbr.c\
				 ft_hexadecimal.c ft_strlen.c ft_ptraddress.c\
#				 main.c\

OBJECT = ./$(SOURCE:.c=.o)
HEADER = ./ft_printf.h

all: $(NAME)

$(NAME):	$(OBJECT) $(HEADER)
	ar rcs $(NAME) $(OBJECT)
#	$(CC) $(CFLAGS) $(OBJECT) -o $(NAME)

./$.o:	./$.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

#./$(OBJECT): ./$(SOURCE)
#	$(CC) $(CFLAGS) -c $(SOURCE) -o $(OBJECT)

clean:
	rm -f $(OBJECT)
fclean: clean
	rm -f $(NAME)
re:	fclean all
.PHONY:=	all clean fclean re
