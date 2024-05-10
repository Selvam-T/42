/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:42:10 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/22 13:42:26 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int 	update_num_meals(t_philo *ph)//return 1 break, 0 no action
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

int 	takefork(t_philo *ph, char *msg) //return -1 error, 1 break, 0 no action
{
	long	time_now;
	
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	return (print_ifalive(time_now, ph, msg, 0));// no usleep
}

int		philo_eats(t_philo *ph)//return -1 error, 1 break, 0 no action
{
	int	flag;

	if (someone_died(ph) == 1)
		return (1);

	pthread_mutex_lock(ph->vork1);
	flag = takefork(ph, "has taken fork 1");
	if (flag == 1 || flag == -1)
	{
		pthread_mutex_unlock(ph->vork1);
		return (flag);
	}

	if (someone_died(ph) == 1)
	{
		pthread_mutex_unlock(ph->vork1);
		return (1);
	}
	
	pthread_mutex_lock(ph->vork2);
	flag = takefork(ph, "has taken fork 2");
	if (flag == 1 || flag == -1)
	{
		pthread_mutex_unlock(ph->vork2);
		pthread_mutex_unlock(ph->vork1);
		return (flag);
	}

	if (someone_died(ph) == 1)
	{
		pthread_mutex_unlock(ph->vork2);
		pthread_mutex_unlock(ph->vork1);
		return (1);
	}

	flag = eating(ph);
	if (flag == 1 || flag == -1)
	{
		pthread_mutex_unlock(ph->vork2);
		pthread_mutex_unlock(ph->vork1);
		return (flag);
	}

	if (update_num_meals(ph) == 1)
	{
		pthread_mutex_unlock(ph->vork2);
		pthread_mutex_unlock(ph->vork1);
		return (1);
	}
	pthread_mutex_unlock(ph->vork2);
	pthread_mutex_unlock(ph->vork1);
	return (0);
}

int		philo_sleeps(t_philo *ph) //return -1 error, 0 no action
{
	if (someone_died(ph) == 1)
		return (1);
	return (sleeping(ph));
}

int 	philo_thinks(t_philo *ph) //return -1 error, 0 no action
{
	long	time_now;
	
	if (someone_died(ph) == 1)
		return (1);

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	return (print_ifalive(time_now, ph, "is thinking", 0));// usleep 1 ms
}
