/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:57:36 by sthiagar          #+#    #+#             */
/*   Updated: 2024/01/31 15:54:24 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_var	*ft_lstnew(char *name, char *val)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (var == NULL)
		return (NULL);
	var->name = name;
	var->value = val;
	var->next = NULL;
	return (var);
}

/*
int	main(void)
{
	t_list	*temp;

	temp = NULL;
	temp = ft_lstnew("This");
	if (temp)
		printf("%s\n",(char *)temp->num);
	return (0);
}*/
