/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_multisort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:21:39 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 14:06:05 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_sort_stka_to_stkb(t_list **stka, t_list **stkb)
{
	int	a_cost;
	int	b_cost;

	a_cost = 0;
	b_cost = 0;
	get_min_pair(stka, stkb, &a_cost, &b_cost);
	if (a_cost >= 0 && b_cost >= 0)
		rot_top_to_base(stka, stkb, a_cost, b_cost);
	else if (a_cost < 0 && b_cost < 0)
		rot_base_to_top(stka, stkb, (a_cost * -1), (b_cost * -1));
	else if (a_cost >= 0 && b_cost < 0)
		rot_alternate1(stka, stkb, a_cost, (b_cost * -1));
	else if (a_cost < 0 && b_cost >= 0)
		rot_alternate2(stka, stkb, (a_cost * -1), b_cost);
	twostacks_operation(stka, stkb, "pb");
}

static void	move_sorted_stkb_to_stka(t_list **stka, t_list **stkb)
{
	int	a_cost;

	a_cost = get_corresponding_a_cost(stka, (*stkb)->rank);
	if (a_cost < 0)
		one_stk_rotate(stka, "rra", (a_cost * -1));
	else if (a_cost > 0)
		one_stk_rotate(stka, "ra", a_cost);
	twostacks_operation(stka, stkb, "pa");
}

static void	final_order_sort(t_list **stka)
{
	t_list		*cur;
	int			rotate;

	set_rotation_cost(*stka);
	cur = *stka;
	while (cur != NULL)
	{
		if (cur->rank == 1)
			rotate = cur->rot_cost;
		cur = cur->next;
	}
	if (rotate < 0)
		one_stk_rotate(stka, "rra", (rotate * -1));
	else if (rotate > 0)
		one_stk_rotate(stka, "ra", rotate);
}

static t_list	*init_stkb(t_list **stka)
{
	t_list	*stkb;

	stkb = NULL;
	twostacks_operation(stka, &stkb, "pb");
	twostacks_operation(stka, &stkb, "pb");
	return (stkb);
}

void	multisort(t_list **stka)
{
	t_list		*stkb;
	int			counta;

	stkb = init_stkb(stka);
	counta = set_rotation_cost(*stka);
	set_rotation_cost(stkb);
	while (counta > 3)
	{
		move_sort_stka_to_stkb(stka, &stkb);
		counta = set_rotation_cost(*stka);
		set_rotation_cost(stkb);
	}
	sort3(stka);
	while (stkb != NULL)
	{
		set_rotation_cost(*stka);
		move_sorted_stkb_to_stka(stka, &stkb);
	}
	final_order_sort(stka);
}
