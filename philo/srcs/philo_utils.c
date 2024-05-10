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

int	validated_count(int argc, char **argv)
{
	int	count;

	if (argc < 5 || argc > 6)
		return (handle_error1("Error: Incorrect No. of arguments"));
	if (is_positive_digit(argc, argv) == -1)
		return (handle_error1("Error: not a valid digit"));
	count = ft_atoi(argv[1]);
	if (count == 0 || count > 200)
		return (handle_error1("Error: Invalid No. of Philosophers"));
	return (count);
}
