/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:40:28 by sthiagar          #+#    #+#             */
/*   Updated: 2023/10/02 14:46:37 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hexadecimal(unsigned long long decimal, int c)
{
	char				hex[16];
	int					index;
	unsigned long long	remainder;

	index = 0;
	if (decimal == 0)
		hex[index++] = '0';
	while (decimal > 0)
	{
		remainder = decimal % 16;
		if (remainder < 10)
			hex[index] = remainder + '0';
		else
			hex[index] = remainder - 10 + c;
		decimal /= 16;
		index++;
	}
	hex[index] = '\0';
	return (ft_putstr(hex, 1));
}
/*
int	main(void)
{
	char *s = "";
	unsigned long long addr;
	addr = (unsigned long long)s;

	int a = printf("%p",s);
	printf("p count is %d\n",a);
	size_t b = put_hex(addr);
	printf("ft_p count is %lu\n",b);
	return (0);
}*/
