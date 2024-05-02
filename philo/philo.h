/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:10:47 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 11:24:55 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //for memset()
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <errno.h> // for errorno returned by pthread_join();

typedef struct s_sim
{
	int 	count;
	int 	kill;
	int 	active;//init to count, decremented by ph[i] 
}	t_sim;

typedef struct s_mutex
{
	pthread_mutex_t 	*vork;
	pthread_mutex_t 	plock;
	pthread_mutex_t 	klock;
	pthread_mutex_t 	alock;//lock active

}	t_mutex;

typedef struct s_general
{
	int		count;
	long	tstart;
	long	ttdie;//length of time before death
	long	tteat;//length of time to eat
	long	ttsleep;//length of time to sleep
	int		numeat;//max meals each ph eat
	int 	*kill;//each ph[i] can access kill
	int		*active;//each ph[i] can decrement active, when eaten >= numeat
}	t_general;

typedef struct s_philo
{
	pthread_t			td; //thread
	int					tid;//thread id associated with thread
	long				last_meal;//after eat, current time
	long				next_meal;//if cur_time > next meal, then dead = 1
	int 				eaten;//meal counter
	pthread_mutex_t		*r_vork;//represented by vork[i]
	pthread_mutex_t		*l_vork;//represented by vork[i + 1]
	pthread_mutex_t 	*plock;//Lock shared printf()
	pthread_mutex_t 	*klock;//lock when updating KILL
	pthread_mutex_t		*alock;//lock when updating ACTIIVE
	t_general			*info;
}	t_philo;

//philo_free
void	*free_ph(t_philo *ph);
int 	handle_error1(char *msg);
void	*handle_error2(char *msg);
int		destroy_vorks(pthread_mutex_t *vork, int count);
void	free_all(t_philo *ph, t_mutex *mtx, int count);
void	destroy_mutex(t_mutex *mtx, int flag);

//philo_utils
int		ft_atoi(const char *nptr);
int		is_positive_digit(int argc, char **argv);

//philo_fork
int	r_vork_index(int i, int count);
int	l_vork_index(int i, int count);

//philo_tests
void	print_info(t_general *info);
void	print_ph(t_philo *ph, int count);
void	print_mutex_test(t_philo *ph, int count, t_mutex *mut);

//philo_time
long	get_time_ms();

//philo_init
t_philo			*init_threads(t_general *info, t_mutex *mtx, int count);
pthread_mutex_t *init_vorks(int count);
void 			init_general_info(t_general *info, int argc, char **argv, t_sim *fl);
int 			init_mutex(t_mutex *mtx, int count);

//philo_sim
int	sim_activity(t_philo *ph, t_sim *flag, long *tstart);

//philo_sim_utils
void	print_status(long time, t_philo *ph, char *msg);
void	usleep2(long time);
int 	breakif_dead(t_philo *ph);
int 	breakif_lesstime(t_philo *ph, int actv_time);

//philo_action
int		eating(t_philo *ph);
int		sleeping(t_philo *ph);
int 	thinking(t_philo *ph);

#endif
