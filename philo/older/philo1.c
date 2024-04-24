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
	t_program	*sim;
	int		status;	

	sim = (t_program *)malloc(sizeof(t_program) * 1);
	if (sim == NULL)
		return (-1);
	sim->vork = NULL;
	sim->ph = NULL;
	if (argc < 5 || argc > 6)
		return (free_philo(&sim));
	else
	{
		status = init_sim(&sim, argc, argv);
		if (status == -1)
			return (free_philo(&sim));
	}
	//if (TEST == 1)
		//test_print(sim);
	sim_activity(sim);
	//free_philo(&sim);
	return (0);
}	
