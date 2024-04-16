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

// 1) Any state change of a philosopher must be formatted as follows:
//timestamp_in_ms X has taken a fork
//timestamp_in_ms X is eating
//timestamp_in_ms X is sleeping
//timestamp_in_ms X is thinking
//timestamp_in_ms X died

// 2) Replace timestamp_in_ms with the current timestamp in milliseconds
// and X with the philosopher number.

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
