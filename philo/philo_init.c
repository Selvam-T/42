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

#include "philo.h"

pthread_mutex_t *init_fork(int count)
{
	pthread_mutex_t 	*fork;
	int	i;
printf("init_fork mutex start\n");
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * count);
	if (fork == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&fork[i], NULL) != 0)
			return (NULL);
		i++;
	}
printf("init_fork mutex success\n\n");
	return (fork);
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
		(*sim)->ph[i].will_die_at = 0;
		(*sim)->ph[i].num_meals = 0;
		(*sim)->ph[i].r_fork = r_fork_index(i, (*sim)->count);
		(*sim)->ph[i].l_fork = l_fork_index(i, (*sim)->count);
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
	(*sim)->ttdie = ft_atoi(argv[2]);
	(*sim)->tteat = ft_atoi(argv[3]);
	(*sim)->ttsleep = ft_atoi(argv[4]);
	(*sim)->numeat = -1;
	(*sim)->eatremain = -1;
	if (argc == 6)
	{
		(*sim)->numeat = ft_atoi(argv[5]);
		(*sim)->eatremain = (*sim)->count;//teminate if reached 0
	}	
	(*sim)->fork = init_fork((*sim)->count);
	if ((*sim)->fork == NULL)
		return (-1);
	(*sim)->end = 0; //1 true, 0 not true, terminate if true
	(*sim)->index = -1; //for pthread_create loop index to assign tid
	//(*sim)->print_lock = NULL;
	//(*sim)->dead_lock = NULL;
	(*sim)->ph = NULL;
	return (init_threads(sim));//return 1 success, -2 malloc fail indicate free forks
}
