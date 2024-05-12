/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:34:56 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/12 12:35:59 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	update_num_meals(t_philo *ph, long time) //REMOVE time
{
	if (ph->info->numeat != -1)
	{
		pthread_mutex_lock(ph->elock); //Lock eaten
		ph->eaten += 1;
		if (ph->eaten >= ph->info->numeat)
		{
			printf("ph[%d] eaten %d meals. LEAVE THREAD >>\n",ph->tid + 1, ph->eaten);
			pthread_mutex_unlock(ph->elock);
			pthread_mutex_lock(ph->alock); //Lock active
			*(ph->info->active) -= 1;
			pthread_mutex_unlock(ph->alock);
			ph->exit_time = time;//DELETE
			return (1);
		}
		pthread_mutex_unlock(ph->elock);
	}
	return (0);
}

void	update_simflags(t_philo *ph, long tdied)
{
	pthread_mutex_lock(ph->dlock);
	*(ph->info->whodied) = ph->tid;
	*(ph->info->tdied) = tdied;
	pthread_mutex_unlock(ph->dlock);
}
