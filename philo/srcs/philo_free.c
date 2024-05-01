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

void	destroy_mutex(t_mutex *mtx, int flag)
{
	if (flag >= 1)
		pthread_mutex_destroy(&(mtx->plock));
	if (flag >= 2)
		pthread_mutex_destroy(&(mtx->klock));
	if (flag >= 3)
		pthread_mutex_destroy(&(mtx->dlock));
	if (flag == 4)
		pthread_mutex_destroy(&(mtx->elock));
}

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
	pthread_mutex_destroy(&mtx->klock);
	pthread_mutex_destroy(&mtx->dlock);
	pthread_mutex_destroy(&mtx->elock);
}
