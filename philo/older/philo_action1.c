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

void	eating(t_program *sim, int i)
{

	//LOCK right and left forks
	pthread_mutex_lock(&sim->vork[sim->ph[i].r_vork]);
	//print_status(sim, sim->ph[i].last_meal, sim->ph[i].tid, "has taken a fork");
			
	pthread_mutex_lock(&sim->vork[sim->ph[i].l_vork]);
	//print_status(sim, sim->ph[i].last_meal, sim->ph[i].tid, "has taken a fork");

	//LAST MEAL = GET CUR TIME
	sim->ph[i].last_meal = get_time_ms();
	//if (sim->ph[i].last_meal == -1) //ERROR
		//return (NULL); //ERROR HANDLE

	//NEXT MEAL = LASTMEAL + TT DIE
	sim->ph[i].next_meal = sim->ph[i].last_meal + sim->ttdie;
	
	//NUM_MEALS++
	sim->ph[i].num_meals++;
	//printf("*** %ld ms ph[%d] num_meals++ [%d] ***\n", get_time_ms(), sim->ph[i].tid, \
		sim->ph[i].num_meals);
	
	//PRINT EATING
	//print_status(sim, sim->ph[i].last_meal, sim->ph[i].tid, "is eating");
	print_status2(sim, get_time_ms(), sim->ph[i].tid, "is eating", \
			sim->ph[i].num_meals);//DELETE
	usleep(sim->tteat * 1000);

	//UNLOCK right and left forks
	pthread_mutex_unlock(&sim->vork[sim->ph[i].r_vork]);
	pthread_mutex_unlock(&sim->vork[sim->ph[i].l_vork]);
}
