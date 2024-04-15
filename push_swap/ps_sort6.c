/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:38:23 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 13:08:22 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pa_push_all(t_list **stka, t_list **stkb)
{
	int	i;
	int	num_count;

	i = 0;
	num_count = lst_count(*stkb);
	while (i < num_count)
	{
		twostacks_operation(stka, stkb, "pa");
		i++;
	}
}

static t_list	*partition(t_list **stka, int total)
{
	int		push;
	t_list	*stkb;

	stkb = NULL;
	push = 0;
	while (push < total - 3)
	{
		if ((*stka)->rank <= total - 3)
		{
			twostacks_operation(stka, &stkb, "pb");
			push++;
		}
		else
			onestack_operation(stka, "ra");
	}
	return (stkb);
}

void	sort6(t_list **stka, int count)
{
	t_list	*stkb;

	stkb = partition(stka, count);
	sort3(stka);
	if (count == 6)
		sort3_reverse(&stkb);
	else if (count == 5)
		sort2_reverse(&stkb);
	pa_push_all(stka, &stkb);
}
