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
			printf("ph[%d].plock address is same as mut plock. [%p] == [%p]\n",i, ph[i].plock, &(mut->plock));
		else
			printf("ph[%d].plock address is different from mut plock\n",i);
		if (ph[i].dlock == &(mut->dlock))
			printf("ph[%d].dlock address is same as mut dlock. [%p] == [%p]\n",i, ph[i].dlock, &(mut->dlock));
		else
			printf("ph[%d].dlock address is different from mut dlock\n",i);
		if (ph[i].alock == &(mut->alock))
			printf("ph[%d].alock address is same as mut alock. [%p] == [%p]\n",i, ph[i].alock, &(mut->alock));
		else
			printf("ph[%d].alock address is different from mut alock\n",i);
		if (ph[i].vork2 == &(mut->vork[i + 1]))
			printf("ph[%d] lfork address is same as mut vork[%d]. [%p] == [%p]\n",i,i + 1, ph[i].vork2, &(mut->vork[i + 1]));
		else
			printf("ph[%d] lfork address is different from mut vork[%d]\n",i,i+1);
		i++;
	}
}

void	print_mutex_addr(t_philo *ph, int count, t_mutex *mut)
{
	int	i;

	i = 0;
	while (i < count)
	{	
		printf("Addr vork[%d] is %p\n",i, &mut->vork[i]);
		i++;
	}
	printf("Addr plock is %p\n",&mut->plock);
	printf("Addr dlock is %p\n",&mut->dlock);
	printf("Addr alock is %p\n",&mut->alock);
	printf("compare it with ph mutexes\n");
	i = 0;
	while (i < count)
	{	
		printf("ph[%d] has vork1 Addr: %p\n",ph->tid + 1, ph[i].vork1);
		printf("ph[%d] has vork2 Addr: %p\n",ph->tid + 1, ph[i].vork2);
		printf("ph[%d] has plock Addr: %p\n",ph->tid + 1, ph[i].plock);
		printf("ph[%d] has dlock Addr: %p\n",ph->tid + 1, ph[i].dlock);
		printf("ph[%d] has alock Addr: %p\n",ph->tid + 1, ph[i].alock);
		i++;
	}
}

void	print_sim(t_sim sim)
{

	printf(" sim whodied init value %d, ptr addr %p\n",sim.whodied, (void*)&sim.whodied);
	printf(" sim tdied init value %ld, ptr addr %p\n",sim.tdied, (void*)&sim.tdied);
	printf(" sim active init value %d, ptr addr %p\n",sim.active, (void*)&sim.active);
	printf(" sim alock address %p\n",sim.alock);
	printf(" sim dlock address %p\n",sim.dlock);
}