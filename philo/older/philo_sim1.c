/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:12:29 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/22 12:12:47 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*sim_routine(void  *ptr)//thread function
{
	int 		i;
	long		timerm;
	t_program	*sim;
	
	sim = (t_program *)ptr;
	i = sim->index;//index of CURRENT ph

	while (1)
	{
		//IF NUMEALS >= NUM EAT ---> DETACH_THREAD, RETURN
		printf("i [%d], tid [%d], num_meals [%d] \n", i, sim->ph[i].tid,\
			sim->ph[i].num_meals);
		if (sim->ph[i].num_meals >= sim->numeat)
		{
			printf("num meals [%d] >= num eat [%d]. Detach ph[%d], tid [%d]\n", \
				sim->ph[i].num_meals, sim->numeat, i, sim->ph[i].tid);
			pthread_detach(sim->ph[i].td);
			return (NULL); //exit? ERROR HANDLE
		}
		else
			printf("num meals [%d] != num eat [%d] for ph[%d], tid [%d]\n", \
				sim->ph[i].num_meals, sim->numeat, i, sim->ph[i].tid);
		//EATING
		eating(sim, i);
		
		//SLEEPING
		//print_status(sim, get_time_ms(), sim->ph[i].tid, "is sleeping");
		print_status2(sim, get_time_ms(), sim->ph[i].tid, "is sleeping", \
			sim->ph[i].num_meals);//DELETE
		usleep(sim->ttsleep * 1000);

		//THINKING
		timerm = sim->ph[i].next_meal - get_time_ms();
		//print_status(sim, get_time_ms(), sim->ph[i].tid, "is thinking");
		print_status2(sim, get_time_ms(), sim->ph[i].tid, "is thinking", \
			sim->ph[i].num_meals);//DELETE
		usleep(timerm * 1000);
	}
	return (NULL);
}

int	sim_monitor(t_program *sim, int i)
{
	(void)sim;
	
	if (sim->ph[i].next_meal < get_time_ms()) //his ttdie exceeded
	{
		//lock mutex to dead
		pthread_mutex_lock(&sim->dead_lock);
			sim->dead = 1;
		pthread_mutex_unlock(&sim->dead_lock);
	}
	//if (sim->dead = 1)
		//END SIMULATION
		//FREE EVERYTHING

	return (0);
}

int	sim_activity(t_program *sim)
{
	int	i;

	i = 0;
	while (i < sim->count)
	{
		//printf("create thread for ph [%d]\n",i);
		sim->ph[i].tid = i;
		sim->index = i;
		if (pthread_create(&sim->ph[i].td, NULL, \
			sim_routine, (void *)sim) != 0)
			return (-1);
		i++;
	}
	
	//while (1)
	//	sim_monitor(sim);
	//	go over each ph[i]->end; if set to 1 then end
	//how to detect all threads have detached?

	//join thread
	i = 0;
	while (i < sim->count)
	{
		//printf("join ph [%d]\n",i);
		if (pthread_join(sim->ph[i].td, NULL) != 0)
			return (-1);
		i++;
	}
	return(0);
}
