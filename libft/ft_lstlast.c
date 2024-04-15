/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:12:07 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/21 15:39:18 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*n;

	n = NULL;
	while (lst)
	{
		n = lst;
		lst = lst->next;
	}
	return (n);
}
/*
int	main(void)
{
}*/
