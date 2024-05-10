/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:06:31 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/10 14:07:32 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_ifalive(long time, t_philo *ph, char *msg, long tsleep)
{
	if (someone_died(ph) == 1)
		return (1);
	pthread_mutex_lock(ph->plock);
	printf("%ld ms ph[%d] %s [will die at %ld] [eaten %d]\n", \
		time, ph->tid + 1, msg, ph->next_meal, ph->eaten);
	pthread_mutex_unlock(ph->plock);
	usleep2(tsleep);
	return (0);
}

void	update_simflags(t_philo *ph, long tdied)
{
	pthread_mutex_lock(ph->dlock);
	*(ph->info->whodied) = ph->tid;
	*(ph->info->tdied) = tdied;
	pthread_mutex_unlock(ph->dlock);
}

int	is_philo_dead(t_philo *ph)
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
