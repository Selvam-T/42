# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 11:07:11 by sthiagar          #+#    #+#              #
#    Updated: 2024/05/13 12:36:30 by sthiagar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		philo

SRCS_DIR = 	srcs/
OBJS_DIR = 	objs/

SOURCE = 	philo.c philo_free.c philo_print.c philo_validate.c\
		philo_init.c philo_time.c philo_fork.c \
		philo_activity.c philo_sim.c philo_activity_utils.c \
		philo_dinner.c philo_detect.c philo_update.c \

SRCS = 		$(addprefix $(SRCS_DIR), $(SOURCE))
OBJS = 		$(addprefix $(OBJS_DIR), $(SOURCE:.c=.o))

HEADER = 	./philo.h

CC = 		cc
#CFLAGS = 	-g -Wall -Werror -Wextra -fsanitize=thread
#CFLAGS = 	-g -Wall -Werror -Wextra -fsanitize=address
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
