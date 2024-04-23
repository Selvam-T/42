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

void 	manage_num_meals(t_philo *ph)
{
	if (ph->info.numeat != -1)
		ph->num_meals += 1;
}

void	eating(t_philo *ph)
{

	//LOCK right and left forks
	pthread_mutex_lock(&(ph->r_vork));
	print_status(get_time_ms(), ph, "has taken a R fork");
			
	pthread_mutex_lock(&(ph->l_vork));
	print_status(get_time_ms(), ph, "has taken a L fork");

	//LAST MEAL = GET CUR TIME
	ph->last_meal = get_time_ms();
	//if (ph->last_meal == -1) //ERROR
		//return (NULL); //ERROR HANDLE

	//NEXT MEAL = LASTMEAL + TT DIE
	ph->next_meal = ph->last_meal + ph->info.ttdie;
	
	//NUM_MEALS++
	manage_num_meals(ph);
	
	//PRINT EATING_->I lock print function in print_status()
	print_status(ph->last_meal, ph, "is eating");
	
	usleep2(ph->info.tteat);

	//UNLOCK right and left forks
	pthread_mutex_unlock(&(ph->r_vork));
	pthread_mutex_unlock(&(ph->l_vork));
}
