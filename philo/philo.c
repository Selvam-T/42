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

void	*sim_routine(void *ptr) 
{
	//last meal, next meal, will die at, num meals
	t_program	*sim;
	int 		i;
	
	sim = (t_program *)ptr;
	i = sim->index;//index of ph
	
	//IF NUMEALS >= NUM EAT ---> DETACH_THREAD, RETURN
	
	//MONITOR() will do this. NOT done here
	//IF NEXT MEAL < CURTIME --> LOCK END 
	// END = 1, UNLOCK END
	
	//LOCK RIGHT FORK
	//LOCK LEFT FORK
	//LAST MEAL = GET CUR TIME
	//NEXT MEAL = LASTMEAL + TT DIE
	//WILL DIE AT = NEXT MEAL
	//PRINT EATING
	//NUMMEALS ++
	//EATREMAIN ??? DON'T NEED?
	//USLEEP TTEAT
	//UNLOCK RIGHT FORK
	//UNLOCK LEFT FORK
	//PRINT SLEEPING
	//USLEEP TTSLEEP
	//BALANCE TIME = NEXT MEAL - CUR TIME??? DON'T NEED?
	//PRINT THINKING
	//USLEEP BALANCE TIME???
	
	
	return NULL;
}

int	sim_activity(t_program **sim)
{
	int	i;

	//create thread -->td, tid
	i = 0;
	while (i < (*sim)->count)
	{
		printf("create thread for ph [%d]\n",i);
		(*sim)->ph[i].tid = i;
		if (pthread_create(&(*sim)->ph[i].td, NULL, \
			sim_routine, (void *)sim) != 0)
			return (-1);
		i++;
	}

	//join thread
	i = 0;
	while (i < (*sim)->count)
	{
		printf("join ph [%d]\n",i);
		if (pthread_join((*sim)->ph[i].td, NULL) != 0)
			return (-1);
		i++;
	}
	//destroy_forks((*sim)->fork, (*sim)->count);
	return(0);
}

int	program_monitor()
{
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
