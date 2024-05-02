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
			return (1); //signal to break from thread
		}
	}
	return (0);
}

int		eating(t_philo *ph)//return -1 error, 1 break, 0 no action
{
	long	time_now;

	//LOCK right fork
	pthread_mutex_lock(ph->r_vork);
	time_now = get_time_ms();
	if (time_now == -1)
		return (-1);
	print_status(time_now - ph->info->tstart, ph, "has taken a R fork");
	
	//LOCK left fork	
	pthread_mutex_lock(ph->l_vork);
	time_now = get_time_ms();
	if (time_now == -1)
		return (-1);
	print_status(time_now - ph->info->tstart, ph, "has taken a L fork");

	//LAST MEAL = GET CUR TIME
	time_now = get_time_ms();
	if (time_now == -1)
		return (-1);
	ph->last_meal = time_now - ph->info->tstart;

	//PRINT EATING
	print_status(ph->last_meal, ph, "is eating");
	usleep2(ph->info->tteat);

	//NEXT MEAL = LASTMEAL + TT DIE
	ph->next_meal = ph->last_meal + ph->info->ttdie;
	
	//NUM_MEALS++
	if (update_num_meals(ph) == 1)
		return (1);//signal to break from thread

	//UNLOCK right and left forks
	pthread_mutex_unlock(ph->r_vork);
	pthread_mutex_unlock(ph->l_vork);
	
	//delete test print------------
	printf("%ld ms ph[%d] finished eating %d meals\n",\
		get_time_ms() - ph->info->tstart, ph->tid + 1, ph->eaten);//DELETE
	return (0);
}

int		sleeping(t_philo *ph) //return -1 error, 0 no action
{
	long	time_now;

	time_now = get_time_ms();
	if (time_now == -1)
		return (-1);
	print_status(time_now - ph->info->tstart, ph, "is sleeping");
	usleep2(ph->info->ttsleep);
	return (0);
}

int 	thinking(t_philo *ph) //return -1 error, 0 no action
{
	long	time_rem;
	long	time_now;

	time_now = get_time_ms();
	if (time_now == -1)
		return (-1);
	time_rem = ph->next_meal - (time_now - ph->info->tstart);
	if (time_rem > 0)
	{
		print_status(time_now - ph->info->tstart, ph, "is thinking");
		usleep2(time_rem);
	}
	return (0);
}
