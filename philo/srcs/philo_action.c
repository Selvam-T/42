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
			pthread_mutex_unlock(ph->r_vork);
			pthread_mutex_unlock(ph->l_vork);
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
	//if kill flag is 1, return (1); don't print
	print_status(time_now, ph, msg);
	return (0);
}

int		philo_eats(t_philo *ph)//return -1 error, 1 break, 0 no action
{
	if (breakif_dead(ph) == 1) //if -1 then terminate program ***
		return (1);

	//LOCK right fork
	pthread_mutex_lock(ph->r_vork);
	if (takefork(ph, "has taken a R fork") == -1) // or == 1
		return (-1); // return (1);

	//LOCK left fork	
	pthread_mutex_lock(ph->l_vork);
	if (takefork(ph, "has taken a L fork") == -1) // or == 1
		return (-1); // return (1);
	
	if (breakif_lesstime(ph, ph->info->tteat, "is eating") == 1)
		return (1);//signal to break from thread

	//test DELETE
	printf("%ld is time_now after eating\n",get_time_ms() - ph->info->tstart);//DELETE
	
	//NUM_MEALS++
	if (update_num_meals(ph) == 1)
		return (1);//signal to break from thread

	//UNLOCK right and left forks
	pthread_mutex_unlock(ph->r_vork);
	pthread_mutex_unlock(ph->l_vork);
	return (0);
}

int		philo_sleeps(t_philo *ph) //return -1 error, 0 no action
{
	if (breakif_dead(ph) == 1) //if -1 then terminate program ***
		return (1);
	return (breakif_lesstime(ph, ph->info->ttsleep, "is sleeping"));
}

int 	philo_thinks(t_philo *ph) //return -1 error, 0 no action
{
	long	time_rem;
	long	time_now;

	if (breakif_dead(ph) == 1) //if -1 then terminate program
		return (1);
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	time_rem = ph->next_meal - time_now;
	if (time_rem > 0)
	{
		//if kill flag is 1, return (1); don't print
		print_status(time_now, ph, "is thinking");
		usleep2(time_rem);
	}
	//else WHAT HAPPENS? *** it means next_meal time is past, handled by sim_routine
	return (0);
}
