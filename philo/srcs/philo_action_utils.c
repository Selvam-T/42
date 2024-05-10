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

int		print_ifalive(long time, t_philo *ph, char *msg, long tsleep)
{

	if (someone_died(ph) == 1) //return 0 no action, 1 break
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

int 	is_philo_dead(t_philo *ph) // return -1 error, 1 break, 0 no action
{
	long	time_now;

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	pthread_mutex_lock(ph->nlock);
	if  (ph->next_meal < time_now)
	{
		pthread_mutex_unlock(ph->nlock); //LOCK WITHIN LOCK POSSIBLE TROUBLE
		return (1);
	}
	pthread_mutex_unlock(ph->nlock);
	return (0);
}

int 	eating(t_philo *ph)
{
	long	time_now;

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	if (time_now > ph->next_meal)//DO I NEED THIS?
		return (1);
	pthread_mutex_lock(ph->nlock);
	ph->next_meal = time_now + ph->info->ttdie;
	pthread_mutex_unlock(ph->nlock);
	return (print_ifalive(time_now, ph, "is eating", ph->info->tteat));
}

int 	sleeping(t_philo *ph)
{
	long	time_now;
	int 	ret;

	ret = 0;
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	if (time_now + ph->info->ttsleep > ph->next_meal)
	{
		ret = print_ifalive(time_now, ph, "is sleeping", ph->next_meal - time_now);
		update_simflags(ph, ph->next_meal);//FUTURE TIME
		return (ret);
	}
	return (print_ifalive(time_now, ph, "is sleeping", ph->info->ttsleep));
}
