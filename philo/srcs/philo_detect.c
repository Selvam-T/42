/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_detect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:23:06 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/14 12:23:22 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	someone_died(t_philo *ph)
{
	pthread_mutex_lock(ph->dlock);
	if (*(ph->info->whodied) >= 0)
	{
		pthread_mutex_unlock(ph->dlock);
		return (1);
	}
	pthread_mutex_unlock(ph->dlock);
	return (0);
}

int	philo_retired(t_philo *ph)
{
	if (ph->info->numeat == -1)
		return (0);
	pthread_mutex_lock(ph->elock);
	if (ph->eaten >= ph->info->numeat)
	{
		pthread_mutex_unlock(ph->elock);
		return (1);
	}
	pthread_mutex_unlock(ph->elock);
	return (0);
}

int	philo_dead(t_philo *ph)
{
	long	time_now;

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	pthread_mutex_lock(ph->nlock);
	if (ph->next_meal < time_now)
	{
		pthread_mutex_unlock(ph->nlock);
		return (1);
	}
	pthread_mutex_unlock(ph->nlock);
	return (0);
}
