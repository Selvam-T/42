/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:02:48 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/10 14:03:05 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_atoi(const char *num)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*num >= 9 && *num <= 13) || *num == 32)
		num++;
	if (*num == 43 || *num == 45)
	{
		if (*num == 45)
			sign = -1;
		num++;
	}
	while (*num >= 48 && *num <= 57)
	{
		res = res * 10 + (*num - 48);
		num++;
	}
	return (res * sign);
}

int	validated_count(int argc, char **argv)
{
	int	i;
	int	count;

	if (argc < 5 || argc > 6)
		return (handle_error1("Error: Incorrect No. of arguments"));
	count = ft_atoi(argv[1]);
	if (count <= 0 || count > 200)
		return (handle_error1("Error: Invalid Philosopher value"));
	i = 2;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (handle_error1("Error: not a valid digit"));
		i++;
	}
	return (count);
}

/*
int	is_positive_digit(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '\0')
			return (-1);
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
*/
