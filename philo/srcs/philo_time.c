/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:32:36 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/13 12:32:51 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	get_time_ms(void)
{
	struct timeval	currenttime;
	long			millisecs;

	if (gettimeofday(&currenttime, NULL) == -1)
		return (-1);
	millisecs = currenttime.tv_sec * 1000 + currenttime.tv_usec / 1000;
	return (millisecs);
}

long	time_now(long tstart)
{
	long	timenow;

	timenow = get_time_ms() - tstart;
	if (timenow == -1)
		return (-1);
	return (timenow);
}

void	usleep2(long time)
{
	int	i;
	long	t;
	long	b;

	t = time / 100;
	b = time % 100;
	i = 0;
	while (i < t)
	{
		usleep(1000 * 100);
		i++;
	}
	usleep(1000 * b);
}
