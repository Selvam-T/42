/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:36:27 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 13:42:54 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_fork_claimed(int *fork, int count)
{
	int	i;
	
	i = 0;
	while (i < count)
	{
		printf("\t fork [%d] is claimed by p[%d]\n", i, fork[i]);
		i++;
	}
}

void	test_print(t_program *sim)
{
	int	i;
	
	printf("Philosopher count %d\n",sim->count);
	printf("time to die %d milliseconds\n",sim->ttdie);
	printf("time to eat %d milliseconds\n",sim->tteat);
	printf("time to sleep %d milliseconds\n",sim->ttsleep);
	printf("Number of times Philosophers eat %d\n",sim->numeat);
	printf("Total eat count %d\n",sim->toteatcount);
	printf("Someone died? %d\n",sim->end);
	printf("fork status before claim:\n");
	print_fork_claimed(sim->fork, sim->count);
	printf("mutex print_lock ptr %p\n", (void *)sim->print_lock);
	printf("mutex dead_lock ptr %p\n", (void *)sim->dead_lock);
	i = 0;
	printf("print each thread:\n");
	
	while (i < sim->count)
	{
		printf("==================\n");
		printf("thread id [%d]\n",sim->ph[i].tid);
		printf("eating yes/no [%d]\n",sim->ph[i].eating);
		printf("eat count [%d]\n",sim->ph[i].eat_count);
		printf("eat start time ms? [%d]\n",sim->ph[i].eat_start);
		printf("next meal time ms? [%d]\n",sim->ph[i].next_meal);
		printf("left fork [%d]\n",sim->ph[i].l_fork);
		printf("right fork [%d]\n",sim->ph[i].r_fork);
		i++;
	}
}

void	*threadfn1(void *arg)
{
	if (arg != NULL)
		printf("arg is not NULL\n");
	printf("Hello from the new thread 1!\n");
	return (NULL);
}

void	*threadfn2(void *arg)
{
	if (arg != NULL)
		printf("arg is not NULL\n");
	printf("Hello from the detached thread 2!\n");
	return (NULL);
}

void	*print_time(void *arg)
{
	int	tid;
	struct	timeval currenttime;
	
	tid = *(int *)arg;
	printf("Thread %d started.\n", tid);
	gettimeofday(&currenttime, NULL);

	printf("Current time in secs is %ld\n",currenttime.tv_sec);
	printf("Current time in milliseconds %ld\n",get_time_ms());
	return (NULL);
}

void	*thread_function(void *arg) 
{
	int tid = *(int *)arg;
	printf("Thread %d started.\n", tid);

	// Perform some computation or task
	for (int i = 0; i < 5; ++i) {
	printf("Thread %d is running...\n", tid);
	// Simulate some computation
	for (int j = 0; j < 1000000; ++j) {}
	}

	printf("Thread %d finished.\n", tid);
	return NULL;
	//pthread_exit(NULL);
}

int	sample_thread_simulation(t_program *sim)
{
	int	i;
	
	printf("Main thread started.\n");
	i = 0;
	while (i < sim->count)//n, 0, 1, 2...n clockwise
	{
		pthread_create(&sim->ph[i].td, NULL, print_time, (void *)&sim->ph[i].tid);
		i++;
	}
	i = 0;
	while (i < sim->count)//n, 0, 1, 2...n clockwise
	{
		pthread_join(sim->ph[i].td, NULL);
		i++;
	}
	printf("Main thread finished.\n");
	return 0;
}
