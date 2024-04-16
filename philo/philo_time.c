/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:32:36 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 13:36:11 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms()
{
	struct timeval currenttime;
	long	millisecs;

	gettimeofday(&currenttime, NULL);
	millisecs = currenttime.tv_sec * 1000 \
			+ currenttime.tv_usec / 1000;
	return (millisecs);
}

void	*print_time(void *arg)
{
	int	tid;
	struct	timeval currenttime;
	
	tid = *(int *)arg;
	printf("Thread %d started.\n", tid);
	gettimeofday(&currenttime, NULL);

	printf("Current time in secs is %ld\n",currenttime.tv_sec);
	printf("Current time in milliseconds %ld\n",get_time_ms());
	return (NULL);
}
