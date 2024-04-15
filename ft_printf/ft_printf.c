/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 15:14:39 by sthiagar          #+#    #+#             */
/*   Updated: 2023/10/02 14:12:19 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_specs(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == '%')
		return (ft_putchar(c));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *), 0));
	else if (c == 'd' || c == 'i')
		return (ft_putint(va_arg(ap, int)));
	else if (c == 'p')
		return (ft_ptraddress(va_arg(ap, void *)));
	else if (c == 'x')
		return (ft_hexadecimal(va_arg(ap, unsigned int), 97));
	else if (c == 'X')
		return (ft_hexadecimal(va_arg(ap, unsigned int), 65));
	else if (c == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int), 0));
	return (0);
}

int	ft_printf(const char *args, ...)
{
	const char	*ptr;
	int			count;
	va_list		ap;

	va_start(ap, args);
	ptr = args;
	count = 0;
	while (*ptr != 0)
	{
		if (*ptr == '%')
		{
			ptr++;
			count += printf_specs(ap, *ptr);
		}
		else
			count += ft_putchar(*ptr);
		ptr++;
	}
	va_end(ap);
	return (count);
}
/*
#include <inttypes.h>
int main(void)
{
    int i = printf("%d \n",-2147483647);
    printf("\n");
    int j = ft_printf("%d \n",-2147483647);
    printf("\n");
    printf("p count %d, ft_p count %d\n",i, j);
    return (0);
}*/
