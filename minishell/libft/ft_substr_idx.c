/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_idx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 12:20:36 by sthiagar          #+#    #+#             */
/*   Updated: 2024/03/07 12:20:48 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr_idx(const char *s, int c, int *ind)
{
	char	*str;

	*ind = 0;
	str = (char *)s;
	while (*str)
	{
		if (((unsigned char)*str) == ((unsigned char)c))
			return (str + 1);
		str++;
		*ind += 1;
	}
	if ((unsigned char)c == 0)
		return (str);
	return (NULL);
}
