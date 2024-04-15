/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:17:55 by sthiagar          #+#    #+#             */
/*   Updated: 2023/12/15 19:03:15 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_str(char **str)
{
	if (*str != NULL)
	{
		free (*str);
		*str = NULL;
	}
}

void	free_str_arr(char ***dbl_arr)
{
	int	i;

	if (*dbl_arr != NULL)
	{
		i = 0;
		while ((*dbl_arr)[i] != NULL)
		{
			free ((*dbl_arr)[i]);
			(*dbl_arr)[i] = NULL;
			i++;
		}
		free(*dbl_arr);
		*dbl_arr = NULL;
	}
}

void	error_exit(char *flag, t_fav *fav, char *str)
{
	if (ft_strncmp(flag, "perror", 6) == 0)
		perror(str);
	else
	{
		if (ft_strncmp(flag, "execve", 6) == 0)
			write(2, "pipex: command not found: ", 26);
		else if (ft_strncmp(flag, "open", 4) == 0)
			write(2, "pipex: no such file or directory: ", 34);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	if (fav != NULL)
		free_fav(fav);
	exit(EXIT_FAILURE);
}

char	*find_cmd_path(char *cmd, char **dir_paths)
{
	int		i;
	char	*cmd_path;
	char	*tmp_path;

	i = 0;
	while (dir_paths[i] != NULL)
	{
		tmp_path = ft_strjoin(dir_paths[i], "/");
		cmd_path = ft_strjoin(tmp_path, cmd);
		free_str(&tmp_path);
		if (access(cmd_path, X_OK) == 0)
		{
			free_str_arr(&dir_paths);
			return (cmd_path);
		}
		free_str(&cmd_path);
		i++;
	}
	free_str_arr(&dir_paths);
	return (cmd_path);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	int		i;
	char	*path_str;
	char	*substr;
	char	**dir_paths;
	char	*cmd_path;

	i = 0;
	while (envp[i] != NULL)
	{
		path_str = envp[i];
		substr = ft_substr(path_str, 0, 5);
		if (ft_strncmp(substr, "PATH=", 5) == 0)
		{
			free_str(&substr);
			break ;
		}
		free_str(&substr);
		i++;
	}
	dir_paths = ft_split(path_str, ':');
	return (cmd_path = find_cmd_path(cmd, dir_paths));
}
