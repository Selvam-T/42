/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:09:34 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 11:10:39 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char *argv[])
{
	t_sim		sim;
	t_mutex		mtx;
	t_general	info;
	t_philo		*ph;

	ph = NULL;
	sim.count = validated_count(argc, argv);
	if (sim.count == -1)
		return (-1);
	if (init_mutex(&mtx, sim.count) == -1)
		return (-1);
	if (init_sim(&sim, &mtx) == -1)
		return (-1);
	init_general_info(&info, argc, argv, &sim);
	ph = init_philos(&info, &mtx, sim.count);
	if (ph == NULL)
		return (handle_error1("Malloc failure"));
	if (run_simulation(ph, &sim, &(info.tstart)) == -1)
		return (handle_error1("Process failure"));
	free_all(ph, &mtx, sim.count);
	return (0);
}
