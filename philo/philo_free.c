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

#include "philo.h"

int	destroy_forks(pthread_mutex_t *fork, int count)
{
	//pthread_mutex_destroy(&mutex);
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&fork[i]);
		i++;
	}
	return (-1);
}

int	free_philo(t_program **sim)
{
	if (sim && (*sim))
	{
		destroy_forks((*sim)->fork, (*sim)->count);
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
