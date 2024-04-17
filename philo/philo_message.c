/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:12:54 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/04 12:13:11 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//printng can experience bottleneck

// A displayed state message should not be mixed up with another message.

// A message announcing a philosopher died should be displayed no more than 10 ms
//after the actual death of the philosopher.

//In someone implementation the printed time is not exactly state change time 
//but the time when the thread got hold of the mutex for printf. So it might have 
//changed state  way earlier than the stamp it prints.

//My implementation was also printing status when forks were released. 
//When I removed that, I was able to make more philosophers eat without dying. 
//(I managed 24 Philos on my home computer, I guess more on school computers!)
//I suppose the frenzy to acquire the printing mutex by threads exiting eat and 
//threads starting eating delayed the threads so much they starved and died.
