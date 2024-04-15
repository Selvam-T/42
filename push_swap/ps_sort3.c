/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:49:37 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/19 14:50:57 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_bcrank(t_list *lst)
{
	t_list	*outer;
	t_list	*inner;

	outer = lst;
	while (outer != NULL)
	{
		outer->bcrank = 1;
		inner = lst;
		while (inner != NULL)
		{
			if (outer->num > inner->num)
				outer->bcrank += 1;
			inner = inner->next;
		}
		outer = outer->next;
	}
}

t_list	*sort3_reverse(t_list **lst)
{
	set_bcrank(*lst);
	if ((*lst)->bcrank == 2 && (*lst)->next->bcrank == 1)
		onestack_operation(lst, "rrb");
	else
	{
		if ((*lst)->bcrank == 3 || (*lst)->bcrank == 2)
			onestack_operation(lst, "sb");
		if ((*lst)->bcrank == 1)
			onestack_operation(lst, "rb");
		if ((*lst)->bcrank == 2)
			onestack_operation(lst, "sb");
	}
	return (*lst);
}

t_list	*sort2_reverse(t_list **lst)
{
	set_bcrank(*lst);
	if ((*lst)->bcrank == 1)
		onestack_operation(lst, "sb");
	return (*lst);
}

t_list	*sort3(t_list **lst)
{
	set_bcrank(*lst);
	if ((*lst)->bcrank == 2 && (*lst)->next->bcrank == 3)
		onestack_operation(lst, "rra");
	else
	{
		if ((*lst)->bcrank == 1 || (*lst)->bcrank == 2)
			onestack_operation(lst, "sa");
		if ((*lst)->bcrank == 3)
			onestack_operation(lst, "ra");
		if ((*lst)->bcrank == 2)
			onestack_operation(lst, "sa");
	}
	return (*lst);
}

t_list	*sort2(t_list **lst)
{
	set_bcrank(*lst);
	if ((*lst)->bcrank == 2)
		onestack_operation(lst, "sa");
	return (*lst);
}
