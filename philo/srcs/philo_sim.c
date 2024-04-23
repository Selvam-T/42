/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:12:29 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/22 12:12:47 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*num_eat_detach(t_philo *ph)
{
	printf("***\n");//DELETE
	printf("ph[%d], num_meals [%d] \n", ph->tid, ph->num_meals);
	if (ph->num_meals >= ph->info.numeat)
	{
		printf("num meals [%d] >= num eat [%d]. Detach ph[%d]\n", \
			ph->num_meals, ph->info.numeat, ph->tid);
		*(ph->actvph) -= 1;
		pthread_detach(ph->td);
		return (NULL); //exit? ERROR HANDLE
	}
	else //DELETE
		printf("num meals [%d] < num eat [%d]. Don't detach ph[%d]\n", \
			ph->num_meals, ph->info.numeat, ph->tid);
	printf("***\n");
	return (NULL);
}

void	*sim_routine(void *arg)
{
	long		timerm;
	t_philo		*ph;
	
	ph = (t_philo *)arg;

	while (1)
	{
		//IF NUMEALS >= NUM EAT ---> DETACH_THREAD, RETURN
		printf("ph[%d] thread begins.\n", ph->tid);
		if (ph->info.numeat != -1)
			num_eat_detach(ph);
		
		//EATING
		eating(ph);
		
		//SLEEPING
		print_status(get_time_ms(), ph, "is sleeping");
		usleep2(ph->info.ttsleep);

		//THINKING
		timerm = ph->next_meal - get_time_ms();
		print_status(get_time_ms(), ph, "is thinking");
		usleep2(timerm);
	}
	return (NULL);
}
/*int	sim_monitor(t_philo *ph)
{
	(void)ph;
	
	if (ph->next_meal < get_time_ms()) //his ttdie exceeded
	{
		//lock mutex to dead
		pthread_mutex_lock(&ph->dead_lock);
			ph->dead = 1;
		pthread_mutex_unlock(&ph->dead_lock);
	}
	//if (ph->dead = 1)
		//END SIMULATION
		//FREE EVERYTHING

	return (0);
}*/

int	sim_activity(t_philo *ph, t_mutex m, int count)
{
	int	i;
	i = 0;
	while (i < count)
	{
		printf("create thread for ph [%d]\n",ph[i].tid);
		if (pthread_create(&(ph[i].td), NULL, sim_routine, (void *)&(ph[i])) != 0)
			return (-1);
		i++;
	}
	
	//	sim_monitor(sim);
	while (1)
	{
		//KIV number of threads still active
		if (m.actvph == 0)
		{
			printf("ALL THREADS have detached \n");
			break;
		}
		else
			printf("%d THREADS still active\n",m.actvph);
		//KIV dead flag
		if (m.dead == 1)
		{
			printf("SOMEONE has died \n");
			break;
		}
		else
			printf("EVERYONE is alive\n");
	}
	
	//join thread
	i = 0;
	while (i < count)
	{
		printf("join ph [%d]\n",i);
		if (pthread_join(ph[i].td, NULL) != 0)
			return (-1);
		i++;
	}
	return(0);
}
