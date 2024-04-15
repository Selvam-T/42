# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 11:07:11 by sthiagar          #+#    #+#              #
#    Updated: 2024/02/04 11:09:19 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = 		cc
CFLAGS = 	-g -Wall -Werror -Wextra

NAME = 		philo
SOURCE = 	philo.c philo_error.c philo_utils.c philo_message.c \
		philo_time.c philo_init.c philo_tests.c philo_threads.c \
	
OBJECT =	$(patsubst %.c, %.o, $(SOURCE))
HEADER = 	./philo.h

all: 		$(NAME)
$(NAME):	$(OBJECT) $(HEADER)
		$(CC) $(CFLAGS) $(OBJECT) -o $(NAME) 

./%.o:		./%.c -l./
		$(CC) $(CFLAGS) -c $< -o $@
	
clean:
		rm -f $(OBJECT)

fclean: 	clean
		rm -f $(NAME)

re:		fclean all

.phony:		all clean fclean re
