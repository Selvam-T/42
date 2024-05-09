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
	
	//I could check if this ph is dead before he picks his forks
	
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	return (print_ifalive(time_now, ph, msg, 0));// no usleep
}

int		philo_eats(t_philo *ph)//return -1 error, 1 break, 0 no action
{
	int	flag;

	flag = is_philo_dead(ph);
	if (flag == 1 || flag == -1)
		return (flag);

	pthread_mutex_lock(ph->vork1);
	flag = takefork(ph, "has taken fork 1");
	if (flag == 1 || flag == -1)
	{
		pthread_mutex_unlock(ph->vork1);
		return (flag);
	}
	pthread_mutex_unlock(ph->vork1);
	
	pthread_mutex_lock(ph->vork2);
	flag = takefork(ph, "has taken fork 2");
	if (flag == 1 || flag == -1)
	{
		pthread_mutex_unlock(ph->vork2);
		return (flag);
	}
	pthread_mutex_unlock(ph->vork2);

	if (handle_task(ph, ph->info->tteat, "is eating") == 1)
	//if (handle_task2(ph, ph->info->tteat, "is eating", 'e') == 1)
		return (1);

	flag = update_num_meals(ph);
	if (flag == 1 || flag == -1)
		return (flag);

	return (0);
}

int		philo_sleeps(t_philo *ph) //return -1 error, 0 no action
{
	int	flag;

	flag = is_philo_dead(ph);
	if (flag == 1 || flag == -1)
		return (flag);
	return (handle_task(ph, ph->info->tteat, "is sleeping"));
	//return (handle_task2(ph, ph->info->ttsleep, "is sleeping", 's'));
}

int 	philo_thinks(t_philo *ph) //return -1 error, 0 no action
{
	long	time_now;
	int 	flag;

	flag = is_philo_dead(ph);
	if (flag == 1 || flag == -1)
		return (flag);

	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	return (print_ifalive(time_now, ph, "is thinking", 1));// usleep 1 ms
	//return (handle_task2(ph, 1, "is thinking", 't'));
}
