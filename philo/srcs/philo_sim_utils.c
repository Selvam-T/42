/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:15:41 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/24 17:15:56 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	usleep2(long time)
{
	int	x;
	int	i;

	x = time / 100;
	i = 0;
	while(i < x)
	{
		usleep(1000);
		i++;
	}
}

void	print_status(long time, t_philo *ph, char *msg)
{
	pthread_mutex_lock(ph->plock);
		printf("%ld ms ph[%d] %s\n", time, ph->tid + 1, msg);
	pthread_mutex_unlock(ph->plock);
}

int 	breakif_dead(t_philo *ph) // return -1 error, 1 break, 0 no action
{
	long	curtime;

	curtime = get_time_ms() - ph->info->tstart;
	if (curtime < 0)
		return (-1);
	if  (ph->next_meal < curtime)
	{
		pthread_mutex_lock(ph->klock);
		*(ph->info->kill) = 1;
		pthread_mutex_unlock(ph->klock);
		return (1);
	}
	return (0);
}

int 	breakif_lesstime(t_philo *ph, int actv_time)// return -1 error, 1 break, 0 no action
{
	long	curtime;

	curtime = get_time_ms() - ph->info->tstart;
	if (curtime == -1)
		return (-1);//error in c lib time function
	
	//where 'actv_time' is tteat or ttsleep depending on eating() or sleeping()
	if (curtime + actv_time < ph->next_meal)
		usleep(actv_time);
	else
	{
		usleep(ph->next_meal - curtime);
		pthread_mutex_lock(ph->klock);
		*(ph->info->kill) = 1;
		pthread_mutex_unlock(ph->klock);
		return (1);
	}
	return (0);
}