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
	if (ph->tid % 2 != 0)
		usleep(1000);
	while (1)
	{
		if (philo_eats(ph) == 1)
			break ;
		if (philo_sleeps(ph) == 1)
			break ;
		if (philo_thinks(ph) == 1)
			break ;
	}
	return (NULL);
}

void	sim_monitor(t_philo *ph, t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->count)
	{
		pthread_mutex_lock(sim->alock);
		if (sim->active == 0)
		{
			pthread_mutex_unlock(sim->alock);
			break ;
		}
		pthread_mutex_unlock(sim->alock);
		if ((philo_retired(&ph[i]) != 1) && (philo_dead(&ph[i]) == 1))
		{
			pthread_mutex_lock(ph[i].nlock);
			update_simflags(&ph[i], ph[i].next_meal);
			pthread_mutex_unlock(ph[i].nlock);
			break ;
		}
		i++;
		if (i == sim->count)
			i = 0;
	}
}

int	start_threads(t_philo *ph, t_sim *sim)
{
	int	i;

	ph->info->tstart = get_time_ms();
	if (ph->info->tstart == -1)
		return (-1);
	i = 0;
	while (i < sim->count)
	{
		pthread_mutex_lock(ph[i].nlock);
		ph[i].next_meal = get_time_ms() - ph[i].info->tstart + ph[i].info->ttdie;
		pthread_mutex_unlock(ph[i].nlock);
		if (pthread_create(&(ph[i].td), NULL, sim_routine, \
			(void *)&(ph[i])) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	join_threads(t_philo *ph, t_sim *sim)
{
	int	i;

	i = 0;
	while (i < sim->count)
	{
		if (pthread_join(ph[i].td, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	run_simulation(t_philo *ph, t_sim *sim)
{
	if (sim->count == 1)
		return (handle_one_philo(ph));
	
	if (start_threads(ph, sim) == -1)
		return (-1);
	sim_monitor(ph, sim);
	pthread_mutex_lock(sim->dlock);
	if (sim->whodied >= 0)
		printf("%ld ms ph[%d] died.\n", sim->tdied, sim->whodied + 1);
	pthread_mutex_unlock(sim->dlock);
	if (join_threads(ph, sim) == -1)
		return (-1);
	return (0);
}
