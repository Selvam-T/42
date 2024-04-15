/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:08:56 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 12:09:53 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_fork(t_program **sim)
{
	free((*sim)->fork);
	(*sim)->fork = NULL;
}

int	free_philo(t_program **sim)
{
	free_fork(sim);
	free((*sim)->ph);
	(*sim)->ph = NULL;
	free(*sim);
	*sim = NULL;
	return (-1);
}

void	handle_error() //used in philo_threads
{
	printf("Error exit\n");
	exit(EXIT_FAILURE);
}
