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

int 	validate_input(int argc, char **argv)
{
	int 	count;

	if (argc < 5 || argc > 6)
		return (handle_error1("Error: Incorrect No. of arguments"));
	if (is_positive_digit(argc, argv) == -1)
			return (handle_error1("Error: not a valid digit"));
	count = ft_atoi(argv[1]);
	if (count == 0 || count > 200)
		return (handle_error1("Error: Invalid No. of Philosophers"));
	return (count);
}

int	main(int argc, char *argv[])
{
	int 		count;
	t_philo		*ph;
	t_general	info;
	t_mutex		mtx;

	count = validate_input(argc, argv);
	if (count == -1)
		return (-1);
	if (init_mutex(&mtx, count) == -1)
		return (-1);
	init_general_info(&info, argc, argv);
	ph = init_threads(&info, &mtx, count);
	if (ph == NULL)
		return (handle_error1("Malloc failure"));
	sim_activity(ph, mtx, count);
	free_all(ph, &mtx, count);
	return (0);
}	
