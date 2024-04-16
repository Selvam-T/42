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

