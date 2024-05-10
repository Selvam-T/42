/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:29:03 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/03 16:29:17 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	update_num_meals(t_philo *ph)
{
	if (ph->info->numeat != -1)
	{
		ph->eaten += 1;
		if (ph->eaten >= ph->info->numeat)
		{
			pthread_mutex_lock(ph->alock);
			*(ph->info->active) -= 1;
			pthread_mutex_unlock(ph->alock);
			return (1);
		}
	}
	return (0);
}

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
	if (time_now > ph->next_meal)
		return (1);
	pthread_mutex_lock(ph->nlock);
	ph->next_meal = time_now + ph->info->ttdie;
	pthread_mutex_unlock(ph->nlock);
	return (print_ifalive(time_now, ph, "is eating", ph->info->tteat));
}

int	sleeping(t_philo *ph)
{
	int		ret;
	long	time_now;

	ret = 0;
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	if (time_now + ph->info->ttsleep > ph->next_meal)
	{
		ret = print_ifalive(time_now, ph, "is sleeping", \
			ph->next_meal - time_now);
		update_simflags(ph, ph->next_meal);
		return (ret);
	}
	return (print_ifalive(time_now, ph, "is sleeping", ph->info->ttsleep));
}
