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

int	claim_fork(t_program **sim)
{
	int	left;
	int	right;
	int	i;

	i = 0;
	while (i < (*sim)->count)//n, 0, 1, 2...n clockwise
	{
		left = l_fork_index(i, (*sim)->count);
		right = r_fork_index(i, (*sim)->count);
	//printf("i is %d, left is %d, right is %d\n",i, left, right);
	//printf("b4 ph left is %d, ph right is %d\n",(*sim)->ph[i].l_fork, (*sim)->ph[i].r_fork);
		if ((*sim)->fork[left] == -1 && (*sim)->fork[right] == -1)
		{
			(*sim)->ph[i].l_fork = left;
			(*sim)->fork[right] = i;
			(*sim)->ph[i].r_fork = right;
			(*sim)->fork[left] = i;	
		}
	printf("ph[%d] left is %d, right is %d\n",i, (*sim)->ph[i].l_fork, (*sim)->ph[i].r_fork);
		i++;
	}
	return(0);
}

int	sim_activity()
{

	return (0);
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

	sim = (t_program *)malloc(sizeof(t_program) * 1);
	if (sim == NULL)
		return (-1);
	if (argc < 5 || argc > 6)
		return (0);
	else
	{
		if(init_sim(&sim, argc, argv) == -2)
			return (free_philo(&sim));
	}
	//test_print(sim);
	claim_fork(&sim);
	//sample_thread_simulation(sim);
	free_philo(&sim);
	return (0);
}	
