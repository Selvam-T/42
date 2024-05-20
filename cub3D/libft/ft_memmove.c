/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 06:51:32 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/15 13:20:16 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src < dest)
	{
		while (n-- > 0)
			((unsigned char *)dest)[n] = ((const unsigned char *)src)[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int	main()//int array
{
	int	arr[10] = {1,2,3,4,5,6,7,8,9,10};

	//create overlapping memory
	int *src = arr;
	int *dest = arr + 3;
	//My function
	ft_memmove(dest,src,2 * sizeof(int));
	for (int i = 0; i < 10; i++)
		printf("My func> %d %d\n",dest[i],src[i]);
	//C lib function
	memmove(dest,src,2 * sizeof(int));
	for (int i = 0; i < 10; i++)
		printf("C lib func> %d %d\n",dest[i],src[i]);
	return (0);
}*/
