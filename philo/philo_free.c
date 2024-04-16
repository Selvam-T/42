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

void	free_fork(t_program **sim)
{
	free((*sim)->fork);
	(*sim)->fork = NULL;
//printf("---100---\n");
}

int	free_philo(t_program **sim)
{
	free_fork(sim);
//printf("---200---\n");
	free((*sim)->ph);
	(*sim)->ph = NULL;
//printf("---300---\n");
	free(*sim);
	*sim = NULL;
//printf("---400---\n");
	return (-1);
}

void	handle_error() //used in philo_threads
{
	printf("Error exit\n");
	exit(EXIT_FAILURE);
}
