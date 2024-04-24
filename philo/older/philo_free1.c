/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:49:04 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/16 15:49:07 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	destroy_vorks(pthread_mutex_t *vork, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("destroy mutex fork %d\n",i);
		pthread_mutex_destroy(&vork[i]);
		i++;
	}
	free (vork);
	vork = NULL;
	return (0);
}

int	free_philo(t_program **sim)
{
	if (sim && (*sim))
	{
		destroy_vorks((*sim)->vork, (*sim)->count);
		if ((*sim)->ph)
			free((*sim)->ph);
		(*sim)->ph = NULL;
		free(*sim);
		*sim = NULL;
	}
	return (-1);
}

void	handle_error() //used in philo_threads
{
	printf("Error exit\n");
	exit(EXIT_FAILURE);
}
