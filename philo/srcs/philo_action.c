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

int	philo_eats(t_philo *ph)
{
	int	flag;

	//fork 1 block: flag = collect_fork1(ph); if (flag != 0) return (flag);
	/*if (someone_died(ph) == 1)
		return (1);
	pthread_mutex_lock(ph->vork1);
	flag = takefork(ph, "has taken fork 1");
	if (flag == 1 || flag == -1)
	{
		pthread_mutex_unlock(ph->vork1);
		return (flag);
	}*/
	flag = collect_fork1(ph);
	if (flag != 0)
		return (flag);
	//fork 2 block: flag = collect_fork2(ph); if (flag != 0) return (flag);
	/*if (someone_died(ph) == 1)
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
	}*/
	flag = collect_fork2(ph);
	if (flag != 0)
		return (flag);
	//eat block: flag = collect_food(ph); if (flag != 0) return (flag);
	/*if (someone_died(ph) == 1)
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
	}*/
	flag = collect_food(ph);
	if (flag != 0)
		return (flag);
	//update meals block: flag = drop_fork_tally_meal(ph); if (flag != 0) return (flag);
	/*if (someone_died(ph) == 1)
	{
		pthread_mutex_unlock(ph->vork2);
		pthread_mutex_unlock(ph->vork1);
		return (1);
	}
	if (update_num_meals(ph) == 1)
	{
		pthread_mutex_unlock(ph->vork2);
		pthread_mutex_unlock(ph->vork1);
		return (1);
	}
	pthread_mutex_unlock(ph->vork2);
	pthread_mutex_unlock(ph->vork1);*/
	flag = drop_fork_tally_meal(ph); 
	if (flag != 0)
		return (flag);
	//end
	return (0);
}

int	philo_sleeps(t_philo *ph)
{
	if (someone_died(ph) == 1)
		return (1);
	return (sleeping(ph));
}

int	philo_thinks(t_philo *ph)
{
	long	time_now;

	if (someone_died(ph) == 1)
		return (1);
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	return (print_ifalive(time_now, ph, "is thinking", 0));
}
