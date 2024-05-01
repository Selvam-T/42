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

void	*sim_routine(void *arg)
{
	t_philo		*ph;
	
	ph = (t_philo *)arg;
	while (1)
	{
		pthread_mutex_lock(ph->klock);
		if (*(ph->info->kill) == 1)//set to 1 by monitor
		{
			printf("ph[%d] kill flag is 1. Break out of loop.\n",ph->tid);
			pthread_mutex_unlock(ph->klock);
			break;
		}
		pthread_mutex_unlock(ph->klock);

		printf("ph[%d] thread begins.\n", ph->tid);

		//1) Check if ttdie is crossed
		if (breakif_dead(ph) == 1)
			break;
		
		//2) Check IF NUMEALS >= NUM EAT
		//detachif_eaten(ph);

		//3) Check if ttdie will be crossed, during length of eatin
		//detachif_lesstime(ph, ph->info->tteat);
		
		//EATING
		eating(ph);
		
		//1) Check if ttdie is crossed
		if (breakif_dead(ph) == 1)
			break;
		//2) Check if ttdie will be crossed, during length of sleeping
		//detachif_lesstime(ph, ph->info->ttsleep);

		//SLEEPING
		sleeping(ph);

		//1) Check if ttdie is crossed
		if (breakif_dead(ph) == 1)
			break;
		//THINKING
		thinking(ph);
	}

	//At this point the simulation is ready to end
	//1) all threads are already detached if ph->actvph == 0
	//or 2) all or some threads need to be detached if ph->dead = 1
	return (NULL);
}

/*void	*sim_monitor(void *ptr)
{
	t_monitor	*mon;
	int			i;
	
	printf("Sim monitor thread \n");
	mon = (t_monitor *)ptr;
	i = 0;
	while (i < mon->ph->info->count)
	{
		printf("sim monitor for ph[%d]\n",i);
		if (mon->ph[i].eaten >= mon->ph[i].info->numeat)
			mon->active -= 1;
		//printf("mon->ph[%d].dead = %d\n", i, mon->ph[i].dead);
		//printf("mon->active = %d\n", mon->active);
		//usleep(50000);
		
		if (mon->ph[i].dead == 1 || mon->active == 0)
		{
			pthread_mutex_lock(mon->klock);
			*(mon->ph[i].kill) = 1;//set kill flag to 1.
			pthread_mutex_unlock(mon->klock);
			break;
		}
		
		i++;
		if (i == mon->ph->info->count)
			i = 0;
	}
	return (NULL);
}*/

int	sim_activity(t_philo *ph, int count, long *tstart)
{
	int 		i;

	*tstart = get_time_ms();
	//PH threads create
	i = 0;
	while (i < count)
	{
		if (pthread_create(&(ph[i].td), NULL, sim_routine, (void *)&(ph[i])) != 0)
			return (-1);
		i++;
	}
	
	// monitoring is done here

	//PH threads join
	i = 0;
	while (i < count)
	{
		if (pthread_join(ph[i].td, NULL) != 0)
			return (-1);
		i++;
	}

	return(0);
}