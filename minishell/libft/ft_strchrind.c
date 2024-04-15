/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 00:56:48 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/26 00:58:47 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrind(const char *s, int c, int *ind)
{
	char	*str;

	*ind = 0;
	str = (char *)s;
	while (*str)
	{
		if (((unsigned char)*str) == ((unsigned char)c))
			return (str);
		str++;
		*ind += 1;
	}
	if ((unsigned char)c == 0)
		return (str);
	return (NULL);
}
