# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 11:07:11 by sthiagar          #+#    #+#              #
#    Updated: 2024/04/25 16:13:23 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo

SRCS_DIR = 	srcs/
OBJS_DIR = 	objs/

SOURCE = 	philo.c philo_free.c philo_utils.c \
		philo_init.c philo_tests.c philo_time.c philo_fork.c \
		philo_action.c philo_sim.c philo_sim_utils.c\
		philo_action_utils.c

SRCS = 		$(addprefix $(SRCS_DIR), $(SOURCE))
OBJS = 		$(addprefix $(OBJS_DIR), $(SOURCE:.c=.o))

HEADER = 	./philo.h

CC = 		cc
#CFLAGS = 	-g -Wall -Werror -Wextra -fsanitize=thread
CFLAGS = 	-g -Wall -Werror -Wextra

all: 		$(NAME)
$(NAME):	$(OBJS) $(HEADER)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
		mkdir -p $(OBJS_DIR)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJS_DIR)

fclean: 	clean
		rm -rf $(NAME)

re:		fclean all

.phony:		all clean fclean re
