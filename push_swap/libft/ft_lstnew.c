/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:57:36 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 15:54:24 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int num)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (NULL);
	n->num = num;
	n->rank = 1;
	n->bcrank = 1;
	n->rot_cost = 0;
	n->next = NULL;
	return (n);
}
/*
int	main(void)
{
	t_list	*temp;

	temp = NULL;
	temp = ft_lstnew("This");
	if (temp)
		printf("%s\n",(char *)temp->num);
	return (0);
}*/
