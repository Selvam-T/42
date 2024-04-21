/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:44:45 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/16 17:44:49 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"


//printng can experience bottleneck

// A displayed state message should not be mixed up with another message.

// A message announcing a philosopher died should be displayed no more than 10 ms
//after the actual death of the philosopher.

//In someone implementation the printed time is not exactly state change time 
//but the time when the thread got hold of the mutex for printf. So it might have 
//changed state  way earlier than the stamp it prints.

//My implementation was also printing status when vorks were released. 
//When I removed that, I was able to make more philosophers eat without dying. 
//(I managed 24 Philos on my home computer, I guess more on school computers!)
//I suppose the frenzy to acquire the printing mutex by threads exiting eat and 
//threads starting eating delayed the threads so much they starved and died.

// 1) Any state change of a philosopher must be formatted as follows:
//timestamp_in_ms X has taken a vork
//timestamp_in_ms X is eating
//timestamp_in_ms X is sleeping
//timestamp_in_ms X is thinking
//timestamp_in_ms X died

// 2) Replace timestamp_in_ms with the current timestamp in milliseconds
// and X with the philosopher number.

void	print_status(long t, int x, char *msg)
{
	printf("%ld ms ph[%d] %s\n", t, x, msg);
}

int	is_positive_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;	
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == 43 || *nptr == 45)
	{
		if (*nptr == 45)
			sign = -1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		res = res * 10 + (*nptr - 48);
		nptr++;
	}
	return (res * sign);
}
