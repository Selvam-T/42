/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:33:23 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/20 17:12:35 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char (*f)(unsigned int, char);

char	test(unsigned int i, char c)
{
	return (c + i);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*arr;

	arr = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
/*
int	main(void)
{
	char const *s = "abc";
	printf("%s ",ft_strmapi(s,test));
	return (0);
}*/
