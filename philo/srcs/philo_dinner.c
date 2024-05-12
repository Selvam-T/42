/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:31:35 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/10 14:31:50 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	collect_fork1(t_philo *ph)
{
	int	flag;

	if (someone_died(ph) == 1)
		return (1);
	pthread_mutex_lock(ph->vork1);
	flag = takefork(ph, "has taken fork 1");
	if (flag != 0)
	{
		pthread_mutex_unlock(ph->vork1);
		return (flag);
	}
	return (0);
}

int	collect_fork2(t_philo *ph)
{
	int	flag;

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
	return (0);
}

int	collect_food(t_philo *ph)
{
	int	flag;

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
	return (0);
}

int	drop_fork_tally_meal(t_philo *ph)
{
	if (someone_died(ph) == 1)
	{
		pthread_mutex_unlock(ph->vork2);
		pthread_mutex_unlock(ph->vork1);
		return (1);
	}
	//if (update_num_meals(ph) == 1)//REPLACE
	if (update_num_meals(ph, get_time_ms() - ph->info->tstart) == 1)//DELETE
	{
		pthread_mutex_unlock(ph->vork2);
		pthread_mutex_unlock(ph->vork1);
		return (1);
	}
	pthread_mutex_unlock(ph->vork2);
	pthread_mutex_unlock(ph->vork1);
	return (0);
}
