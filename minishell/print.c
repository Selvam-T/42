/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 20:53:49 by sthiagar          #+#    #+#             */
/*   Updated: 2024/03/12 20:54:04 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	qtest(char *p, char *s, int i, char c)
{
	printf("%s: str is %s, i is %d, char is %c\n",p, s, i, c);
}

void	ptest(int i)
{
	printf("---- %d ----\n",i);
}

void	stest(char *w, char *s)
{
	printf("%s is %s\n",w,s);
}

void	print_str_chars(char *str)
{
	int	i;
	if (str == NULL)
		printf("str is NULL\n");
	else
	{
		i = 0;	
		while (*str)
		{
			printf("%d. %c --> %d\n",i, *str, *str);
			str++;
			i++;
		}
		printf("%d. %c --> %d\n",i, *str, *str);
	}
}

void	print_int_arr(int *arr)
{
	int	i;
	
	if (arr == NULL)
		printf("int arr is NULL\n");
	else
	{
		i = 0;	
		while (arr[i] != -1)
		{
			printf("%d --> %d\n",i, arr[i]);
			i++;
		}
		printf("outside loop: %d --> %d\n",i, arr[i]);
	}
}

void	print_var(t_var *var)
{
	if (var == NULL)
		printf("lst is NULL\n");
	else
		printf("lst is not NULL\n");
	while (var != NULL)
	{
		//printf("name is %s, value is %s\n",var->name, var->value);
		printf("name is %s\n",var->name);
		printf("value is %s\n",var->value);
		printf("char is %c\n",var->c);
		var = var->next;
	}
}

void	print_var2(t_var *var)
{
	while (var != NULL)
	{
		printf("%c\n",var->c);
		var = var->next;
	}
}

void	print_doubleptr(char **ptr)
{
	int	i;

	//if (ptr == NULL)
		//printf("a) **ptr is NULL\n");
	//else
	//{
		//printf("a) **ptr is NOT NULL\n");
		//if (ptr[0] != NULL)
			//printf("a) ptr[0] is not NULL %s\n",ptr[0]);
		//else
			//printf("a) ptr[0] is NULL\n");
	//}
	
	i = 0;
	while (ptr != NULL && ptr[i] != NULL)
	{
		printf("arg[%d]: %s\n", i, ptr[i]);
		//print_str_chars(ptr[i]);
		i++;
	}
	
	//if (ptr == NULL)
		//printf("b) **ptr is NULL\n");
	//else
	//{
		//printf("b) **ptr is NOT NULL\n");
		//if (ptr[i] != NULL)
			//printf("b) ptr[%d] is not NULL %s\n",i, ptr[i]);
		//else
			//printf("b) ptr[%d] is NULL\n",i);
	//}
	//if (ptr == NULL)
		//printf("finally **ptr is NULL\n");
}

void	test_delete_print(char **ptr, int index)
{
	int	i;
	
	i = 0;
	while (ptr != NULL && ptr[i] != NULL)
	{
		if (i == index)
			printf("I will be deleting the following item\n");
		printf("arg[%d]: %s\n", i, ptr[i]);
		i++;
	}
	
}
