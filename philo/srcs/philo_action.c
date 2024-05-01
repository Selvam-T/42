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

void 	update_num_meals(t_philo *ph)
{
	if (ph->info->numeat != -1)// -1 means num of meals was not input
	{
		pthread_mutex_lock(ph->elock);
		ph->eaten += 1;
		pthread_mutex_unlock(ph->elock);
	}
}

void	eat_and_die()
{

}

void	eating(t_philo *ph)
{

	//LOCK right and left forks
	pthread_mutex_lock(ph->r_vork);
	print_status(get_time_ms() - ph->info->tstart, ph, "has taken a R fork");//print lock in func
			
	pthread_mutex_lock(ph->l_vork);
	print_status(get_time_ms() - ph->info->tstart, ph, "has taken a L fork");//print lock in func

	//LAST MEAL = GET CUR TIME
	ph->last_meal = get_time_ms() - ph->info->tstart;
	//if (ph->last_meal == -1) //get_time_ms() could return -1 if local ERROR
		//return (NULL); //ERROR HANDLE

	//NEXT MEAL = LASTMEAL + TT DIE
	ph->next_meal = ph->last_meal + ph->info->ttdie;
	printf("ph[%d] assigned, last_meal %ld, next_meal %ld, tt_die %ld\n",\
			ph->tid, ph->last_meal, ph->next_meal, ph->info->ttdie);
	//NUM_MEALS++
	update_num_meals(ph);
	
	//PRINT EATING
	print_status(ph->last_meal, ph, "is eating");//print lock in func
	usleep2(ph->info->tteat);
	
	//UNLOCK right and left forks
	pthread_mutex_unlock(ph->r_vork);
	pthread_mutex_unlock(ph->l_vork);

	print_eat_updates(ph);//DELETE
}

void	sleeping(t_philo *ph)
{
	print_status(get_time_ms(), ph, "is sleeping");//lock if done in func
	usleep2(ph->info->ttsleep);
}

void	thinking(t_philo *ph)
{
	long		timerm;

	timerm = ph->next_meal - get_time_ms();
	if (timerm > 0)
	{
		print_status(get_time_ms(), ph, "is thinking");//lock is done in func
		usleep2(timerm);
	}
}
