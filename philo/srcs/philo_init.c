/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:10:54 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/14 15:10:56 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

pthread_mutex_t *init_vork(int count)
{
	pthread_mutex_t 	*vork;
	int	i;

	vork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * count);
	if (vork == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&vork[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (vork);
}

t_philo	*init_threads(t_general *info, t_mutex *mtx, int count)
{
	t_philo	*ph;
	int		i;

	ph = (t_philo *)malloc(sizeof(t_philo) * count);
	if (ph == NULL)
		return (handle_error2("Malloc failure"));
	
	i = 0;
	while (i < count)
	{
		ph[i].tid = i;
		ph[i].last_meal = 0;
		ph[i].next_meal = 0;
		ph[i].num_meals = 0;
		
		ph[i].dead = &(mtx->dead);
		ph[i].actvph = &(mtx->actvph);
		ph[i].r_vork = mtx->vork[r_vork_index(i, count)];
		ph[i].l_vork = mtx->vork[l_vork_index(i, count)];
		ph[i].plock = mtx->plock;
		ph[i].dlock = mtx->dlock;
		ph[i].info = *info;
		
		i++;
	}
	return (ph);
}

void 	init_general_info(t_general *info, int argc, char **argv)
{
	info->ttdie = (long)ft_atoi(argv[2]);
	info->tteat = (long)ft_atoi(argv[3]);
	info->ttsleep = (long)ft_atoi(argv[4]);
	info->numeat = -1;
	if (argc == 6)
		info->numeat = ft_atoi(argv[5]);
}

int 	init_mutex(t_mutex *mtx, int count)
{
	mtx->dead = 0;
	mtx->actvph = count;
	if (pthread_mutex_init(&mtx->plock, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&mtx->dlock, NULL) != 0)
	{
		//pthread_mutex_destroy(&mtx->plock);
		destroy_mutex(&mtx->plock, NULL, NULL);
		return (-1);
	}
	if (pthread_mutex_init(&mtx->alock, NULL) != 0)
	{
		//pthread_mutex_destroy(&mtx->plock);
		//pthread_mutex_destroy(&mtx->dlock);
		destroy_mutex(&mtx->plock, &mtx->dlock, NULL);
		return (-1);
	}
	mtx->vork = init_vork(count);
	if (mtx->vork == NULL)
	{
		//pthread_mutex_destroy(&mtx->plock);
		//pthread_mutex_destroy(&mtx->dlock);
		//pthread_mutex_destroy(&mtx->alock);
		destroy_mutex(&mtx->plock, &mtx->dlock, &mtx->alock);
		return (-1);
	}
	return (0);
}
