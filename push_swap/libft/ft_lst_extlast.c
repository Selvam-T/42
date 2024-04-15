/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_extlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:12:08 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/10 17:14:21 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_extlast(t_list *lst)
{
	t_list	*last;

	last = NULL;
	if (lst != NULL)
	{
		last = ft_lstlast(lst);
		ft_lstbeforelast(lst)->next = NULL;
		return (last);
	}
	return (NULL);
}
