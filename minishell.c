/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: simoberri <simoberri@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:57:56 by aaammari          #+#    #+#             */
/*   Updated: 2023/03/04 00:49:18 by simoberri        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	white_space(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] > 32 && str[i] < 127)
			return (0);
		i++;
	}
	return (1);
}

int	check_syntax_init(char *line)
{
	if (!check_quotes(line))
		return(0);
	if (!check_pipes(line))
		return (0);
	if (!check_redirect(line))
		return (0);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	//char	**args;
	//int		i;

	//i = 0;
	(void)ac;
	(void)av;
	(void)env;
	while(1)
	{
		line = readline("minishell$> ");
		if(!line)
			break;
		add_history(line);
		if (line && !(white_space(line)) && check_syntax_init(line))
		{
			printf("ok\n");	
		}
	}
	/*line = expand_env(line, env);
	args = ft_split(line, '|');
	while (args[i])
	{
		printf("args : %s\n", args[i]);
		i++;
	}
	//ft_exec_pipe(args, env);*/
	return (0);
}
