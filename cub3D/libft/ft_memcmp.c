/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 14:47:47 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/16 16:42:57 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*str1 = (const char *)s1;
	const char	*str2 = (const char *)s2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	//s1 == NULL --> segmentation fault
	//S2 == NULL --> segmentation fault
	//n = 0 --> return 0;
	//s1 = "thisa", s2 = "this", n = 5 --> return +
	//S1 = "this" and S2 = '\0', n > 0 --> return +
	//s1 = "this", s2 = "thisa", n = 5 --> return -
	//S1 = "\0" and S2 = "this", n > 0 --> return -
	//S1 = '\0' and S2 = '\0', n > 0 --> return 0
	//s1 = "thisa", s2 = "this", n = 4 --> return 0
  // s1 = "atoms\0\0\0\0" , *s2 = "atoms\0abc", n = 8 --> return -97
	char *s1 = "thisa";
 	char *s2 = "\0";
	size_t n;

	n = 5;
	printf("memcpy returns: %d \n",memcmp(s1,s2,n));
	printf("ft_memcpy returns: %d \n",ft_memcmp(s1,s2,n));
	return (0);
}*/
