/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_multisort_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:14:13 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/26 13:20:17 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rot_top_to_base(t_list **stka, t_list **stkb, int a_cost, int b_cost)
{
	int	ra;
	int	rb;
	int	rr;

	ra = 0;
	rb = 0;
	rr = 0;
	if (a_cost >= b_cost)
	{
		rr = b_cost;
		ra = a_cost - b_cost;
		one_stk_rotate(stka, "ra", ra);
	}
	else if (b_cost > a_cost)
	{
		rr = a_cost;
		rb = b_cost - a_cost;
		one_stk_rotate(stkb, "rb", rb);
	}
	two_stks_rotate(stka, stkb, "rr", rr);
}

void	rot_base_to_top(t_list **stka, t_list **stkb, int a_cost, int b_cost)
{
	int	rra;
	int	rrb;
	int	rrr;

	rra = 0;
	rrb = 0;
	rrr = 0;
	if (a_cost >= b_cost)
	{
		rrr = b_cost;
		rra = a_cost - b_cost;
		one_stk_rotate(stka, "rra", rra);
	}
	else if (b_cost > a_cost)
	{
		rrr = a_cost;
		rrb = b_cost - a_cost;
		one_stk_rotate(stkb, "rrb", rrb);
	}
	two_stks_rotate(stka, stkb, "rrr", rrr);
}

void	rot_alternate1(t_list **stka, t_list **stkb, int a_cost, int b_cost)
{
	int	ra;
	int	rrb;

	ra = a_cost;
	rrb = b_cost;
	one_stk_rotate(stka, "ra", ra);
	one_stk_rotate(stkb, "rrb", rrb);
}

void	rot_alternate2(t_list **stka, t_list **stkb, int a_cost, int b_cost)
{
	int	rra;
	int	rb;

	rra = a_cost;
	rb = b_cost;
	one_stk_rotate(stka, "rra", rra);
	one_stk_rotate(stkb, "rb", rb);
}
