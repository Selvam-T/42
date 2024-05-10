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
	int 	active;
	int 	whodied;
	long	tdied;
	pthread_mutex_t 	*dlock;
	pthread_mutex_t		*alock;
}	t_sim;

typedef struct s_mutex
{
	pthread_mutex_t 	*vork;
	pthread_mutex_t 	plock;
	pthread_mutex_t 	dlock;
	pthread_mutex_t 	alock;
	pthread_mutex_t		nlock;

}	t_mutex;

typedef struct s_general
{
	int		count;
	long	tstart;
	long	ttdie;
	long	tteat;
	long	ttsleep;
	int		numeat;
	int		*active;
	int 	*whodied;
	long	*tdied;
}	t_general;

typedef struct s_philo
{
	pthread_t			td;
	int					tid;
	long				next_meal;
	int 				eaten;
	pthread_mutex_t		*vork1;
	pthread_mutex_t		*vork2;
	pthread_mutex_t 	*plock;
	pthread_mutex_t 	*dlock;
	pthread_mutex_t		*alock;
	pthread_mutex_t		*nlock;
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
int 	validated_count(int argc, char **argv);

//philo_fork
int	vork1_index(int i, int count);
int	vork2_index(int i, int count);
int	vork_index(int i, int count, char fork);

//philo_tests
void	print_info(t_general *info);
void	print_ph(t_philo *ph, int count);
void	print_mutex_test(t_philo *ph, int count, t_mutex *mut);
void	print_fork_allocation(t_philo *ph, int count);
void	print_mutex_addr(t_philo *ph, int count, t_mutex *mut);
void	print_sim(t_sim sim);

//philo_time
void	usleep2(long time);
long	get_time_ms();
long	time_now(long tstart);

//philo_init
t_philo			*init_threads(t_general *info, t_mutex *mtx, int count);
pthread_mutex_t *init_vorks(int count);
void 			init_general_info(t_general *info, int argc, char **argv, t_sim *fl);
int 			init_mutex(t_mutex *mtx, int count);
int 			init_sim(t_sim *sim, t_mutex *mtx);

//philo_sim
int	sim_activity(t_philo *ph, t_sim *flag, long *tstart);

//philo_sim_utils
int	someone_died(t_philo *ph);

//philo_action_utils
int		print_ifalive(long time, t_philo *ph, char *msg, long tsleep);
void	update_simflags(t_philo *ph, long tdied);
int 	is_philo_dead(t_philo *ph);
int 	eating(t_philo *ph);
int 	sleeping(t_philo *ph);

//philo_action
int		philo_eats(t_philo *ph);
int		philo_sleeps(t_philo *ph);
int 	philo_thinks(t_philo *ph);

#endif
