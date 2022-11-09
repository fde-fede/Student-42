/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:37:50 by fde-fede          #+#    #+#             */
/*   Updated: 2022/11/07 21:48:39 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_prompt init_prompt(char **argv, char **envp)
{
	t_prompt	prompt;
	char		*str;
	
	str = NULL;
	prompt.cmds = NULL;
	prompt.envp = ft_dup_matrix(envp);
	g_status = 0;
	mini_getpid(&prompt);
	prompt = init_vars(prompt, str, argv);
	return (prompt);
}

int	main(int argc, char *argv[], char **envp)
{
	char		*str;
	char		*out;
	t_prompt	prompt;

	promt = init_prompt(argv, envp);
	while (argv && argc)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		str = mini_getprompt(prompt);
		if (str)
			out = readline(str);
		else
			out = readline("guest@minishell $ ");
		free(str);
		if (!check_args(out, &prompt))
			break ;
	}
	exit(g_status)
}