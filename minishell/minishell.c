/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sthiagar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:02:58 by sthiagar          #+#    #+#             */
/*   Updated: 2024/02/09 13:29:18 by sthiagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
//env_variable
int	main()
{
	t_minishell	*shell;
	char	*value;
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	
	//display_env_list(shell->env); //OK
	//ptest(get_env_arr_index(shell->env, "HOME"));//OK
	
	//value = get_env_value(shell->env, "HOME"); //OK
	//stest("find HOME value",value);
	//free_str(&value);
	
	//add_env(shell, "apple=", "sauce");//OK
	//add_apn_env(shell, "apple+=duh", "sauce");//OK
	
	delete_env(shell, "HOME");//OK
	
	//update_env(shell->env, "USER", "SOMETHING WONDERFUL TONIGHT");// OK
	
	value = get_env_value(shell->env, "HOME"); //OK
	stest("find HOME value",value);
	free_str(&value);
	
	//display_env_list(shell->env); //OK
	free_tminishell2(&shell);
	return (0);	
}*/

//general tester 

int	main()
{
	char		*input;
	char		*clean;
	char		**pa;
	char		**ref;
	int		i;
	t_minishell	*shell;
	
	clean = NULL;
	//ref = NULL;
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	
	//input = "echo $*";
	
	//input = "echo \"$HELLO$USER\""; //incorrect
	//bash:~ ./echo.sh "$HELLO$USER"
	
	//input =   "echo >$? user ->$USER home ->$HOME"; //OK
	//bash:~ ./echo.sh $? user - $USER home - $HOME
	
	//input = "echo abc$HOME'\"$USER\"$HOME'"; //-->incorrect
	//bash:~ ./echo.sh abc$HOME'"$USER"$HOME'
	
	//input = "echo abc\"$HOME'$USER'$HOME\""; //--> incorrect. 
	//bash:~ ./echo.sh abc"$HOME'$USER'$HOME"
	
	//input = "echo $HOME '$HOME\"$HOME\"'"; //OK
	//bash:~ ./echo.sh $HOME '$HOME"$HOME"'
	
	//input = "echo \"$HOME\"";//OK
	//bash:~ ./echo.sh "$HOME"
	
	//input = "echo hello* \"hello*\" $ $HOME \"$HOME\" $HOME*ABC \"$HOME*ABC\" \"$HOME\"*ABC";
	//bash:~ ./echo.sh hello* "hello*" $ $HOME "$HOME" $HOME*ABC "$HOME*ABC" "$HOME"*ABC
	
	//input = "echo -n 'abc' \"$HELLO\" \"'*'\"";
	//input = "echo abc\"a\"\"2  << | >>  \"\"3\"'abc'000>>infile";
	input = "echo 123\"\"a";
	
	clean = clean_up_quotes(input);
	printf("str after cleanup:	%s\n", clean);
	
	ref = rfmt_input(clean);
	printf("\nreformat_input() returns:\n");
	print_doubleptr(ref);
	free (clean);
	
	printf("\nEcho parse_arguments individually. Ignoring < > | & \n");
	
	i = 1;//ref[0] is command, so skip commmand
	while ( ref[i] != NULL)
	{
		if (ref[i][0] != '>' && ref[i][0] != '<' \
			&& ref[i][0] != '&' && ref[i][0] != '|')
		{
			pa = parse_argument(shell, ref[i]);
			exec_builtin(shell, "echo", pa);//built-in executed
			free_doubleptr(pa);
		}
		i++;
	}
	
	//input = "-";
	//clean = clean_up_quotes(input);
	//pa = parse_argument(shell, clean);
	//free (clean);
	//exec_builtin(shell, "echo", pa);//built-in executed
	//free_doubleptr(pa);
	
	free_doubleptr2(&ref);
	free_tminishell2(&shell);
	return (0);
}

//parse arguments ------------
/*
int	main()
{
	char		*input;
	char		**ret;
	t_minishell	*shell;
	char		*clean;
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	
	//input = "*"; //--> wildcard*
	//bash:~ ./echo.sh * --> don't test wildcard with echo.sh, incorrect
	
	//input = "'*'"; //--> * OK
	//input = "'\"*\"'"; //--> "*" OK
	//input = "\"*\""; //--> * OK
	//input = "\"\""; //--> '*' OK
	//input = "-n abc * \"$HOME*\"'123*kill'$USER*";
	
	//input = "'\"$Hello\"'"; //--> "$Hello"
	//bash:~ ./echo.sh '"$Hello"'
	
	//input = "'$Hello'"; //--> $Hello
	//bash:~ ./echo.sh '$Hello'
	
	//input = "abc$Hello"; //--> abc
	//bash:~ ./echo.sh abc$Hello
	
	//input = "\"$Hello\""; //--> nothing
	//bash:~ ./echo.sh "$Hello"
	
	//input = "\"'$Hello'\""; //--> ' '
	//bash:~ ./echo.sh "'$Hello'"
	
	
	input = "abc$HOME\"$HELLO'$USER'\"'$HOME''$USER'123$HOME";
	//bash:~ ./echo.sh abc$HOME"$HELLO'$USER'"'$HOME''$USER'123$HOME
	
	//input = "abc\"$USER\"def";
	//bash:~ ./echo.sh abc"$HELLO"def
	
	clean = clean_up_quotes(input);
	printf("str after cleanup:	%s\n", clean);
	
	ret = parse_argument(shell, clean);
	free_str(&clean);
	printf("Print parsed arguments:\n");
	//print_doubleptr(ret);
	free_doubleptr2(&ret);
	free_tminishell2(&shell);
	return (0);
}*/

//cleanup quotes ------------------
/*
int	main()
{
	char		*input;
	char		*ret;
	t_minishell	*shell;
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	
	//double quote test
	//input = "hello* \"hello*\" $ $HOME \"$HOME\" $HOME*ABC \"$HOME*ABC\" \"$HOME\"*ABC";
	//input = "$ \"HELLO\" abc$9HELLO+123 \"abcHELLO*\"";
	//input = "abc\"$HOME\"$USER \"abc$HOME$USER+123\"";
	//input	= "$9HOME and $99HOME";
	//input = "\"$ 1\"apple";
	//input = "'\"$HOME\"'";
	//input = "ABC\"$\"\"good\"XYZ";
	//ret = clean_up_quotes(input);
	//printf("%s\n",ret);
	//free(ret);
	//ret = NULL;
	
	//single quote test
	//input = "cat '*' * '\"USER\"' '$USER' '''remove'";
	//input = "xyz'123";
	input =   "echo ->$? user ->$USER home ->$HOME";
	
	//input = "ec\"\"ho ->$? user ->$USER home ->wild* \"notwild*\"";
	ret = clean_up_quotes(input);
	printf("%s\n",ret);
	free(ret);
	free_tminishell2(&shell);
	
	return (0);
}*/


//reformat input str ------------------
/*
int	main()
{
	char		*input;
	char		**ret;
	t_minishell	*shell;
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	
	//input = "apple <<infile>> "" &&|||a";
	//input = "apple <<infile>> \"abc'123'def\" 'goat\"is\"roast' &&|||a";
	//input = "apple <<infile>> \"abc\" &&|||a";
	//input = "aaa\"hello world\"bb>>haha |||man '\"diehard\"'";
	//input = "echo ->\"$?\" user ->\"$USER\" home ->wild* \"notwild*\"";
	input = "echo \"a\"\"2\"\"3\"abc";
	
	//input = "echo \"'hello &&'\" * >> '$HELLO \"no\" >> !! &&' '\"home << >>\"'";
	//input = "echo hello=\"123 A-\" \"1\"\"2\"\"3\" 'a ''b ''c '";
	ret = rfmt_input(input);
	//print_doubleptr(ret);
	free_doubleptr(ret);
	free_tminishell2(&shell);
	return (0);
}*/

//Wildcard * --------------------------
/*
int	main()
{
	char		**test;
	char		*wildcard;
	t_minishell	*shell;
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	test = NULL;
	wildcard = "*";
	//wildcard= "$DUMMY*";//--> TEST THIS. Should display wildcard.
	
	if (ft_chrindex(wildcard, '*') != -1)
		test = get_wc_matches(wildcard);
	if (test[0] != NULL)
		//assuming wildcard is executed with echo cmd
		exec_builtin(shell, "echo", test);
	else
		printf("minishell: no matches found: %s\n", wildcard);
	free_doubleptr2(&test);
	free_tminishell2(&shell);
	return (0);
}*/

//test CD
/*
int	main()
{
	t_minishell	*shell;
	char	*test;
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	
	char	*str[2];
	
	str[0] = "/home/sthiagar/Practice";
	str[1] = NULL;
	
	update_env(shell->env, "OLDPWD=", "something");
	//-----print before change ----------
	test = get_env_value(shell->env, "OLDPWD");
	printf("OLDPWD BEFORE update is    %s\n", test);
	free (test);
	test = get_env_value(shell->env, "PWD");
	printf("PWD    BEFORE update is    %s\n", test);
	free(test);
	//----------------
	printf("\n");
	exec_builtin(shell, "cd", str);
	
	//-----print after change ----------
	test = get_env_value(shell->env, "PWD");
	printf("PWD    AFTER update is     %s\n", test);
	free(test);
	test = get_env_value(shell->env, "OLDPWD");
	printf("OLDPWD AFTER update is     %s\n", test);
	free (test);
	//----------------
	
	free_tminishell2(&shell);
	return (0);
}*/
/*
//test UNSET

int	main()
{
	char		*input;
	char		*clean;
	char		**ref;
	int		i;
	t_minishell	*shell;
	char		*value;
	
	clean = NULL;
	ref = NULL;
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	//input for export or add	
	input = "apple=123";
	
	clean = clean_up_quotes(input);
	//printf("input 1 after cleanup:	%s\n", clean);
	
	ref = rfmt_input(clean);
	//printf("reformat_input() returns:\n");
	//print_doubleptr(ref);
	free (clean);
	
	//Export on input 1
	//printf("\nExecute Export input 1\n");
	i = exec_builtin(shell, "export", ref);
	//display_env_list(shell->env);
	free_doubleptr2(&ref);
	value = get_env_value(shell->env, "apple");
	printf("After EXPORT, apple value: %s\n\n", value);
	free_str(&value);

//input for unset
	input = "apple";
	clean = clean_up_quotes(input);
	ref = rfmt_input(clean);
	free (clean);
	
	exec_builtin(shell, "unset", ref);//////////////////////////////
	value = get_env_value(shell->env, "apple");
	printf("After UNSET, apple value: %s\n\n", value);
	free_str(&value);
	
	//exec_builtin(shell, "env", NULL);
	exec_builtin(shell, "export", NULL);

	free_doubleptr2(&ref);
	free_tminishell2(&shell);
	return (0);
}*/

//test PWD
/*
int	main()
{
	t_minishell	*shell;
	
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	
	exec_builtin(shell, "pwd", NULL);
	free_tminishell2(&shell);	
	return (0);
}*/

//test ENV
/*
int	main()
{
	t_minishell	*shell;
	
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	char	*s[3];
	
	//s[0] = NULL;
	s[0] = "home=";
	s[1] = "bird=";
	s[2] = NULL;
	
	exec_builtin(shell, "env", s);
	
	free_tminishell(shell);	
	return (0);
}*/

//test ECHO
/*
int	main()
{
	t_minishell	*shell;
	
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);

	char *str[4];
	str[0] = "-n";
	str[1] = "a";
	str[2] = "b";
	str[3] = NULL;	
	
	//exec_builtin(shell, "echo", NULL);
	exec_builtin(shell, "echo", str);
	
	free_tminishell2(&shell);
	return (0);
}*/

//test EXPORT 
//---> Need to fix valgrind error
/*
int	main()
{
	char		*input;
	char		*clean;
	char		**pa;
	char		**ref;
	int		i;
	t_minishell	*shell;
	char		*temp;
	
	clean = NULL;
	ref = NULL;
	shell = (t_minishell *)malloc(sizeof(t_minishell) * 1);
	init_env(shell);
	
	//char	*str[3];

		//test case 1: 
	//str[0] = "apple"; str[1] = "apple=bad";
		//	env APPLE return bad 
		//	--> initial no value, then overwrite
		//test case 2: 
	//str[0] = "apple"; str[1] = "apple+=bad";
		//	env APPLE return bad 
		//	--> initial no value, then append to it 
		//test case 3: 
	//str[0] = "apple=not"; str[1] = "apple+=bad";
		//	env APPLE return notbad 
		//	--> overwrite, then append
		//test case 4: 
	//str[0] = "apple+=good"; str[1] = "apple+=bad";
		//	env APPLE return (goodbad) 
		//	--> append good, then append bad
		//test case 5: 
	//str[0] = "apple+=good"; str[1] = "apple";
		//	env APPLE return (good) 
		//	-->because nothing to overwrite or append
	
		//test case 6: --->emma spotted error
	//str[0] = "9a"; str[1] = "a9_";
	
	//str[2] = NULL;
	
	input = "apple=\"*\"";
	
	clean = clean_up_quotes(input);
	//printf("input 1 after cleanup:	%s\n", clean);
	
	ref = rfmt_input(clean);
	//printf("reformat_input() returns:\n");
	//print_doubleptr(ref);
	free (clean);
	pa = parse_argument(shell, ref[0]);	
	print_doubleptr(pa);
	free_doubleptr2(&ref);
	
	//Export on input 1
	i = exec_builtin(shell, "export", pa);//Note: I am not parsing each ref[i]
	//display_env_list(shell->env);
	temp = get_env_value(shell->env, "apple");
	printf("After export input 1, apple value: %s\n",temp);
	free_str(&temp);
	free_doubleptr2(&pa);
	
printf("*************************************************************************\n");
	input = "apple=456";
	
	clean = clean_up_quotes(input);
	//printf("\ninput 2 after cleanup:	%s\n", clean);
	
	ref = rfmt_input(clean);
	//printf("reformat_input() returns:\n");
	//print_doubleptr(ref);
	free (clean);
	pa = parse_argument(shell, ref[0]);
	print_doubleptr(pa);
	free_doubleptr2(&ref);;
	
	//Export on input 2
	i = exec_builtin(shell, "export", pa);//Note: I am not parsing each ref[i]
	//display_env_list(shell->env);
	temp = get_env_value(shell->env, "apple");
	printf("After export input 2, apple value: %s\n",temp);
	free_str(&temp);
	free_doubleptr2(&pa);
	
	i = exec_builtin(shell, "export", NULL);
	
	free_tminishell2(&shell);
	return (0);
}*/
