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

void	eating(t_program *sim, int i)
{
	//printf("\nph [%d] enters eating(). Requires rfork [%d], lfork [%d]\n",i, \
	//		sim->ph[i].r_vork, sim->ph[i].l_vork);//DELETE
	
	//LOCK right and left forks
	pthread_mutex_lock(&sim->vork[sim->ph[i].r_vork]);
	//printf("%ld ph [%d] has taken a fork [%d]\n",\
	//	get_time_ms(), i, sim->ph[i].r_vork);
	pthread_mutex_lock(&sim->vork[sim->ph[i].l_vork]);
	//printf("%ld ph [%d] has taken a fork [%d]\n",\
	//	get_time_ms(), i, sim->ph[i].l_vork);
	
	//LAST MEAL = GET CUR TIME
	sim->ph[i].last_meal = get_time_ms();
	//if (sim->ph[i].last_meal == -1) //ERROR
		//return (NULL); //ERROR HANDLE
	printf("ph [%d] last meal %ld ms\n",sim->ph[i].tid, sim->ph[i].last_meal);
	//NEXT MEAL = LASTMEAL + TT DIE
	sim->ph[i].next_meal = sim->ph[i].last_meal + sim->ttdie;
	printf("ph [%d] next meal %ld ms\n",sim->ph[i].tid, sim->ph[i].next_meal);

	//PRINT EATING
	//print_status(sim->ph[i].last_meal, sim->ph[i].tid, "is eating");
	printf("\nph[%d] is eating, start_time=> [%ld]\n",sim->ph[i].tid, \
		get_time_ms());
	
	sim->ph[i].num_meals++;
	usleep(sim->tteat * 1000);
	
	//UNLOCK right and left forks
	pthread_mutex_unlock(&sim->vork[sim->ph[i].r_vork]);
	pthread_mutex_unlock(&sim->vork[sim->ph[i].l_vork]);
	//printf("for ph[%d] UNLOCK right fork [%d]\n",i, sim->ph[i].r_vork);//DELETE
	//printf("for ph[%d] UNLOCK left fork [%d]\n",i, sim->ph[i].l_vork);//DELETE
	
	printf("ph [%d] exits eating process\n",i);//DELETE
}

void	*sim_routine(void  *ptr) 
{
	//last meal, next meal, num meals
	int 		i;
	long		timerm;
	t_program	*sim;
	
	sim = (t_program *)ptr;
	i = sim->index;//index of CURRENT ph

	printf("\nph[%d] is executing ...\n",sim->ph[i].tid);

	printf("ph [%d], last_meal=> [%ld], next_meal=> [%ld], (next_meal - curtime)=> [%ld]\n",\
		sim->ph[i].tid, sim->ph[i].last_meal, sim->ph[i].next_meal, \
		sim->ph[i].next_meal - get_time_ms());
	printf("ph [%d], num_meals_eaten=> [%d], (Max_meals_eat - his_meals_eat)=> [%d]\n",\
		sim->ph[i].tid, sim->ph[i].num_meals, sim->numeat - sim->ph[i].num_meals);
	
	//IF NUMEALS >= NUM EAT ---> DETACH_THREAD, RETURN
	if (sim->ph[i].num_meals >= sim->numeat)
	{
		printf("num meals [%d] >= num eat [%d]. Detach Thread [%d]\n", \
			sim->ph[i].num_meals, sim->numeat, i);
		pthread_detach(sim->ph[i].td);
		return (NULL); //exit? ERROR HANDLE
	}	
	//eating process
	eating(sim, i);
	
	//sleeping process
	//print_status(get_time_ms(), sim->ph[i].tid, "is sleeping");
	usleep(sim->ttsleep * 1000);

	//thinking process
	timerm = sim->ph[i].next_meal - get_time_ms();
	//print_status(get_time_ms(), sim->ph[i].tid, "is thinking");
	usleep(timerm * 1000);
	
	return (NULL);
}

int	sim_monitor(t_program **sim)
{
	(void)sim;
	//MONITOR() will do this. NOT done here
	//IF NEXT MEAL < CURTIME --> LOCK END 
	// END = 1, UNLOCK END
	return (0);
}

int	sim_activity(t_program *sim)
{
	int	i;

	//create thread -->td, tid
	i = 0;
	while (i < sim->count)
	{
		//printf("create thread for ph [%d]\n",i);
		sim->ph[i].tid = i;
		sim->index = i;
		if (pthread_create(&sim->ph[i].td, NULL, \
			sim_routine, (void *)sim) != 0)
			return (-1);
		i++;
	}
	
	//while (1)
	//	sim_monitor(sim);

	//join thread
	i = 0;
	while (i < sim->count)
	{
		//printf("join ph [%d]\n",i);
		if (pthread_join(sim->ph[i].td, NULL) != 0)
			return (-1);
		i++;
	}
	return(0);
}

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
