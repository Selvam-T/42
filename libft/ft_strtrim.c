/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:43:29 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/23 13:57:23 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*arr;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[0] != '\0' && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i > 0 && ft_strchr(set, s1[i - 1]))
		i--;
	arr = (char *)ft_calloc((i + 1), sizeof(char));
	if (arr == NULL)
		return (NULL);
	ft_memcpy(arr, s1, i);
	return (arr);
}
/*
int	main(void)
{
	char *arr;
	//for the commented input, i value is weird in the while loop
	char const *s1 = "  \t \t \n   \n\n\n\t";
	char const *set = " \n\t";
	//char	*s1 = "hello  ";
	//char	*set = " ";

	arr = ft_strtrim(s1, set);
	printf("\n output in Main():%s \n",arr);
	printf("strlen is %zu\n",ft_strlen(arr));
	free (arr);
	return(0);
}*/
