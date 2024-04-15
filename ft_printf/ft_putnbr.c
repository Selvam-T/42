/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:16:15 by sthiagar          #+#    #+#             */
/*   Updated: 2023/10/02 11:35:15 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(unsigned int n, size_t count)
{
	if (n >= 10)
		count = ft_putnbr(n / 10, count);
	count += ft_putchar((n % 10) + '0');
	return (count);
}
