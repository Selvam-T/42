/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:58:51 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/15 13:23:57 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	n;

	n = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size > dst_len)
	{
		if (src_len < size - dst_len -1)
			n = src_len;
		else
			n = size - dst_len - 1;
		ft_memcpy(&dst[dst_len], src, n);
		dst[dst_len + n] = '\0';
		return (dst_len + src_len);
	}
	return (src_len + size);
}
/*
#include <bsd/string.h>

int	main(void)
{

	char *str = "ZZZZZUUUUUKKKKK";
 	//char buff1[0xF00];
	char buff1[10];
	size_t	i;
	//fill n-1 indexs of buff1 with 'A'
 	memset(buff1, 'A', sizeof(buff1) - 5);
 	buff1[sizeof(buff1) - 5] = 0;// null terminate nth index
 	i = ft_strlcat(buff1, str, 6);
	//i = strlcat(buff1, str, 6);

	printf("Buffer value: %s \n",buff1);
	i = 0;
	while (buff1[i] != '\0')
	{
		printf("%c",buff1[i]);
		i++;
	}
	printf("%d \n",buff1[i]);
	printf("i is %zu \n",i);


	size_t i = 0;
	i = ft_strlcat(((void*)0), "abcd", 20);
	printf("My i is %zu \n",i);
	i = strlcat(((void*)0), "abcd", 20);
	printf("C func i is %zu \n",i);
	return(0);
}*/
