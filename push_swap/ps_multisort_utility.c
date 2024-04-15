/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_multisort_utility.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 10:23:52 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 13:34:31 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_move_cost(int a_rot_cost, int b_rot_cost)
{
	int	move_cost;

	move_cost = 0;
	if (a_rot_cost >= 0 && b_rot_cost >= 0)
	{
		if (a_rot_cost > b_rot_cost)
			move_cost = a_rot_cost;
		else
			move_cost = b_rot_cost;
	}
	else if (a_rot_cost < 0 && b_rot_cost < 0)
	{
		if ((a_rot_cost * -1) > (b_rot_cost) * -1)
			move_cost = a_rot_cost * -1;
		else
			move_cost = b_rot_cost * -1;
	}
	else if (a_rot_cost >= 0 && b_rot_cost < 0)
		move_cost = a_rot_cost + (b_rot_cost * -1);
	else if (a_rot_cost < 0 && b_rot_cost >= 0)
		move_cost = (a_rot_cost * -1) + b_rot_cost;
	return (move_cost);
}

void	get_min_pair(t_list **stka, t_list **stkb, int *a_cost, int *b_cost)
{
	t_list	*aptr;
	int		b_rot_cost;
	int		cur_move_cost;
	int		low_move_cost;

	b_rot_cost = get_corresponding_b_cost(stkb, (*stka)->rank);
	*a_cost = (*stka)->rot_cost;
	*b_cost = b_rot_cost;
	cur_move_cost = get_move_cost(*a_cost, *b_cost);
	if (cur_move_cost == 0 || cur_move_cost == 1)
		return ;
	low_move_cost = cur_move_cost;
	aptr = (*stka)->next;
	while (aptr != NULL)
	{
		b_rot_cost = get_corresponding_b_cost(stkb, aptr->rank);
		cur_move_cost = get_move_cost(aptr->rot_cost, b_rot_cost);
		if (cur_move_cost < low_move_cost)
		{
			low_move_cost = cur_move_cost;
			*a_cost = aptr->rot_cost;
			*b_cost = b_rot_cost;
		}
		aptr = aptr->next;
	}
}

void	one_stk_rotate(t_list **stk, char *op, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		onestack_operation(stk, op);
		i++;
	}
}

void	two_stks_rotate(t_list **stka, t_list **stkb, char *op, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		twostacks_operation(stka, stkb, op);
		i++;
	}
}
