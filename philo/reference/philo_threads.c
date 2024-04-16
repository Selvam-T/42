/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:47:51 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/05 14:09:28 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

//create a new thread
int	create_newthread()
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, threadfn1, NULL) != 0)
		handle_error();
	// Wait for the thread to finish (not typically done in practice)
    	pthread_join(tid, NULL);
	return (0);
}

//create a new detached thread
int	detach_thread()
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, threadfn2, NULL) != 0)
		handle_error();
	pthread_detach(tid);
	return (0);
}

//create a new detached thread with attributes
int	detach_thread_attr()
{
	pthread_t	tid;
	pthread_attr_t	attr;
	
	//Initialize thread attributes
	pthread_attr_init(&attr);

	//set the thread as detached
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

	if (pthread_create(&tid, &attr, threadfn2, NULL) != 0)
		handle_error();
	//pthread_detach(tid);
	
	//clean up thread attributes
	pthread_attr_destroy(&attr);
	return (0);
}


int	init_thread(pthread_mutex_t mymutex)
{

	if (pthread_mutex_init(&mymutex, NULL) != 0)
		handle_error();
		
	//pthread_mutex_destroy(&mymutex);
	return (1);
}

int	destroy_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
		handle_error();
	return (1);
}

int	lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
		handle_error();
	return (1);
}

int	unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
		handle_error();
	return (1);
}

//print error message after join to determine the type of error
void	thread_join(pthread_t thread)
{
	// Assuming no need for return value from the joined thread
	int ret = pthread_join(thread, NULL); 

	if (ret == 0)
	printf("pthread_join() succeeded.\n");
	else 
	{
		printf("pthread_join() failed with error code: %d\n", ret);
		if (ret == ESRCH)
		    printf("No such thread.\n");
		else if (ret == EINVAL)
		    printf("Invalid argument.\n");
		else if (ret == EDEADLK)
			printf("Deadlock. Thread waits for itself, or threads waiting for eachother.\n");
		else
	    		printf("Unknown error.\n");
	}

}
