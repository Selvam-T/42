/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 19:04:18 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/23 14:25:28 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	(*del)(void*);
*/

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n;
	t_list	*t;

	t = *lst;
	while (t)
	{
		n = t->next;
		del(t->content);
		free(t);
		t = n;
	}
	*lst = NULL;
}
/*
void	del_content(void* n)
{
	//if (n != NULL)
		//free(n->content);
		//n->content = NULL;
	//else
		return ;
}

int	main(void)
{
	t_list	*n;

	n = NULL;
	n = ft_lstnew("one");
	ft_lstadd_back(&n, ft_lstnew("Two"));
	ft_lstadd_back(&n, ft_lstnew("Three"));
	//printf("%s",(char *)n->next->content);
	ft_lstclear(&n, del_content);
}*/
