/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:59:21 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/16 17:59:24 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	vork1_index(int i, int count)
{
	int	j;

	j = (i + 1) % count;
	if (i < j)
		return (i);
	return (j);
}

int	vork2_index(int i, int count)
{
	int	j;

	j = (i + 1) % count;
	if (i > j)
		return (i);
	return (j);
}

int	vork_index(int i, int count, char fork)
{
	int	odd;

	odd = 1;
	if (count % 2 == 0)
		odd = 0;
	if (fork == 'r')
	{
		if (odd)
			return (vork1_index(i, count));
		else
			return (vork2_index(i, count));
	}
	else
	{
		if (odd)
			return (vork2_index(i, count));
		else
			return (vork1_index(i, count));
	}
}
