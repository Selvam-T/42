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
	if (ph->next_meal == -1)
		ph->next_meal = get_time_ms() - ph->info->tstart + ph->info->ttdie;
	while (1)
	{
		if (someone_died(ph) == 1)
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
	//printf("ph[%d] thread is exiting.\n",ph->tid);
	return (NULL);
}

void	sim_monitor(t_sim *sim) 
{

	while (1)
	{

		//printf("sim B4 dlock addr: %p to Death MONITOR **************\n",&sim->dlock);
		pthread_mutex_lock(sim->dlock);
		if (sim->whodied >= 0)
		{
			pthread_mutex_unlock(sim->dlock);
			//printf("sim AFT dlock addr: %p to Death MONITOR **************\n",&sim->dlock);
			printf("%ld ms ph[%d] died.\n",sim->tdied, sim->whodied);
			break;
		}
		pthread_mutex_unlock(sim->dlock);
		//printf("sim AFT dlock addr: %p to Death MONITOR **************\n",&sim->dlock);

		//printf("sim B4 alock addr: %p to Active MONITOR **************\n",&sim->alock);
		pthread_mutex_lock(sim->alock);
		if (sim->active == 0)
		{
			pthread_mutex_unlock(sim->alock);
			//printf("sim AFT alock addr: %p to Active MONITOR **************\n",&sim->alock);
			printf("All ph eaten. simulation ended.\n"); //DELETE
			break;
		}
		pthread_mutex_unlock(sim->alock);
		//printf("sim AFT alock addr: %p to Active MONITOR **************\n",&sim->alock);
	}
}

int 	handle_one_philo(t_philo *ph)
{
	long	time_now;
	long	tsleep;

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	printf("%ld ms ph[%d] has taken fork 1\n", time_now, ph->tid + 1);
	tsleep = time_now + ph->info->ttdie;
	usleep2(tsleep);
	printf("%ld ms ph[%d] died\n", tsleep, ph->tid + 1);
	return (0);
}

int	sim_activity(t_philo *ph, t_sim *sim, long *tstart)// return -1 error, 0 no action
{
	int 		i;

	*tstart = get_time_ms();
	if (*tstart == -1)
		return (-1);

	if (sim->count == 1)
		return (handle_one_philo(ph));

	i = 0;
	while (i < sim->count)
	{
		if (pthread_create(&(ph[i].td), NULL, sim_routine, (void *)&(ph[i])) != 0)
			return (-1);
		i++;
	}

	sim_monitor(sim);

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