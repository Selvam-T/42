/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:05:31 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/10 12:06:27 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst)
{
	t_list	*cur;
	t_list	*next;

	cur = *lst;
	next = cur;
	cur = cur->next;
	next->next = cur->next;
	cur->next = next;
	*lst = cur;
}

void	push(t_list **lst1, t_list **lst2)
{
	t_list	*cur;

	cur = *lst2;
	*lst2 = cur->next;
	cur->next = *lst1;
	*lst1 = cur;
	cur = NULL;
}

void	rotate(t_list **lst)
{
	t_list	*cur;
	t_list	*first;

	cur = *lst;
	first = cur->next;
	ft_lstlast(*lst)->next = cur;
	cur->next = NULL;
	*lst = first;
}

void	reverse_rotate(t_list **lst)
{
	t_list	*cur;
	t_list	*last;

	cur = *lst;
	last = ft_lstlast(*lst);
	last->next = *lst;
	while (cur != NULL)
	{
		if (cur->next == last)
			cur->next = NULL;
		cur = cur->next;
	}
	*lst = last;
}
