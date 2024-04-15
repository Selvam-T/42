/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_free_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:04:59 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 12:07:53 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	r_fork_index(int i, int count)
{
	int	j;
	
	j = (i + 1) % count;
	if (i < j)
		return (i);
	return (j);
}

int	l_fork_index(int i, int count)
{
	int	j;
	
	j = (i + 1) % count;
	if (i > j)
		return (i);
	return (j);
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

