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

pthread_mutex_t *init_vorks(int count)// return NULL error 
{
	pthread_mutex_t 	*vorks;
	int	i;

	vorks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * count);
	if (vorks == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&vorks[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (vorks);
}

t_philo	*init_threads(t_general *info, t_mutex *mtx, int count) // return NULL error
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
		ph[i].next_meal = info->ttdie;
		ph[i].eaten = 0;
		ph[i].r_vork = &mtx->vork[vork_index(i, count, 'r')];
		ph[i].l_vork = &mtx->vork[vork_index(i, count, 'l')];
		ph[i].plock = &mtx->plock;
		ph[i].klock = &mtx->klock;
		ph[i].alock = &mtx->alock;
		ph[i].info = info;
		i++;
	}
	return (ph);
}
	
void 	init_general_info(t_general *info, int argc, char **argv, t_sim *sim)
{
	info->count = sim->count;
	info->tstart = 0;
	info->ttdie = (long)ft_atoi(argv[2]);
	info->tteat = (long)ft_atoi(argv[3]);
	info->ttsleep = (long)ft_atoi(argv[4]);
	info->numeat = -1;
	if (argc == 6)
		info->numeat = ft_atoi(argv[5]);
	info->kill = &(sim->kill);
	info->active = &(sim->active);
	info->whodied = &(sim->whodied);
}

int 	init_mutex(t_mutex *mtx, int count)// return -1 error, 0 no action
{
	if (pthread_mutex_init(&mtx->plock, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&mtx->klock, NULL) != 0)
	{
		destroy_mutex(mtx,1);
		return (-1);
	}

	if (pthread_mutex_init(&mtx->alock, NULL) != 0)
	{
		destroy_mutex(mtx,2);
		return (-1);
	}
	
	mtx->vork = init_vorks(count);
	if (mtx->vork == NULL)
	{
		destroy_mutex(mtx,3);
		return (-1);
	}
	return (0);
}
