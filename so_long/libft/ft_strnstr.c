/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:55:04 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/16 19:46:57 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <bsd/string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (*big != '\0' && i < len)
	{
		ptr = (char *)big;
		j = 0;
		while (little[j] != '\0' && *ptr == little[j] && i + j < len)
		{
			j++;
			ptr++;
		}
		if (little[j] == '\0')
			return ((char *)big);
		i++;
		big++;
	}
	return (NULL);
}
/*
int	main(void)
{
	// little = "" --> return big
	// little match in first len chars of big, return ptr to 1st char
	// little not match in first len chars of big, return null
	char	*big = "abc";
	char	*little = "xyz";
	size_t	len;
	char	*r;

	len = 0;
	r = strnstr(big,little,len);
	//r = strnstr(((void*)0), "fake", 3);
	printf("strnstr: %s \n",r);
	r = ft_strnstr(big,little,len);
	//r = ft_strnstr(((void*)0), "fake", 3);
	printf("ft_strnstr: %s \n",r);
}*/
