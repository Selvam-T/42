/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:36:27 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 13:42:54 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_info(t_general info)
{	
	printf("No. of PH [%d]\n",info.count);
	printf("time to die [%ld] milliseconds\n",info.ttdie);
	printf("time to eat [%ld] milliseconds\n",info.tteat);
	printf("time to sleep [%ld] milliseconds\n",info.ttsleep);
	printf("each ph eats [%d] times\n",info.numeat);
}

void	print_ph(t_philo *ph, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("tid [%d]\n", ph[i].tid);
		printf("last meal [%ld]\n", ph[i].last_meal);
		printf("next meal [%ld]\n", ph[i].next_meal);
		printf("ptr to dead [%d]\n", *(ph[i].dead));
		printf("ptr to active threads [%d]\n", *(ph[i].actvph));
		print_info(ph[i].info);
		printf("****************************************\n");
		i++;
	}
}
