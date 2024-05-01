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
	printf("kill value [%d]\n",*(info->kill));
	printf("active value [%d]\n",*(info->active));
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
		printf("eaten [%d] meals\n", ph[i].num_meals);
		printf("dead flag [%d]\n", ph[i].dead);
		printf("eaten count [%d]\n", ph[i].eaten);
		print_info(ph[i].info);
		printf("****************************************\n");
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
		if (ph[i].klock == &(mut->klock))
			printf("ph[%d] address is same as mut klock\n",i);
		else
			printf("ph[%d] address is different from mut klock\n",i);
		if (ph[i].dlock == &(mut->dlock))
			printf("ph[%d] address is same as mut dlock\n",i);
		else
			printf("ph[%d] address is different from mut dlock\n",i);
		if (ph[i].elock == &(mut->elock))
			printf("ph[%d] address is same as mut elock\n",i);
		else
			printf("ph[%d] address is different from mut elock\n",i);
		if (ph[i].l_vork == &(mut->vork[i + 1]))
			printf("ph[%d] lfork address is same as mut vork[%d]\n",i,i + 1);
		else
			printf("ph[%d] lfork address is different from mut vork[%d]\n",i,i+1);
		i++;
	}
}

void 	print_eat_updates(t_philo *ph)
{

	printf("ph[%d], next meal %ld ms, has eaten %d meals, dead flag is %d\n", \
			ph->tid, ph->next_meal, ph->eaten, ph->dead);
}
