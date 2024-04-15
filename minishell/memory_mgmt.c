/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_mgmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:01:13 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/28 13:02:45 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_str(char **str)
{
	free(*str);
	*str = NULL;
}

void	free_with_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	free_var_lst(t_var **var)
{
	t_var	*next;
	t_var	*cur;

	next = NULL;
	cur = *var;
	while (cur != NULL)
	{
		next = cur->next;
		free (cur);
		cur = next;
	}
	free(cur);
	*var = NULL;
}

void	free_doubleptr(char **ptr)
{
	int	i;

	i = -1;
	while (ptr && ptr[++i])
	{
		if (ptr[i])
			free(ptr[i]);
		ptr[i] = NULL;
	}
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	free_tminishell(t_minishell *shell)
{
	if (shell != NULL)
	{
		free_doubleptr(shell->env);
		free(shell);
		shell = NULL;
	}
}

void	free_doubleptr2(char ***ptr)
{
	int	i;

	i = -1;
	while (*ptr != NULL && (*ptr)[++i])
	{
		if ((*ptr)[i])
		{
			free((*ptr)[i]);
			(*ptr)[i] = NULL;
		}
	}
	if (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_tminishell2(t_minishell **shell)
{
	if (*shell != NULL)
	{
		if ((*shell)->exit_status)
		{
			free((*shell)->exit_status);
			(*shell)->exit_status = NULL;
		}
		free_doubleptr2(&(*shell)->env);
		free(*shell);
		*shell = NULL;
	}
}
