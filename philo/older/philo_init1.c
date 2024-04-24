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

/* DO I NEED TO MALLOC d_lock mutex?
pthread_mutex_t init_dlock()
{
	pthread_mutex_t 	dlock;
	
	dlock = (pthread_mutex_t)malloc(sizeof(pthread_mutex_t) * 1);
	if (dlock == NULL)
		return (NULL);
	return (dlock);
}

pthread_mutex_t init_prnlock() //DO I NEED TO MALLOC prn_lock mutex?
{
	pthread_mutex_t 	prnlock;
	
	prnlock = (pthread_mutex_t)malloc(sizeof(pthread_mutex_t) * 1);
	if (prnlock == NULL)
		return (NULL);
	return (prnlock);
}*/

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
		//printf("init_vork[%d] mutex\n",i);//DELETE
		if (pthread_mutex_init(&vork[i], NULL) != 0)
			return (NULL);
		i++;
	}
	return (vork);
}

int	init_threads(t_program **sim)
{
	int	i;
	
	(*sim)->ph = (t_philo *)malloc(sizeof(t_philo) * (*sim)->count);
	if ((*sim)->ph == NULL)
		return (-1);
	
	i = 0;
	while (i < (*sim)->count)
	{
		(*sim)->ph[i].tid = i;
		(*sim)->ph[i].last_meal = 0;
		(*sim)->ph[i].next_meal = 0;
		(*sim)->ph[i].num_meals = 0;
		(*sim)->ph[i].r_vork = r_vork_index(i, (*sim)->count);
		(*sim)->ph[i].l_vork = l_vork_index(i, (*sim)->count);
		i++;
	}
	return (1);
}

int	init_sim(t_program **sim, int argc, char **argv)
{
	
	if (is_positive_digit(argc, argv) == -1)
		return (-1);//NEG_DIGIT_OR_NON_DIGIT
	(*sim)->count = ft_atoi(argv[1]);
	if ((*sim)->count > 200)
		return (-1);//GRT_THAN_200
	(*sim)->ttdie = (long)ft_atoi(argv[2]);
	(*sim)->tteat = (long)ft_atoi(argv[3]);
	(*sim)->ttsleep = (long)ft_atoi(argv[4]);
	(*sim)->numeat = -1;
	if (argc == 6)
	{
		(*sim)->numeat = ft_atoi(argv[5]);
		//(*sim)->eatremain = (*sim)->count;//teminate if reached 0
	}	
	(*sim)->vork = init_vork((*sim)->count);//IF NULL ERROR?
	//(*sim)->print_lock = init_prnlock();//not a pointer,can't initalize to NULL
	//(*sim)->dead_lock = init_dlock(); //not a pointer,can't initalize to NULL
	if ((*sim)->vork == NULL)
		return (-1);
	(*sim)->dead = 0; //1 true, 0 not true, terminate if true
	(*sim)->index = -1; //for pthread_create loop index to assign tid
	(*sim)->ph = NULL;
	return (init_threads(sim));//return 1 success, -2 malloc fail indicate free vorks
}
