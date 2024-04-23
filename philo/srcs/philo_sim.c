/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:12:29 by sthiagar          #+#    #+#             */
/*   Updated: 2024/04/22 12:12:47 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*num_eat_detach(t_philo *ph)
{
	printf("***\n");//DELETE
	printf("ph[%d], num_meals [%d] \n", ph->tid, ph->num_meals);
	if (ph->num_meals >= ph->info.numeat)
	{
		printf("num meals [%d] >= num eat [%d]. Detach ph[%d]\n", \
			ph->num_meals, ph->info.numeat, ph->tid);
		pthread_mutex_lock(&(ph->alock));
			*(ph->actvph) -= 1;
		pthread_mutex_unlock(&(ph->alock));
		pthread_detach(ph->td);
		return (NULL); //exit? ERROR HANDLE
	}
	else //DELETE
		printf("num meals [%d] < num eat [%d]. Don't detach ph[%d]\n", \
			ph->num_meals, ph->info.numeat, ph->tid);
	printf("***\n");
	return (NULL);
}

void	*sim_routine(void *arg)
{
	long		timerm;
	t_philo		*ph;
	
	ph = (t_philo *)arg;

	while (1)
	{
//i must check if ttdie is crossed
//update dead flag, remember to LOCK, UNLOCK dlock

		//IF NUMEALS >= NUM EAT ---> DETACH_THREAD, RETURN
		printf("ph[%d] thread begins.\n", ph->tid);
		if (ph->info.numeat != -1)
			num_eat_detach(ph);
		
		//EATING
		eating(ph);
		
		//SLEEPING-->I lock print function in print_status()
		print_status(get_time_ms(), ph, "is sleeping");
		usleep2(ph->info.ttsleep);

		//THINKING-
		timerm = ph->next_meal - get_time_ms();
		print_status(get_time_ms(), ph, "is thinking");
		usleep2(timerm);
	}
	return (NULL);
}

/*
void	sim_monitor(t_philo *ph)
{
	
}*/

int	sim_activity(t_philo *ph, t_mutex m, int count)
{
	int	i;
	i = 0;
	while (i < count)
	{
		printf("create thread for ph [%d]\n",ph[i].tid);
		if (pthread_create(&(ph[i].td), NULL, sim_routine, (void *)&(ph[i])) != 0)
			return (-1);
		i++;
	}
	
	//	sim_monitor
	while (1)
	{
		
		//KIV number of threads still active
		if (m.actvph == 0)
		{
			printf("ALL THREADS have detached \n");
			break;
		}
		else
			printf("%d THREADS still active\n",m.actvph);
		
		//KIV dead flag
		if (m.dead == 1)
		{
			printf("SOMEONE has died \n");
			break;
		}
		else
			printf("EVERYONE is alive\n");

	}
	
	//join thread
	i = 0;
	while (i < count)
	{
		printf("join ph [%d]\n",i);
		if (pthread_join(ph[i].td, NULL) != 0)
			return (-1);
		i++;
	}
	return(0);
}


/*
int sim_activity(t_philo *ph, t_mutex m, int count) {
    int i = 0;
    // Create threads
    while (i < count) {
        printf("create thread for ph [%d]\n", ph[i].tid);
        if (pthread_create(&(ph[i].td), NULL, sim_routine, (void *)&(ph[i])) != 0) {
            // If pthread_create fails, return -1 immediately
            return (-1);
        }
        i++;
    }
    
    // Monitor threads
    int all_detached = 0;
    while (!all_detached) {
        all_detached = 1;
        int i = 0;
        while (i < count) {
            if (pthread_join(ph[i].td, NULL) != 0) {
                // If pthread_join fails, return -1 immediately
                return (-1);
            }
            if (ph[i].td != 0) {
                // Thread is still active
                all_detached = 0;
                break;
            }
            i++;
        }
        if (all_detached) {
            printf("ALL THREADS have detached \n");
            break;
        }

        // Print status of threads
        printf("%d THREADS still active\n", m.actvph);
        
        // Check the dead flag
        if (m.dead == 1) {
            printf("SOMEONE has died \n");
            break;
        } else {
            printf("EVERYONE is alive\n");
        }
    }
    
    // Join threads
    i = 0;
    while (i < count) {
        printf("join ph [%d]\n", i);
        if (pthread_join(ph[i].td, NULL) != 0) {
            // If pthread_join fails, return -1 immediately
            return (-1);
        }
        i++;
    }
    
    return 0;
}*/