/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:34:53 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 12:35:35 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	twostacks_operation(t_list **lst_a, t_list **lst_b, char *str)
{
	if ((ft_strncmp(str, "pa", 2) == 0) && (*lst_b != NULL))
		push(lst_a, lst_b);
	else if ((ft_strncmp(str, "pb", 2) == 0) && (*lst_a != NULL))
		push(lst_b, lst_a);
	if ((lst_count(*lst_a) > 1) && (ft_strncmp(str, "ss", 3) == 0))
		swap(lst_a);
	if ((lst_count(*lst_b) > 1) && (ft_strncmp(str, "ss", 3) == 0))
		swap(lst_b);
	if ((lst_count(*lst_a) > 1) && (ft_strncmp(str, "rrr", 3) == 0))
		reverse_rotate(lst_a);
	else if ((lst_count(*lst_a) > 1) && (ft_strncmp(str, "rr", 2) == 0))
		rotate(lst_a);
	if ((lst_count(*lst_b) > 1) && (ft_strncmp(str, "rrr", 3) == 0))
		reverse_rotate(lst_b);
	else if ((lst_count(*lst_b) > 1) && (ft_strncmp(str, "rr", 2) == 0))
		rotate(lst_b);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
}

void	onestack_operation(t_list **lst, char *str)
{
	if (lst_count(*lst) > 1)
	{
		if ((ft_strncmp(str, "sa", 3) == 0) || \
			(ft_strncmp(str, "sb", 3) == 0))
			swap(lst);
		else if ((ft_strncmp(str, "ra", 2) == 0) || \
			(ft_strncmp(str, "rb", 2) == 0))
			rotate(lst);
		else if ((ft_strncmp(str, "rra", 3) == 0) || \
			(ft_strncmp(str, "rrb", 3) == 0))
			reverse_rotate(lst);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
}
