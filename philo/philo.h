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

# define TEST 1

// GLOBAL VARIABLE to rememeber the exit code, the last exit code
// stick the exit code for echo and exit?? 

typedef struct s_philo
{
	pthread_t		td; //thread
	int				tid;//thread id associated with thread
	long			last_meal;//after eat, current time
	long			next_meal;//if cur_time > next meal, then end = 1
	//int			will_die_at;
	int				num_meals;//times this ph has eaten
	//pthread_mutex_t	r_vork;//take addr of vork[i]
	//pthread_mutex_t	l_vork;//take addr of vork[i + 1]
	int				r_vork;//take addr of vork[i]
	int 			l_vork;//take addr of vork[i + 1]
}	t_philo;

typedef struct s_program
{
	int 	count;//number of philosophers
	long	ttdie;//length of time before death
	long	tteat;//length of time to eat
	long	ttsleep;//length of time to sleep
	int		numeat;//max meals each ph eat
	//int	eatremain;//set to ph count, -- as each ph >= numeat
	int		end; //if any ph died, set this to 1
	int 	index;//loop index to assign tid
	
	pthread_mutex_t *vork;//this is array of mutexes
	//pthread_mutex_t *print_lock;//move to program
	//pthread_mutex_t *dead_lock;//move to program
	
	t_philo	*ph;
	
}	t_program;

//philo_utils
int	ft_atoi(const char *nptr);
int	is_positive_digit(int argc, char **argv);
void	mutex_init(t_program **sim);
void	mutex_destroy(t_program **sim);

//philo_threads
void	thread_join(pthread_t thread);

//philo_time
long	get_time_ms();

//philo vork
int	r_vork_index(int i, int count);
int	l_vork_index(int i, int count);

//philo_free
int	destroy_vorks(pthread_mutex_t *vork, int count);
int	free_philo(t_program **sim);
void	handle_error();

//philo_init
int	init_threads(t_program **sim);
int	init_sim(t_program **sim, int argc, char **argv);
pthread_mutex_t *init_vork(int count);

//philo_message
void	print_status(long t, int x, char *msg);

//philo_tests
void	*threadfn1(void *arg);
void	*threadfn2(void *arg);
int		sample_thread_simulation(t_program *ph);
void	test_print(t_program *ph);
void	print_vork_claimed(pthread_mutex_t *vork, int count);

#endif
