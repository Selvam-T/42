/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:20:29 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/23 14:22:24 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(long n)
{
	int	count;

	count = 0;
	if (n < 0)
		n *= -1;
	else if (n == 0)
		count = 1;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static int	multiplier(int digit)
{
	int	mult;

	mult = 1;
	while (digit > 1)
	{
		mult *= 10;
		digit--;
	}
	return (mult);
}

static char	*str(char *arr, int neg, long num)
{
	int	i;
	int	digit;
	int	mult;
	int	num_digits;

	i = 0;
	num_digits = digit_count(num);
	if (neg && num_digits > 0)
	{
		arr[i] = '-';
		i++;
	}
	while (num_digits > 0)
	{
		mult = multiplier(num_digits);
		digit = num / mult;
		arr[i] = digit + 48;
		num = num - (digit * mult);
		i++;
		num_digits--;
	}
	arr[i] = 0;
	return (arr);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		num_digits;
	long	num;
	char	*arr;

	num = (long)n;
	neg = 0;
	num_digits = digit_count(num);
	if (num < 0)
	{
		neg = 1;
		num *= -1;
		arr = (char *)malloc((num_digits + 2) * sizeof(char));
	}
	else
	{
		arr = (char *)malloc((num_digits + 1) * sizeof(char));
	}
	if (arr == NULL)
		return (NULL);
	return (str(arr, neg, num));
}
/*
int	main(void)
{
	printf("%s \n",ft_itoa(-2147483648));
	printf("%s \n",ft_itoa(00002));
	printf("%s \n",ft_itoa(2147483647));
	return (0);
}*/
