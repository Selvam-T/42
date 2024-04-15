/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:18:25 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/10 13:19:08 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h> //readline
#include <readline/history.h> //readline
#include <sys/types.h> // for functions that use return value of pid_t data type
#include <sys/wait.h> //wait
#include <sys/resource.h> //contains struct rusage defintion
#include <sys/stat.h> //stat functions
#include <fcntl.h>
#include <dirent.h> //representing directory stream
#include <sys/ioctl.h>
#include <termios.h> //get and set terminal attributes
#include <curses.h> // Include curses library for termcap functions

extern char	**environ;

typedef struct s_minishell
{
	int					*exit_status;
	char				**env;
	struct s_input		*tree;
}	t_minishell;

typedef struct s_data
{
	t_var	*usr;
	t_var	*env;
}	t_data;

//global variable - indicate signal received
extern int	sigrcd;

//memory mgmt
void	free_doubleptr(char **ptr);
void	free_doubleptr2(char ***ptr);
void	free_var_lst(t_var **var);
void	free_tminishell(t_minishell *shell);
void	free_tminishell2(t_minishell **shell);
void	free_str(char **str);
void	free_with_ptr(void **ptr);//emma's function

//wildcard
char	**get_wc_matches(char *wildcard);

//wildcard_utils
void	update_head_tail_stars(char *wildcard, int *head_star, int *tail_star);
//char	*ft_strchr_headpart(char *str, char *substr);
//char	*ft_strchr_tailpart(char *str, char *substr);
//t_var	*get_cur_lst(int dironly, char *wc, char *str, t_var *cur_lst);
char	*wildcard_match(char *name, char *wildcard);

//built_in cmds
int 	exec_builtin(t_minishell *ms, char *cmd, char **args);//modify if other ver used
int	execute_echo(char **args);//modify if other ver used
int	execute_cd(t_minishell *ms, char **args);
int	execute_pwd();
int	execute_env(t_minishell *ms, char **args);
int	execute_export(t_minishell *ms, char **args);
int	execute_unset(t_minishell *ms, char **args);

//builtin_cmds_utils 
int	args_count(char **args);
t_var	*matched_lst(t_var *match, char *str);
char	**matched_arr(t_var *match);
int	has_wildcard(char *str);
int	ft_last_idxofchar(char *str, char c);
char	**sortstrarr(char **arg);

//env_variable
int	init_env(t_minishell *shell);
char	*update_env(char **env, char *find, char *value);
int	delete_env(t_minishell *shell, char *find);
int	add_env(t_minishell *shell, char *name, char *value);
int	add_apn_env(t_minishell *shell, char *name, char *append);

//env_variable_utils
void	display_env_list(char **ptr);
char	**mem_alloc(char **mem, int resize);
int	get_env_arr_index(char **env, char *find);
char	*get_env_value(char **env, char *find);
char	**index_removed_env(t_minishell *shell, int index);

//file
int	is_regularfile(char *dir);
int	is_directory(char *dir);

//export
//int	display_exp_list(char **ptr);

//CD
int	is_directory(char *dir);
int	is_regularfile(char *dir);

//input_reformat
char	**rfmt_input(char *str);
char	*clean_up_quotes(char *input);

//input_reformat_utils
int	update_str_info(char *input, int length, int **str_info);
int	count_chars(char *str);
int	count_chars2(char *str, char c);

//validate
int	is_valid_id_chr(char c, int index);
int	validate_key_val(char *key, char *val);
int	is_valid_value(char *str);
int	is_valid_key(char *key);

//validate_utils
char	*set_nonvalue(char *s, int *i, int len);
//char	*extract_id_value(t_minishell *shell, char *s, int *i);
char	*extract_id_value(t_minishell *shell, char *s, int *i, int *t);

//cleanup
char	*clean_up_quotes(char *input);

//input_parser
char	**parse_argument(t_minishell *shell, char *input);
//char	**parse_quote(char **env, char *str, char c);
//char	*resolve_dblquote(char **env, char *str);

//input_parser_utils
char	*trim_quote_adv_idx(char *s, int *i, char c);
int	count_delim(char *str, char c);
int	next_delim(char *str);

//struct_conv_utils
char	*convert_struct_chr(t_var *lst);

//parse_dquote_utils -->to be removed -----------
t_var	*init_env_vars();
t_var	*init_user_vars();
char	*get_str();
//print -->to be removed ------------------------
void	print_var(t_var *var);
void	print_var2(t_var *var);
void	print_doubleptr(char **ptr);
void	print_str_chars(char *str);
void	print_int_arr(int *arr);
void	ptest(int i);
void	qtest(char *p, char *s, int i, char c);
void	stest(char *w, char *s);
void	test_delete_print(char **ptr, int index);
//-----------------------------------------------

#endif
