/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:20:51 by sthiagar          #+#    #+#             */
/*   Updated: 2023/12/15 18:53:45 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_file
{
	int		read;
	int		write;
}	t_file;

typedef struct s_fav
{
	char	**stmt1;
	char	*path1;
	char	**stmt2;
	char	*path2;
	char	**envp;
}	t_fav;

void	free_fav(t_fav *fav);
void	free_str(char **str);
void	free_str_arr(char ***dbl_arr);
void	error_exit(char *msg, t_fav *fav, char *str);
char	*find_cmd_path(char *cmd, char **dir_paths);
char	*get_cmd_path(char *cmd, char **envp);

#endif
