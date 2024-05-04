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
		if (philo_isdead(ph) == 1)
			break;
		// eat 
		if (philo_eats(ph) == 1) //if -1 then terminate program ***
			break;
		// sleep
		if (philo_sleeps(ph) == 1) //if -1 then terminate program + does not have return 1 to break
			break;
		// think
		if (philo_thinks(ph)== 1) //if -1 then terminate program + does not have return 1 to break
			break;	
	}
	return (NULL);
}

/*
void	sim_monitor(t_philo *ph, t_sim *sim) //possible DELETE
{
	int 	i;

	i = 0;
	while (i < sim->count)
	{
		pthread_mutex_lock(ph->dlock);
		if (sim->kill == 1)
		{
			if (*(ph->info->whodied) != -1)
			{
				pthread_mutex_lock(ph->plock);
				printf("%ld ms [%d] died\n",get_time_ms() - ph->info->tstart, *(ph->info->whodied));
				pthread_mutex_unlock(ph->plock);
			}
			pthread_mutex_unlock(ph->dlock);
			break;
		}
		pthread_mutex_unlock(ph->dlock);

		pthread_mutex_lock(ph->alock);
		if (sim->active == 0)
		{
			pthread_mutex_unlock(ph->alock);
			break;
		}
		pthread_mutex_unlock(ph->alock);
		i++;
		if (i == sim->count)
			i = 0;
	}

}*/

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
	
	//sim_monitor(ph, sim);
	
	if (*(ph->info->whodied) == -1) //DELETE for testing only
		printf("Simulation ended, all eaten.\n"); //DELETE for testing only
	else
		printf("%ld ms ph[%d] is dead",sim->tdied, sim->whodied);

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