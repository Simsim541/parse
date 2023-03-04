/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberri <mberri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:39:35 by aaammari          #+#    #+#             */
/*   Updated: 2023/02/25 13:52:11 by mberri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "stdio.h"
# include "stdlib.h"
# include "readline/readline.h"
# include "readline/history.h"
# include "libft/libft.h"
# include "unistd.h"
# include "fcntl.h"


int     check_redirect(char *line);
int     print_error(char *str);
int     check_append_in_out(char *str);
int		check_quotes(char *str);
char	*expand_env(char *str, char **env);
int		double_quotes(char *str, int i, int *db, int single);
int     check_in_out(char *str);
void	nbr_of_char(char *str, int *d, int *s, int i);
int		check_dollar(char *str, int *i, int status, char *cmd);
int		get_var_env(char *str, char **env, int *j, char *cmdline);
int		check_d(char *str, char *cmdline, int *i, int status);
void	fillcmd_and_incj(char *cmdline, int *j, int *l, int *i);
int		check_digit(char *str, char *cmdline);
void	init_var(int *var1, int *var2, int *var3, int *var4);
void	ft_execve(char **cmd, char **env, int fd[2]);
void	ft_exec_pipe(char **cmds, char **env);
void	ft_free(char **args);
int		is_white_space(char c);
int		check_pipes(char *line);
int		number_of_pipes(char *line);
int     check_syntax_init(char *line);

#endif
