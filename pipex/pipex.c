/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:23:38 by sthiagar          #+#    #+#             */
/*   Updated: 2023/12/17 13:59:52 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_fav(t_fav *fav)
{
	free_str(&fav->path1);
	free_str_arr(&fav->stmt1);
	free_str(&fav->path2);
	free_str_arr(&fav->stmt2);
}

void	init_datastruct(t_file *filedesc, t_fav *fav, char *argv[], char **envp)
{
	filedesc->read = open(argv[1], O_RDONLY, 0777);
	if (filedesc->read == -1)
		error_exit("open", NULL, argv[1]);
	filedesc->write = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filedesc->write == -1)
		error_exit("open", NULL, argv[4]);
	fav->stmt1 = ft_split(argv[2], ' ');
	fav->path1 = get_cmd_path(fav->stmt1[0], envp);
	fav->stmt2 = ft_split(argv[3], ' ');
	fav->path2 = get_cmd_path(fav->stmt2[0], envp);
	fav->envp = envp;
}

void	child_process(int *fd, t_file *filedesc, t_fav *fav)
{

	close(fd[0]);
	dup2(filedesc->read, 0);
	close(filedesc->read);
	dup2(fd[1], 1);
	close(fd[1]);
	if (fav->path1 != NULL)
		execve(fav->path1, fav->stmt1, fav->envp);
	else
		error_exit("execve", fav, fav->stmt1[0]);
}

void	parent_process(int *fd, pid_t pid, t_file *filedesc, t_fav *fav)
{
	int	status;
	
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	dup2(filedesc->write, 1);
	close(filedesc->write);
	if (fav->path2 != NULL)
		execve(fav->path2, fav->stmt2, fav->envp);
	else
		error_exit("execve", fav, fav->stmt2[0]);
	waitpid(pid, &status, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_file	filedesc;
	t_fav	fav;
	int		fd[2];
	
	pid_t	pid;
	
	if (argc < 5)
		error_exit("argc", NULL, "pipex: Error: too few arguments.");
	else if (argc > 5)
		error_exit("argc", NULL, "pipex: Error: too many arguments.");
	init_datastruct(&filedesc, &fav, argv, envp);
	if (pipe(fd) == -1)
		error_exit("perror", &fav, "pipe");
	pid = fork();
	if (pid == -1)
		error_exit("perror", &fav, "fork");
	if (pid == 0)
		child_process(fd, &filedesc, &fav);
	else
		parent_process(fd, pid, &filedesc, &fav);
	free_fav(&fav);
	return (0);
}
