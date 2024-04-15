/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 22:38:22 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/12 21:44:30 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)s;
	while (i < n)
	{
		arr[i] = c;
		i++;
	}
	return (arr);
}
/*
int	main(void)
{
	int	arr[2];
	size_t	i;
	size_t	num = sizeof(arr);

	printf("the num size %zu\n\n",num);
	//output of c library function
	i = 0;
	memset(arr,127, num);
	while (i < num)
	{
		printf("C lib arr[%zu] is %c\n",i,arr[i]);
		i++;
	}
	//output of my function for comparison
	i = 0;
	ft_memset(arr,127, num);
  while (i < num)
  {
  	printf("My r[%zu] is %c\n",i,arr[i]);
  	i++;
  }
	return (0);
}*/
