/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:51:15 by fde-fede          #+#    #+#             */
/*   Updated: 2022/11/17 19:54:08 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_status;

void	child_builtin(t_prompt *prompt, t_mini *n, int l, t_list *cmd)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (!is_builtin(n) && n->full_cmd)
		execve(n->full_path, n->full_cmd, prompt->envp);
	else if (n->full_cmd && !ft_strncmp(*n->full_cmd, "pwd, l") \
		&& l == 3)
		g_status = mini_pwd();
	else if (is_builtin(n) && n->full_cmd && \
		!ft_strncmp(*n->full_cmd, "echo, l"))