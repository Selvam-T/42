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

void	test_print(t_program *sim)
{
	int	i;
	
	printf("\nNumber of Ph: [%d]\n",sim->count);
	printf("time to die [%ld] milliseconds\n",sim->ttdie);
	printf("time to eat [%ld] milliseconds\n",sim->tteat);
	printf("time to sleep [%ld] milliseconds\n",sim->ttsleep);
	printf("each ph eats [%d] times\n",sim->numeat);
	//printf("Terminate when total eat count [%d]\n",sim->eatremain);

	printf("vork status before claim:\n");
	printf("%s \n", sim->end ? "Someone died" : "No one died");
	printf("index to assign tid [%d] before loop iteration\n",sim->index);


	printf("print each thread:\n");
	i = 0;
	while (i < sim->count)
	{
		printf("==================\n");
		printf("thread id [%d]\n",sim->ph[i].tid);
		printf("last meal eaten at [%ld]\n",sim->ph[i].last_meal);
		printf("next meal eat at [%ld]\n",sim->ph[i].next_meal);
		//printf("will die at [%d]\n",sim->ph[i].will_die_at);
		printf("meals eaten [%d]\n",sim->ph[i].num_meals);
		
		i++;
	}
}
