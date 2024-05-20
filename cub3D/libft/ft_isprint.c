/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:49:28 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/12 20:14:12 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
/*
#include <ctype.h>

int	main(void)
{
	printf("%d\n",ft_isprint(32));
	printf("%d\n",ft_isprint(100));
	printf("%d\n",ft_isprint(126));
	printf("%d\n",isprint(32));
	printf("%d\n",isprint(100));
	printf("%d\n",isprint(126));
	return (0);
}*/
