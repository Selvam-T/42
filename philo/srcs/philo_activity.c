/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_activity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 14:24:21 by sthiagar          #+#    #+#             */
/*   Updated: 2024/05/11 14:24:35 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_eats(t_philo *ph)
{
	int	flag;

	flag = collect_fork1(ph);
	if (flag != 0)
		return (flag);
	flag = collect_fork2(ph);
	if (flag != 0)
		return (flag);
	flag = collect_food(ph);
	if (flag != 0)
		return (flag);
	flag = drop_fork_tally_meal(ph);
	if (flag != 0)
		return (flag);
	return (0);
}

int	philo_sleeps(t_philo *ph)
{
	if (someone_died(ph) == 1)
		return (1);
	return (sleeping(ph));
}

int	philo_thinks(t_philo *ph)
{
	long	time_now;
	int		tsleep;

	tsleep = 1;
	if (ph->info->count % 2 == 0)
		tsleep = 0;
	if (someone_died(ph) == 1)
		return (1);
	time_now = get_time_ms() - ph->info->tstart;
	if (time_now == -1)
		return (-1);
	return (print_ifalive(time_now, ph, "is thinking", tsleep));
}
