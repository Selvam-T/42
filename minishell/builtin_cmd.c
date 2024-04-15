/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:20:01 by sthiagar          #+#    #+#             */
/*   Updated: 2024/03/08 10:20:15 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(t_minishell *ms, char *cmd, char **args)
{
	int	return_status;

	return_status = 0;
	if (ft_is_strequal(cmd, "echo"))
		return_status = execute_echo(args);
	else if (ft_is_strequal(cmd, "pwd"))
		return_status = execute_pwd(ms);
	else if (ft_is_strequal(cmd, "env"))
		return_status = execute_env(ms, args);
	else if (ft_is_strequal(cmd, "export"))
		return_status = execute_export(ms, args);
	else if (ft_is_strequal(cmd, "unset"))
		return_status = execute_unset(ms, args);
	else if (ft_is_strequal(cmd, "cd"))
		return_status = execute_cd(ms, args);
	*(ms->exit_status) = return_status;
	return (return_status);
}
