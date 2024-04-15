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

int	*init_fork(int count)
{
	int	*fork;
	int	i;
	
	fork = (int *)malloc(sizeof(int) * count);
	if (fork == NULL)
		return (NULL);//ph is malloc after this, hence nothing to free in calling func
	i = 0;
	while (i < count)
	{
		fork[i] = -1;//-1 is unclaimed initially
		i++;
	}
	return (fork);	
}

int	init_threads(t_program **sim)
{
	int	i;
	
	//malloc for count, no need extra to null terminate, we know count
	(*sim)->ph = (t_philo *)malloc(sizeof(t_philo) * (*sim)->count);
	if ((*sim)->ph == NULL)
		return (-2); //-2 free fork in calling function
	i = 0;
	while (i < (*sim)->count)//n, 0, 1, 2...n clockwise
	{
		(*sim)->ph[i].tid = i;
		(*sim)->ph[i].eating = 0;
		(*sim)->ph[i].eat_count = 0;
		(*sim)->ph[i].eat_start = 0;
		(*sim)->ph[i].next_meal = 0;
		(*sim)->ph[i].l_fork = -1;
		(*sim)->ph[i].r_fork = -1;
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
	(*sim)->toteatcount = -1;
	if (argc == 6)
	{
		(*sim)->numeat = ft_atoi(argv[5]);
		(*sim)->toteatcount = (*sim)->count * (*sim)->numeat;//teminate if reached
	}	
	(*sim)->fork = init_fork((*sim)->count);
	if ((*sim)->fork == NULL)
		return (-1);
	(*sim)->end = 0; //1 true, 0 not true, terminate if true
	(*sim)->r_fork = NULL;
	(*sim)->l_fork = NULL;
	(*sim)->print_lock = NULL;
	(*sim)->dead_lock = NULL;
	(*sim)->ph = NULL;
	return (init_threads(sim));//return 1 success, -2 malloc fail
}
