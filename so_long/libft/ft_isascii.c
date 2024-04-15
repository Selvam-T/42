/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 12:04:36 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/12 20:12:39 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
/*
#include <ctype.h>

int     main(void)
{
	printf("%d\n",ft_isascii(127));
        printf("%d\n",isascii(127));
	printf("%d\n",ft_isascii(128));
        printf("%d\n",isascii(128));
        return (0);
}*/
