/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 12:31:21 by sthiagar          #+#    #+#             */
/*   Updated: 2023/10/02 11:34:37 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putint(int n)
{
	size_t			count;
	unsigned int	num;

	count = 0;
	num = (unsigned int)n;
	if (n < 0)
	{
		count += write(1, "-", 1);
		num = n * -1;
	}
	return (ft_putnbr(num, count));
}
/*
int	main(void)
{
	int	i = 1;
	size_t v;

	v = ft_putint(i);
	printf("\n%zu",v);
	return (0);
}*/
