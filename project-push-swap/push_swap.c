/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:15:01 by fde-fede          #+#    #+#             */
/*   Updated: 2022/07/16 17:19:17 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	initialize_stacks(t_stack stack_a, t_stack stack_b,
	int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < argc)
	{
		stack_a.nbs[i] = argv[j];
		i++;
		j++;
	}
}

void	change_numbers(t_stack stack_a)
{
	int	cont;
	int	i;

	
}

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	check_arguments(argc, **argv);
	initialize_stacks(stack_a, stack_b, argc, argv);
	change_numbers(stack_a);
}
