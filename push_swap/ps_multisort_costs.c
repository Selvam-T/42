/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_multisort_costs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:43:42 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 13:46:59 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rot_cost_stkb_max(t_list **stkb)
{
	t_list	*bptr;
	t_list	*maxb;

	bptr = *stkb;
	maxb = bptr;
	while (bptr != NULL)
	{
		if (maxb->rank < bptr->rank)
			maxb = bptr;
		bptr = bptr->next;
	}
	return (maxb->rot_cost);
}

static int	rot_cost_stka_min(t_list **stka)
{
	t_list	*aptr;
	t_list	*mina;

	aptr = *stka;
	mina = aptr;
	while (aptr != NULL)
	{
		if (mina->rank > aptr->rank)
			mina = aptr;
		aptr = aptr->next;
	}
	return (mina->rot_cost);
}

int	get_corresponding_b_cost(t_list **stkb, int a_rank)
{
	t_list	*ptr_b;
	t_list	*target;

	ptr_b = *stkb;
	target = NULL;
	while (ptr_b != NULL)
	{
		if (a_rank > ptr_b->rank)
		{
			if (target == NULL || ptr_b->rank > target->rank)
				target = ptr_b;
		}
		ptr_b = ptr_b->next;
	}
	if (target == NULL)
		return (rot_cost_stkb_max(stkb));
	return (target->rot_cost);
}

int	get_corresponding_a_cost(t_list **stka, int b_rank)
{
	t_list	*ptr_a;
	t_list	*target;

	ptr_a = *stka;
	target = NULL;
	while (ptr_a != NULL)
	{
		if (b_rank < ptr_a->rank)
		{
			if (target == NULL || ptr_a->rank < target->rank)
				target = ptr_a;
		}
		ptr_a = ptr_a->next;
	}
	if (target == NULL)
		return (rot_cost_stka_min(stka));
	return (target->rot_cost);
}

int	set_rotation_cost(t_list *lst)
{
	t_list	*cur;
	int		count;
	int		median;
	int		i;

	cur = lst;
	count = lst_count(lst);
	median = (count / 2) + 1;
	i = 1;
	while (i <= median)
	{
		cur->rot_cost = i - 1;
		cur = cur->next;
		i++;
	}
	while (i <= count)
	{
		cur->rot_cost = (count - i + 1) * -1;
		cur = cur->next;
		i++;
	}
	return (count);
}
