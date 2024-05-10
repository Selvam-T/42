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
	if (ph->info->count % 2 == 0)//odd
		usleep(1);
	while (1)
	{
		if (someone_died(ph) == 1)
			break;
		if (philo_eats(ph) == 1) //if -1 then terminate program ***
			break;
		if (philo_sleeps(ph) == 1) //if -1 then terminate program + does not have return 1 to break
			break;
		if (philo_thinks(ph)== 1) //if -1 then terminate program + does not have return 1 to break
			break;	
	}
	return (NULL);
}

void	sim_monitor(t_philo *ph, t_sim *sim) 
{
	int 	i;

	i = 0;
	while (i < sim->count)
	{
		if (is_philo_dead(&ph[i]) == 1)
		{
			pthread_mutex_lock(ph->nlock);
			update_simflags(ph, ph->next_meal);
			pthread_mutex_unlock(ph->nlock);
			break;
		}

		pthread_mutex_lock(sim->alock);
		if (sim->active == 0)
		{
			pthread_mutex_unlock(sim->alock);
			break;
		}
		pthread_mutex_unlock(sim->alock);

		if (i == sim->count)
			i = 0;
	}
	pthread_mutex_lock(sim->dlock);
	if (sim->whodied >= 0)
		printf("%ld ms ph[%d] died.\n",sim->tdied, sim->whodied + 1);
	pthread_mutex_unlock(sim->dlock);	
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
		ph[i].next_meal = get_time_ms() - *tstart + ph[i].info->ttdie;
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