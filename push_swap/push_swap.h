/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:25:45 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 14:37:26 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>

void	handle_error(t_list *lst, char **str_arr);
void	free_lst(t_list *lst);
void	free_str_arr(char **str_arr);
void	rank_nums(t_list *lst);
int		lst_count(t_list *lst);
void	sort6(t_list **stka, int count);
t_list	*sort3(t_list **lst);
t_list	*sort3_reverse(t_list **lst);
t_list	*sort2_reverse(t_list **lst);
t_list	*sort2(t_list **lst);
void	multisort(t_list **lst);
int		set_rotation_cost(t_list *lst);
void	get_min_pair(t_list **stka, t_list **stkb, int *a_cost, int *b_cost);
int		get_corresponding_a_cost(t_list **stka, int b_rank);
int		get_corresponding_b_cost(t_list **stkb, int a_rank);
void	rot_top_to_base(t_list **stka, t_list **stkb, int a_cost, int b_cost);
void	rot_base_to_top(t_list **stka, t_list **stkb, int a_cost, int b_cost);
void	rot_alternate1(t_list **stka, t_list **stkb, int a_cost, int b_cost);
void	rot_alternate2(t_list **stka, t_list **stkb, int a_cost, int b_cost);
void	one_stk_rotate(t_list **stk, char *op, int num);
void	two_stks_rotate(t_list **stka, t_list **stkb, char *op, int num);
void	swap(t_list **lst);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
void	push(t_list **stka, t_list **stkb);
void	onestack_operation(t_list **lst, char *str);
void	twostacks_operation(t_list **lst_a, t_list **lst_b, char *str);
//to be deleted-------------
//void	print_costs(int arc, int brc, int amc);
//void	print_stack(t_list *lst);
//void	print_both_stacks(t_list *stka, t_list *stkb, char *str);
//void	test1(t_list **lst_a, t_list **lst_b);
//void	check_sorted(t_list *stka);
#endif
