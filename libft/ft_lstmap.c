/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:51:10 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/23 13:13:10 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void *(*f)(void *);
void (*del)(void *);
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mylst;
	t_list	*new;

	mylst = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new == NULL)
		{
			ft_lstclear(&mylst, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&mylst, new);
		lst = lst->next;
	}
	return (mylst);
}
/*
void *(*f)(void *);
void (*del)(void *);

void *fun(void *x)
{
	return ("fun");
}

void delete(void *x)
{
	//free(x->content);
	x->content = NULL;
	return ;
}

int	main(void)
{
	t_list	*n;
	t_list	*p;

	n = NULL;
	n = ft_lstnew("one");
	ft_lstadd_back(&n, ft_lstnew("Two"));
	ft_lstadd_back(&n, ft_lstnew("Three"));
	//printf("%s",(char *)n->next->content);
	p = ft_lstmap(n, &fun, delete);
	while (p)
	{
		printf("%s \n",(char *)p->content);
		p = p->next;
	}
	return (0);
}*/
