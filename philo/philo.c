/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:09:34 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 11:10:39 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//deadlock avoidance strategies
//i)   avoid circular dependencies
//ii)  resource ordering
//iii) implement timeout
//iv)  careful design

//race condition avoidance strategy
//i) ensure only one thread can access shared resource at a time
//ii) mutex
//iii) sephamores
//iv) atomic operations

void	*sim_routine(void *ptr)
{
	t_program	*sim;
	int 		i;
	printf("sim_routine\n");
	sim = (t_program *)ptr;
	i = sim->index;
	printf("Created tid [%d]\n",sim->ph[i].tid);
	printf("last meal eaten at [%d]\n",sim->ph[i].last_meal);
	printf("next meal eat at [%d]\n",sim->ph[i].next_meal);
	printf("will die at [%d]\n",sim->ph[i].will_die_at);
	printf("meals eaten [%d]\n",sim->ph[i].num_meals);
	printf("claimed a left fork \n");
	printf("claimed a right fork \n");
	//int	left;
	//int	right;
	/*left = l_fork_index(i, (*sim)->count);
		right = r_fork_index(i, (*sim)->count);
		if ((*sim)->fork[left] == -1 && (*sim)->fork[right] == -1)
		{
			(*sim)->ph[i].l_fork = left;
			(*sim)->fork[right] = i;
			(*sim)->ph[i].r_fork = right;
			(*sim)->fork[left] = i;	
		}
		i++;*/
	return NULL;
}

//eat sleep think eat
int	sim_activity(t_program **sim)
{
	int	i;

	i = 0;
	//create
	while (i < (*sim)->count)
	{
		printf("sim activity for [%d]\n",i);
		(*sim)->ph[i].tid = i;
		pthread_create(&(*sim)->ph[i].td, NULL, sim_routine, (void *)sim);
		i++;
	}
	//i = 0;
	//join
	//while (i < (*sim)->count)//n, 0, 1, 2...n clockwise
	//{
	//	i++;
	//}
	destroy_forks((*sim)->fork, (*sim)->count);
	return(0);
}

int	program_monitor()
{
	//if (time_to_die > current_time - last meal && state != eating)
	//	simulation_end = 1;
	//if (thread1_eat + thread2_eat ... + threadn_eat > total_Eat)
	//	simulation_end = 1;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_program	*sim;
	int		status;	

	sim = (t_program *)malloc(sizeof(t_program) * 1);
	if (sim == NULL)
		return (-1);
	sim->fork = NULL;
	sim->ph = NULL;
	if (argc < 5 || argc > 6)
		return (free_philo(&sim));
	else
	{
		status = init_sim(&sim, argc, argv);
		if (status == -1)
			return (free_philo(&sim));
	}
	//test_print(sim);
	sim_activity(&sim);
	free_philo(&sim);
	return (0);
}	
