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
SOURCE = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
				 ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c\
				 ft_strlcpy.c ft_strlcat.c ft_toupper.c\
				 ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
				 ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
				 ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_putchar_fd.c\
				 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strtrim.c\
				 ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
				ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
				ft_lstmap.c

OBJECT = ./$(SOURCE:.c=.o)
B_OBJECT = ./$(BONUS:.c=.o)
HEADER = ./libft.h

all: $(NAME)

$(NAME):	$(OBJECT)
			ar rc $(NAME) $(OBJECT)

bonus: $(OBJECT) $(B_OBJECT)
		ar rc $(NAME) $(OBJECT) $(B_OBJECT)

./%.o: ./%.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJECT) $(B_OBJECT)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY:= all clean fclean re bonus
