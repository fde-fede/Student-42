/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:15:01 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/25 18:16:02 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*root_a;
	t_stack	*root_b;
	char	**tab;
	int		size;

	root_a = NULL;
	root_b = NULL;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		size = ft_tab_size(tab);
		error_check(size, tab, 1);
		push_args(size, tab, &root_a, 'a');
		free_tab(tab);
		error_doubles(root_a);
		sort_stack(&root_a, &root_b);
	}
	else
	{
		tab = NULL;
		size = 0;
		error_check(argc, argv, 0);
		push_args(argc, argv, &root_a, 'a');
	}
	return (0);
}
