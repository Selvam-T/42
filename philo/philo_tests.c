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
	
	printf("\nNumber of Ph: [%d]\n",sim->count);
	printf("time to die [%d] milliseconds\n",sim->ttdie);
	printf("time to eat [%d] milliseconds\n",sim->tteat);
	printf("time to sleep [%d] milliseconds\n",sim->ttsleep);
	printf("each ph eats [%d] times\n",sim->numeat);
	printf("Terminate when total eat count [%d]\n",sim->eatremain);

	printf("fork status before claim:\n");
	print_fork_claimed(sim->fork, sim->count);
	printf("%s \n", sim->end ? "Someone died" : "No one died");
	printf("index to assign tid [%d]\n",sim->index);
	printf("mutex right fork ptr %p\n", (void *)sim->r_fork);
	printf("mutex left fork ptr %p\n", (void *)sim->l_fork);
	printf("mutex print_lock ptr %p\n", (void *)sim->print_lock);
	printf("mutex dead_lock ptr %p\n", (void *)sim->dead_lock);

	printf("print each thread:\n");
	i = 0;
	while (i < sim->count)
	{
		printf("==================\n");
		printf("thread id [%d]\n",sim->ph[i].tid);
		printf("last meal eaten at [%d]\n",sim->ph[i].last_meal);
		printf("next meal eat at [%d]\n",sim->ph[i].next_meal);
		printf("will die at [%d]\n",sim->ph[i].will_die_at);
		printf("meals eaten [%d]\n",sim->ph[i].num_meals);
		printf("claimed a left fork [%d]\n",sim->ph[i].l_fork);
		printf("claimed a right fork [%d]\n",sim->ph[i].r_fork);
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
