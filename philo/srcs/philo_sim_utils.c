/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:15:41 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/24 17:15:56 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	usleep2(long time)
{
	int	x;
	int	i;

	x = time / 100;
	i = 0;
	while(i < x)
	{
		usleep(1000);
		i++;
	}
}

void	print_status(long time, t_philo *ph, char *msg)
{
	pthread_mutex_lock(ph->plock);
		printf("%ld ms ph[%d] %s\n", time, ph->tid + 1, msg);
	pthread_mutex_unlock(ph->plock);
}

void	detachif_eaten(t_philo *ph)
{
	if (ph->info->numeat != -1 && ph->eaten >= ph->info->numeat)
	{
		//printf("num meals [%d] >= num eat [%d]. Detach ph[%d]\n", \
		//	ph->num_meals, ph->info->numeat, ph->tid);//DELETE
		pthread_detach(ph->td);
	}
}

int 	breakif_dead(t_philo *ph)
{
	long	curtime;

	curtime = get_time_ms() - ph->info->tstart;// -1 ERROR HANDLE
	if  (ph->next_meal < curtime)
	{
		pthread_mutex_lock(ph->dlock);
		ph->dead = 1;
		pthread_mutex_unlock(ph->dlock);

		printf("ph[%d] next meal %ld < cur time %ld, dead flag is set to 1\n"\
			,ph->tid, ph->next_meal, curtime);//DELETE
		return (1);
	}
	printf("ph[%d] next meal is later, so not dead\n",ph->dead);//DELETE
	return (0);
}

void 	detachif_lesstime(t_philo *ph, int actv_time)
{
	//actv_time = tteat or ttsleep
	if (get_time_ms() + actv_time < ph->next_meal)// -1 ERROR HANDLE
		usleep(actv_time);
	else
	{
		usleep(ph->next_meal - get_time_ms());
		pthread_detach(ph->td);
	}
}