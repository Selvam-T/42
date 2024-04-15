/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:38:23 by sthiagar          #+#    #+#             */
/*   Updated: 2023/12/18 19:38:48 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	while (lst != NULL)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

void	free_str_arr(char **str_arr)
{
	int	i;

	if (str_arr != NULL)
	{
		i = 0;
		while (str_arr[i] != NULL)
		{
			free (str_arr[i]);
			str_arr[i] = NULL;
			i++;
		}
	}
	free (str_arr);
	str_arr = NULL;
}

void	handle_error(t_list *lst, char **str_arr)
{
	free_lst(lst);
	free_str_arr(str_arr);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	lst_count(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	rank_nums(t_list *lst)
{
	t_list	*outer;
	t_list	*inner;

	outer = lst;
	while (outer != NULL)
	{
		inner = lst;
		while (inner != NULL)
		{
			if (outer->num > inner->num)
				outer->rank += 1;
			inner = inner->next;
		}
		outer = outer->next;
	}
}
