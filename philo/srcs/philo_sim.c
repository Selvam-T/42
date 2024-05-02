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
			pthread_mutex_unlock(ph->klock);
			break;
		}
		pthread_mutex_unlock(ph->klock);
		//1) Check if DIED
		if (breakif_dead(ph) == 1) //if -1 then terminate program
			break;
		
		//2) Check count of MEALS eaten inside eating()

		//3) Check if ttdie will be crossed, while eating
		if (breakif_lesstime(ph, ph->info->tteat) == 1) //if -1 then terminate program
			break;
		//EATING
		if (eating(ph) == 1) //if -1 then terminate program
			break;
		
		//1) Check if DIED
		if (breakif_dead(ph) == 1) //if -1 then terminate program
			break;
		//2) Check if ttdie will be crossed, while sleeping
		if (breakif_lesstime(ph, ph->info->ttsleep) == 1) //if -1 then terminate program
			break;
		//SLEEPING
		sleeping(ph); //if -1 then terminate program

		//1) Check if DIED
		if (breakif_dead(ph) == 1) //if -1 then terminate program
			break;
		//THINKING
		thinking(ph); //if -1 then terminate program
	}
	//At this point thread has ended.
	return (NULL);
}

void	sim_monitor(t_philo *ph, t_sim	*sim)
{
	int 	i;

	i = 0;
	while (i < sim->count)
	{
		pthread_mutex_lock(ph->alock);
		if (sim->active == 0)
		{
			printf("All ph have eaten. so kill simulation\n"); //DELETE
			pthread_mutex_lock(ph->klock);
			sim->kill = 1;
			pthread_mutex_unlock(ph->klock);
			break;
		}
		pthread_mutex_unlock(ph->alock);
		i++;
		if (i == sim->count)
			i = 0;
	}

}

int	sim_activity(t_philo *ph, t_sim *sim, long *tstart)// return -1 error, 0 no action
{
	int 		i;

	*tstart = get_time_ms();
	if (*tstart == -1)
		return (-1);
	
	//PH threads create
	i = 0;
	while (i < sim->count)
	{
		if (pthread_create(&(ph[i].td), NULL, sim_routine, (void *)&(ph[i])) != 0)
			return (-1);
		i++;
	}
	
	sim_monitor(ph, sim);

	//PH threads join
	i = 0;
	while (i < sim->count)
	{
		if (pthread_join(ph[i].td, NULL) != 0)
			return (-1);
		i++;
	}

	return(0);
}