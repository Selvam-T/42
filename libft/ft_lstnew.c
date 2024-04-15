/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:57:36 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/21 13:12:49 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n;

	n = malloc(sizeof(t_list));
	if (n == NULL)
		return (NULL);
	n->content = content;
	n->next = NULL;
	return (n);
}
/*
int	main(void)
{
	t_list	*temp;

	temp = NULL;
	temp = ft_lstnew("This");
	if (temp)
		printf("%s\n",(char *)temp->content);
	return (0);
}*/
