/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:10:36 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/11 13:10:52 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


int	takefork(t_philo *ph, char *msg)
{
	long	time_now;

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	return (print_ifalive(time_now, ph, msg, 0));
}

int	eating(t_philo *ph)
{
	long	time_now;

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	pthread_mutex_lock(ph->nlock);
	if (time_now > ph->next_meal)
	{
		pthread_mutex_unlock(ph->nlock);
		return (1);
	}
	ph->next_meal = time_now + ph->info->ttdie;
	pthread_mutex_unlock(ph->nlock);
	return (print_ifalive(time_now, ph, "is eating", ph->info->tteat));
}

int	sleeping(t_philo *ph)
{
	int		ret;
	long	time_now;
	long	tsleep;

	ret = 0;
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	pthread_mutex_lock(ph->nlock);
	if (time_now > ph->next_meal)
	{
		pthread_mutex_unlock(ph->nlock);
		return (1);
	}
	else if (time_now + ph->info->ttsleep > ph->next_meal)
	{
		tsleep = ph->next_meal - time_now;
		pthread_mutex_unlock(ph->nlock);
		ret = print_ifalive(time_now, ph, "is sleeping", tsleep);
		update_simflags(ph, ph->next_meal);
		return (ret);
	}
	pthread_mutex_unlock(ph->nlock);
	return (print_ifalive(time_now, ph, "is sleeping", ph->info->ttsleep));
}

int	handle_one_philo(t_philo *ph)
{
	long	time_now;
	long	tsleep;

	time_now = 0;
	printf("%ld ms ph[%d] has taken fork 1\n", time_now, ph->tid + 1);
	tsleep = time_now + ph->info->ttdie;
	usleep2(tsleep);
	printf("%ld ms ph[%d] died\n", tsleep, ph->tid + 1);
	return (0);
}