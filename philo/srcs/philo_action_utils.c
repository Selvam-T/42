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

void	print_status(long time, t_philo *ph, char *msg)
{
	pthread_mutex_lock(ph->plock);
		printf("%ld ms ph[%d] %s\n", time, ph->tid + 1, msg);
	pthread_mutex_unlock(ph->plock);
}

void	update_simflags(t_philo *ph)
{
	pthread_mutex_lock(ph->klock);
	*(ph->info->kill) = 1;
	*(ph->info->whodied) = ph->tid;
	pthread_mutex_unlock(ph->klock);
}

int 	breakif_dead(t_philo *ph) // return -1 error, 1 break, 0 no action
{
	long	curtime;

	curtime = get_time_ms() - ph->info->tstart;
	if (curtime < 0)
		return (-1);
	if  (ph->next_meal < curtime)
	{
		update_simflags(ph);
		return (1);
	}
	return (0);
}

int 	breakif_lesstime(t_philo *ph, long ttact, char *msg)
{
	long	time_now;
	long	tsleep;
	int		ret;

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);

	tsleep = ttact; //tteat or ttsleep
	ret = 0;
	if (time_now + ttact > ph->next_meal)
	{
		tsleep = ph->next_meal - time_now;
		update_simflags(ph);
		ret = 1;
	}
	if (msg[4] == 'e')
		ph->next_meal = time_now + ph->info->tteat;//only for eating
	print_status(time_now, ph, msg);
	usleep(tsleep);
	return (ret);
}