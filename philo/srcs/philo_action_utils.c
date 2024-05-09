/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_action_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 16:29:03 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/03 16:29:17 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

/*
void	print_status(long time, t_philo *ph, char *msg)
{
	pthread_mutex_lock(ph->plock);
		printf("%ld ms ph[%d] %s\n", time, ph->tid + 1, msg);
	pthread_mutex_unlock(ph->plock);
}*/

int		print_ifalive(long time, t_philo *ph, char *msg, long tsleep)
{

	if (someone_died(ph) == 1) //return 0 no action, 1 break
		return (1);
	//print_status(time, ph, msg);
	pthread_mutex_lock(ph->plock);
		printf("%ld ms ph[%d] %s\n", time, ph->tid + 1, msg);
	pthread_mutex_unlock(ph->plock);
	usleep2(tsleep);
	return (0);
}

void	update_simflags(t_philo *ph, long tdied)
{
	//printf("%ld ms ph[%d] B4 dlock addr: %p to WRITE **************\n",\
	//		get_time_ms() - ph->info->tstart, ph->tid, &ph->dlock); //DELETE
	pthread_mutex_lock(ph->dlock);
	*(ph->info->whodied) = ph->tid;
	*(ph->info->tdied) = tdied;
	pthread_mutex_unlock(ph->dlock);
	//printf("%ld ms ph[%d] AFT un-dlock addr: %p to WRITE **************\n",\
	//		get_time_ms() - ph->info->tstart, ph->tid, &ph->dlock); //DELETE
}

int 	is_philo_dead(t_philo *ph) // return -1 error, 1 break, 0 no action
{
	long	curtime;

	curtime = get_time_ms() - ph->info->tstart;
	if (curtime < 0)
		return (-1);
	//printf("ph[%d] compare curtime %ld v next_meal %ld\n",ph->tid, curtime, ph->next_meal);
	if  (ph->next_meal < curtime)
	{
		//printf("%ld ms ph[%d] is about to update his death **************\n", curtime, ph->tid);
		update_simflags(ph, ph->next_meal);//PAST TIME
		return (1);
	}
	return (0);
}


int 	handle_task(t_philo *ph, long ttact, char *msg)
{
	int		ret;
	long	tsleep;
	long	time_now;

	ret = 0;
	tsleep = ttact; //tteat or ttsleep
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	if (msg[4] == 'e')
		ph->next_meal = time_now + ph->info->tteat;//only for eating
	//printf("ph[%d] update next meal = time now %ld + tteat %ld\n",ph->tid, time_now, ph->info->tteat);
	//printf("ph[%d] compare timenow + ttact %ld v next_meal %ld\n",ph->tid, time_now + ttact, ph->next_meal);
	if (time_now + ttact > ph->next_meal)
	{
		tsleep = ph->next_meal - time_now;
		ret = print_ifalive(time_now, ph, msg, tsleep);
		update_simflags(ph, time_now + tsleep);//FUTURE TIME
		return (ret);
	}
	return (print_ifalive(time_now, ph, msg, tsleep));
}
/*
int 	handle_task2(t_philo *ph, long ttact, char *msg, int flag)
{
	int		ret;
	long	tsleep;
	long	time_now;

	ret = 0;
	tsleep = ttact; //tteat or ttsleep
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	if (flag == 'e')
		ph->next_meal = time_now + ph->info->tteat;
	if (time_now + ttact > ph->next_meal)
	{
		tsleep = ph->next_meal - time_now;
		ret = print_ifalive(time_now, ph, msg, tsleep);
		update_simflags(ph, time_now + tsleep);//FUTURE TIME
		return (ret);
	}
	return (print_ifalive(time_now, ph, msg, tsleep));
}*/