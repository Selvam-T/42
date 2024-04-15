/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbeforelast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:40:11 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/10 14:42:49 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstbeforelast(t_list *lst)
{
	t_list	*last;
	t_list	*penultimate;

	last = NULL;
	penultimate = NULL;
	while (lst)
	{
		penultimate = last;
		last = lst;
		lst = lst->next;
	}
	return (penultimate);
}
/*
int	main(void)
{
}*/
