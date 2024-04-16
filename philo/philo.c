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

void	*claim_fork(void *ptr)
{
	t_program	*sim;
	
	sim = (t_program *)ptr;
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

int	sim_activity(t_program **sim)
{
	int	i;

	mutex_init(sim);
	i = 0;
	//create
	while (i < (*sim)->count)
	{
		(*sim)->ph[i].tid = i;
		pthread_create(&(*sim)->ph[i].td, NULL, claim_fork, (void *)sim);
		i++;
	}
	i = 0;
	//join
	//while (i < (*sim)->count)//n, 0, 1, 2...n clockwise
	//{
	//	i++;
	//}
	mutex_destroy(sim);
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
	//claim_fork(&sim);
	sim_activity(&sim);
	free_philo(&sim);
	return (0);
}	