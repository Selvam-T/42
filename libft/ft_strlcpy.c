/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:34:48 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/13 16:25:31 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	n;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		if (src_len < size)
			n = src_len;
		else
			n = size - 1;
		ft_memcpy(dst, src, n);
		dst[n] = '\0';
	}
	return (src_len);
}
/*
int	main(void)
{
	char	dst[0]; //for testing purpose, change array size
	//char	*src = "lorem";
	size_t	i;
	//int	n = 15; //buffer size to write to

	//i = ft_strlcpy(dst, src, n * sizeof(char));
	i = ft_strlcpy(dst,"lorem ipsum dolor sit amet", 0);
	printf("My func > strlcpy return value %zu \n", i);
	return (0);
}*/
/*
int	main(void)
{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
 	char buff1[0xF00];
	size_t	i;

 	memset(buff1, 'A', sizeof(buff1) - 1);
 	buff1[sizeof(buff1) - 1] = 0;
 	ft_strlcpy(buff1, str, sizeof(buff1));
	i = 0;
	while (buff1[i] != '\0')
	{
		printf("%c \n",buff1[i]);
		i++;
	}
	return(0);
}*/
