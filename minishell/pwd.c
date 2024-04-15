/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:23:25 by sthiagar          #+#    #+#             */
/*   Updated: 2024/03/03 18:23:37 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute_pwd(t_minishell *ms)
{
	char	*pwd;

	//pwd = get_env_value(ms->env, "PWD");
	pwd = get_cwd(void);
	printf("%s\n", pwd);
	free_str(&pwd);
	return (0);
}
