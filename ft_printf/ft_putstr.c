/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 15:51:49 by sthiagar          #+#    #+#             */
/*   Updated: 2023/10/02 11:35:30 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(char *s, int reverse)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	if (s == NULL)
	{
		count += write (1, "(null)", 6);
		return (count);
	}
	if (reverse)
	{
		index = ft_strlen(s) - 1;
		while (index >= 0)
			count += ft_putchar(s[index--]);
	}
	else
	{
		while (s[count] != '\0')
			count += ft_putchar(s[count]);
	}
	return (count);
}
