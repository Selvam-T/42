/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:24:29 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/01 17:54:49 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_if_sorted_or_null(t_list *stka)
{
	t_list	*cur;
	t_list	*next;

	cur = stka;
	if (cur != NULL)
	{
		next = cur->next;
		while (next != NULL && cur->num < next->num)
		{
			cur = next;
			next = next->next;
		}
		if (next == NULL)
		{
			free_lst(stka);
			exit(EXIT_FAILURE);
		}
	}
	else
		handle_error(NULL, NULL);
}

static int	error_check(t_list *lst, char *str, char **str_arr)
{
	long	num;
	t_list	*head;

	head = lst;
	if (!ft_is_strdigit(str))
		handle_error(lst, str_arr);
	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		handle_error(lst, str_arr);
	while (lst != NULL)
	{
		if (num == lst->num)
			handle_error(head, str_arr);
		lst = lst->next;
	}
	return (num);
}

static t_list	*make_lst(t_list *head, char **str_arr)
{
	int		j;
	int		num;
	t_list	*node;

	j = 0;
	while (str_arr[j] != NULL)
	{
		num = error_check(head, str_arr[j], str_arr);
		node = ft_lstnew(num);
		if (node == NULL)
			handle_error(head, str_arr);
		ft_lstadd_back(&head, node);
		j++;
	}
	return (head);
}

static t_list	*get_lst(int argc, char **argv)
{
	int		i;
	t_list	*head;
	char	**str_arr;

	i = 1;
	head = NULL;
	str_arr = NULL;
	while (i < argc)
	{
		str_arr = ft_split(argv[i], 32);
		if (str_arr == NULL)// correct: if(str_arr == NULL || str_arr[0] == NULL)
			handle_error(head, str_arr);
		head = make_lst(head, str_arr);
		free_str_arr(str_arr);
		i++;
	}
	rank_nums(head);
	return (head);
}

int	main(int argc, char *argv[])
{
	t_list	*stka;
	int		count;

	count = 0;
	stka = NULL;
	if (argc < 2)
		return (0);
	else
	{
		stka = get_lst(argc, argv);
		exit_if_sorted_or_null(stka);
		count = lst_count(stka);
		if (count <= 3)
			sort3(&stka);
		else if (count > 3 && count <= 6)
			sort6(&stka, count);
		else
			multisort(&stka);
		free_lst(stka);
	}
	return (0);
}
