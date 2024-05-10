/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:42:19 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/03 16:42:37 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int someone_died(t_philo *ph) //return 0 no action, 1 break
{
	pthread_mutex_lock(ph->dlock);
	if (*(ph->info->whodied) >= 0)
	{
		pthread_mutex_unlock(ph->dlock);
		return (1);
	}
	pthread_mutex_unlock(ph->dlock);
	return (0);
}