/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 12:36:28 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/12 12:36:40 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	print_ifalive(long time, t_philo *ph, char *msg, long tsleep)
{
	if (someone_died(ph) == 1)
		return (1);
	pthread_mutex_lock(ph->plock);
	printf("%ld ms %d %s\n", time, ph->tid + 1, msg);
	pthread_mutex_unlock(ph->plock);
	//usleep2(tsleep);
	usleep(tsleep);
	return (0);
}
