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

long	get_time_ms()
{
	struct	timeval currenttime;
	long	millisecs;
	
	if (gettimeofday(&currenttime, NULL) == -1)
		return (-1);// ERROR_HANDLE
	millisecs = currenttime.tv_sec * 1000 + currenttime.tv_usec / 1000;
	return (millisecs);
}
