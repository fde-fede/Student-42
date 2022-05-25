/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:41:24 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/19 17:41:24 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static int	cmp(int fst_value, int scnd_value)
{
	if (fst_value == scnd_value)
		return (0);
	else
		return (1);
}

void	error_check(int argc, char **argv, int s)
{
	int	i;

	if (argc == 1)
		exit(0);
	if (check_flag(argv[1]))
		i = 1;
	else
		i = 0;
	while (--argc > 1)
	{
		if (ft_atoi_err(argv[argc]) == -1)
		{
			ft_printf(BOLDRED "Error\n" RESET);
			if (s)
				free_tab(argv)
			exit(0);
		}
	}
}

void	error_doubles(t_stack *lst)
{
	t_stack *future;

	while (lst)
	{
		future = lst->next;
		while (future)
		{
			if (!cmp(lst->data, future->data))
			{
				ft_printf(BOLDRED "Error\n" RESET);
				free_stack(lst);
				exit(0);
			}
			future = future->next;
		}
		lst = lst->next;
	}
}