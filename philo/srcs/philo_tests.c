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

void	print_info(t_general *info)
{	
	printf("No. of PH [%d]\n",info->count);
	printf("time to die [%ld] milliseconds\n",info->ttdie);
	printf("time to eat [%ld] milliseconds\n",info->tteat);
	printf("time to sleep [%ld] milliseconds\n",info->ttsleep);
	printf("each ph eats [%d] times\n",info->numeat);
	printf("ph[%d] died\n",*(info->whodied));
	printf("time of death [%ld]\n",*(info->tdied));
	printf("number of active ph [%d]\n",*(info->active));
}

void	print_ph(t_philo *ph, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		printf("tid [%d]\n", ph[i].tid);
		//printf("last meal [%ld]\n", ph[i].cur_meal);
		printf("next meal [%ld]\n", ph[i].next_meal);
		printf("eaten count [%d]\n", ph[i].eaten);
		print_info(ph[i].info);
		printf("****************************************\n");
		i++;
	}
}

void	print_fork_allocation(t_philo *ph, int count)
{
	int	i;

	if (count % 2 == 0)
		printf("We have Even number of ph \n");
	else
		printf("We have Odd number of ph \n");
	i = 0;
	while (i < count)
	{
		printf("ph[%d] right fork is %d\n",ph[i].tid, vork_index(i, count, 'r'));
		printf("ph[%d] left fork is %d\n",ph[i].tid, vork_index(i, count, 'l'));
		i++;
	}
}

void	print_mutex_test(t_philo *ph, int count, t_mutex *mut)
{
	int	i;

	i = 0;
	while (i < count)
	{	
		if (ph[i].plock == &(mut->plock))
			printf("ph[%d] address is same as mut plock\n",i);
		else
			printf("ph[%d] address is different from mut plock\n",i);
		if (ph[i].dlock == &(mut->dlock))
			printf("ph[%d] address is same as mut dlock\n",i);
		else
			printf("ph[%d] address is different from mut dlock\n",i);
		if (ph[i].alock == &(mut->alock))
			printf("ph[%d] address is same as mut elock\n",i);
		else
			printf("ph[%d] address is different from mut elock\n",i);
		if (ph[i].vork2 == &(mut->vork[i + 1]))
			printf("ph[%d] lfork address is same as mut vork[%d]\n",i,i + 1);
		else
			printf("ph[%d] lfork address is different from mut vork[%d]\n",i,i+1);
		i++;
	}
}
