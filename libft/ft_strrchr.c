/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:15:56 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/15 17:33:48 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (((unsigned char)str[i]) == ((unsigned char)c))
			return (&str[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	// *s == NULL return segmentation fault
	// *s == "\0" return NULL
	//
	// c = '\0' and s !=NULL return ptr to s at '\0' index
	// if no match return NULL
	// if match return s
	// check if s and c cast to unsigned char when comparing
	char *s = "Hello";
	int	c = '\0';
	printf("%p \n",ft_strrchr(s,c));
	printf("%p \n",strrchr(s,c));
	return (0);
}*/
