/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:40:09 by sthiagar          #+#    #+#             */
/*   Updated: 2023/09/23 14:27:12 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;

	i = 0;
	while (s != NULL && *s)
	{
		if (*s == c)
			s++;
		else
		{
			i++;
			s = ft_strchr(s, c);
		}
	}
	return (i);
}

static char	**free_arr(char **arr, size_t i)
{
	while (i--)
		free (arr[i]);
	free (arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**arr;
	char const	*start;

	i = 0;
	arr = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (arr == NULL || !s)
		return (NULL);
	while (s != NULL && *s)
	{
		if (*s != c)
		{
			start = s;
			s = ft_strchr(s, c);
			if (s == NULL)
				s = start + ft_strlen(start);
			arr[i++] = ft_substr(start, 0, s - start);
			if (arr[i - 1] == NULL)
				return (free_arr(arr, i));
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
/*
int	main (void)
{
	char	**s;
	//s = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
	//s = ft_split("\11\11\11\11hello!\11\11\11\11", '\11');
	//s = ft_split("", 'a');
	//s = ft_split("ggggggggggg", 'g');
	//s = ft_split("nonempty", '\0');
	//s = ft_split("one+two+three", '+');	
	while (*s != NULL)
	{	
		printf("%s \n",*s);			
		s++;
	}
	return (0);
}*/
