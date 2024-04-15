/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbef_chr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 22:49:28 by sthiagar          #+#    #+#             */
/*   Updated: 2024/03/20 22:49:42 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strbef_chr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	if (s == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (((unsigned char)str[i]) == ((unsigned char)c))
			return (ft_substr(str, 0, i));
		i++;
	}
	if ((unsigned char)c == 0)
		return (ft_strdup(str));
	return (NULL);
}
/*
int	main()
{
	printf("%s\n",ft_strbef_chr("APPLECOON",'P'));
	return (0);
}*/
