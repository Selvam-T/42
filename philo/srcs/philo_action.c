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
			pthread_mutex_unlock(ph->vork1);
			pthread_mutex_unlock(ph->vork2);
			return (1); //signal to break from thread
		}
	}
	return (0);
}

int 	takefork(t_philo *ph, char *msg)
{
	long	time_now;
	
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	if (someone_died(ph) == 1) //return 0 no action, 1 break
		return (1);
	print_status(time_now, ph, msg);
	return (0);
}

int		philo_eats(t_philo *ph)//return -1 error, 1 break, 0 no action
{
	if (is_philo_dead(ph) == 1) //if -1 then terminate program ***
		return (1);

	//LOCK right fork
	pthread_mutex_lock(ph->vork1);
	if (takefork(ph, "has taken fork 1") == -1) // or == 1
	{
		pthread_mutex_unlock(ph->vork1);
		return (-1); // return (1);
	}
	//LOCK left fork	
	pthread_mutex_lock(ph->vork2);
	if (takefork(ph, "has taken fork 2") == -1) // or == 1
	{
		pthread_mutex_unlock(ph->vork2);
		return (-1); // return (1);
	}
	
	if (less_time_to_eat(ph, ph->info->tteat, "is eating") == 1)
		return (1);//signal to break from thread

	//NUM_MEALS++
	if (update_num_meals(ph) == 1)
		return (1);//signal to break from thread

	//UNLOCK right and left forks
	pthread_mutex_unlock(ph->vork1);
	pthread_mutex_unlock(ph->vork2);
	return (0);
}

int		philo_sleeps(t_philo *ph) //return -1 error, 0 no action
{
	if (is_philo_dead(ph) == 1) //if -1 then terminate program ***
		return (1);
	return (less_time_to_eat(ph, ph->info->ttsleep, "is sleeping"));
}

/*
int 	philo_thinks(t_philo *ph) //return -1 error, 0 no action
{
	
	long	time_rem;
	long	time_now;

	if (is_philo_dead(ph) == 1) //if -1 then terminate program
		return (1);
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	time_rem = ph->next_meal - time_now;
	if (time_rem > 0)
	{
		//remember to dlock whodied
		if (*(ph->info->whodied) >= 0)//if someone died, return (1); don't print
		return (1);
		print_status(time_now, ph, "is thinking");
		usleep2(time_rem);
	}
	print_status(time_now, ph, "is thinking");
	return (0);
}*/

int 	philo_thinks(t_philo *ph) //return -1 error, 0 no action
{
	long	time_now;

	if (is_philo_dead(ph) == 1) //if -1 then terminate program
		return (1);
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	
	if (someone_died(ph) == 1) //return 0 no action, 1 break
		return (1);
	print_status(time_now, ph, "is thinking");
	return (0);
}
