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

long	get_time_ms()
{
	struct	timeval currenttime;
	long	millisecs;
	
	if (gettimeofday(&currenttime, NULL) == -1)
		return (-1);// ERROR_HANDLE
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
