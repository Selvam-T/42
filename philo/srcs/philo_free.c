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

void	destroy_mutex(pthread_mutex_t *a, pthread_mutex_t *b, pthread_mutex_t *c)
{
	if (a != NULL)
		pthread_mutex_destroy(a);
	if (b != NULL)
		pthread_mutex_destroy(b);
	if (c != NULL)
		pthread_mutex_destroy(c);
}

/*
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
} */

void	*free_ph(t_philo *ph)
{

	free (ph);
	ph = NULL;
	return (NULL);
}

int	handle_error1(char *msg)
{
	printf("%s\n",msg);
	return (-1);
}

void	*handle_error2(char *msg)
{
	printf("%s\n",msg);
	return (NULL);
}

void	free_all(t_philo *ph, t_mutex *mtx, int count)
{
	free_ph(ph);
	destroy_vorks(mtx->vork, count);
	pthread_mutex_destroy(&mtx->plock);
	pthread_mutex_destroy(&mtx->dlock);	
}
