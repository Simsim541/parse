
# include "minishell.h"

static void quotes_check(char c, int *db, int *s)
{
	if (c == '"')
		db++;
	if (c == '\'')
		s++;
}

static int error_redirection(char *str, int i, int red)
{
	int y;
	int	stop;

	stop = 2;
	i -= red - 2;
	ft_putstr_fd("syntax error near unexpected token `", 2);
	if (str[i] == '>' || str[i] == '<')
	{
		if (str[i] == '<')
			stop++;
		y = i;
		while (stop-- && str[i] == str[y])
			ft_putchar_fd(str[i++], 2);
		ft_putstr_fd("\'\n", 2);
	}
	return (0);
}

static int check_deplicate_of_redirection(char *line)
{
	int i;
	int redirection;
	int	db;
	int	s;

	db = 0;
	s = 0;
	i = -1;
	printf("here 1\n");
	while (line[++i])
	{
		quotes_check(line[i], &db, &s);
		redirection = 0;
		printf("here before check\n");
		while ((line[i] == '>' || line[i] == '<') && (!(db % 2) && !(s % 2)))
		{
			redirection++;
			printf("here %d\n", redirection);
			i++;
		}
		if (redirection == 2 && line[i - 2] != line[i - 1])
			return (error_redirection(line, i, redirection));
		else if (redirection > 2)
			return (error_redirection(line, i, redirection));
	}
	return (1);
}

int check_redirect(char *line)
{
	if (!(check_deplicate_of_redirection(line)))
		return (0);
	if (!(check_in_out(line)))
		return (0);
	if (!(check_append_in_out(line)))
		return (0);
	return (1);
}
