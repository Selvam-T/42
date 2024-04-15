/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 11:28:28 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/16 17:17:36 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ((unsigned char)c))
			return (&((void *)s)[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	// *s == NULL , return segmentation fault
	// s[25]; , return segmentation fault
	// match, return ptr to index
	// s[25] == "\0", c == '\0', return s at '\0' index
	// s[25] == "Hello", c == '\0', n = 2, return s at '\0' index
	// no match , return NULL
	// n = 0, return NULL
	// n > strlen(s), return NULL
	// s[25] == "\0" and c == 'a' , n > 0 return NULL

	char test[15] = ":(){ :|: & };:";
	int k = '\xde';

	//char s[25] = "Selvam";
	//int	c = 'e';
	size_t n = 15;
	char	*r;
	//printf("%p \n",ft_memchr(s,c,n));
	r = memchr(test,k,n);
	printf("memcpy addr %p, str %s \n",r,r);
	r = ft_memchr(test,k,n);
	printf("ft_memcpy addr %p, str %s \n",r,r);
	return (0);
}*/
