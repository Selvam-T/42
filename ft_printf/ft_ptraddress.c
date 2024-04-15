/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptraddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:36:15 by sthiagar          #+#    #+#             */
/*   Updated: 2023/10/02 14:49:24 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ptraddress(void *decimal)
{
	size_t				count;
	unsigned long long	num;

	num = (unsigned long long)decimal;
	count = 0;
	if (decimal == 0)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	return (count + ft_hexadecimal(num, 97));
}
/*
int	main(void)
{
	char *s = "this";

	int i = ft_ptraddress((uintptr_t)s);
	printf("\n");
	int j = printf("%p",s);
	printf("\n ft_p %d, p %d \n",i,j);
	return (0);
}*/
