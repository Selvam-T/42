/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:10:47 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/10 15:56:15 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>

typedef struct s_sim
{
	int				count;
	int				active;
	int				whodied;
	long			tdied;
	pthread_mutex_t	*dlock;
	pthread_mutex_t	*alock;
}	t_sim;

typedef struct s_mutex
{
	pthread_mutex_t	*vork;
	pthread_mutex_t	plock;
	pthread_mutex_t	dlock;
	pthread_mutex_t	alock;
	pthread_mutex_t	nlock;
	pthread_mutex_t	elock;
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
	int		*whodied;
	long	*tdied;
}	t_general;

typedef struct s_philo
{
	pthread_t		td;
	int				tid;
	long			next_meal;
	int				eaten;
	pthread_mutex_t	*vork1;
	pthread_mutex_t	*vork2;
	pthread_mutex_t	*plock;
	pthread_mutex_t	*dlock;
	pthread_mutex_t	*alock;
	pthread_mutex_t	*nlock;
	pthread_mutex_t	*elock;
	t_general		*info;
}	t_philo;

//philo_free
int				handle_error1(char *msg);
void			*handle_error2(char *msg);
int				destroy_vorks(pthread_mutex_t *vork, int count);
void			free_all(t_philo *ph, t_mutex *mtx, int count);
void			destroy_mutex(t_mutex *mtx, int flag);
//philo_print
int				print_ifalive(long time, t_philo *ph, char *msg, long tsleep);
//philo_verify
int				someone_died(t_philo *ph);
int				philo_dead(t_philo *ph);
int				philo_retired(t_philo *ph);
//philo_update
void			update_simflags(t_philo *ph, long tdied);
int				update_num_meals(t_philo *ph);
//philo_sim
int				run_simulation(t_philo *ph, t_sim *sim);
//philo_fork
int				vork_index(int i, int count, char fork);
//philo_dinner
int				collect_fork1(t_philo *ph);
int				collect_fork2(t_philo *ph);
int				collect_food(t_philo *ph);
int				drop_fork_tally_meal(t_philo *ph);
//philo_activity_utils
int				eating(t_philo *ph);
int				sleeping(t_philo *ph);
int				takefork(t_philo *ph, char *msg);
int				handle_one_philo(t_philo *ph);
//philo_activity
int				philo_eats(t_philo *ph);
int				philo_sleeps(t_philo *ph);
int				philo_thinks(t_philo *ph);
//philo_init
t_philo			*init_philos(t_general *info, t_mutex *mtx, int count);
pthread_mutex_t	*init_vorks(int count);
void			init_general_info(t_general *info, int argc, char **argv, \
					t_sim *fl);
int				init_mutex(t_mutex *mtx, int count);
int				init_sim(t_sim *sim, t_mutex *mtx);
//philo_time
void			usleep2(long time);
long			get_time_ms(void);
long			time_now(long tstart);
//philo_validate
int				ft_atoi(const char *nptr);
int				is_positive_digit(int argc, char **argv);
int				validated_count(int argc, char **argv);
void	print_mutex_addr(t_philo *ph, int count, t_mutex *mut);
#endif
