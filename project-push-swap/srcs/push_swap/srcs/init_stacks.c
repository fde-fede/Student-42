/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:32:27 by fde-fede          #+#    #+#             */
/*   Updated: 2022/09/29 18:47:31 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup_char(const char *str, char stop)
{
	int		i;
	char	*pt;

	i = 0;
	while (str[i] && str[i] != stop)
		i++;
	pt = malloc ((i + 1) * sizeof(char));
	if (!pt)
		return (0);
	i = -1;
	while (str[++i] && str[i] != stop)
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

int	fill_st_arg(char *arg, t_stack *stack, size_t *stack_nb)
{
	int		num;
	char	*str;

	while (*arg)
	{
		while (*arg && *arg == ' ')
			arg++;
		if (!arg)
			break ;
		str = ft_strdup_char(arg, ' ');
		if (ft_atoi(str, &num))
		{
			free(str);
			return (1);
		}
		free(str);
		if (stack_contains(stack, num))
			return (1);
		stack->array[(*stack_nb)++] = num;
		stack->size++;
		while (*arg && *arg != ' ')
			arg++;
	}
	return (0);
}

int	fill_stack(int ac, char *av[], t_stack *stack)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	while (i < (size_t)ac)
	{
		ptr = av[i];
		if (fill_st_arg(ptr, stack, &j))
			return (1);
		i++;
	}
	return (0);
}

size_t	count_stack_size(int ac, char *av[])
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	i = 0;
	while (i < (size_t)ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((!j || av[i][j - 1] == ' ') && av[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	init_stacks(int ac, char *av[], t_stack *st_a, t_stack *st_b)
{
	size_t	stack_size;

	stack_size = count_stack_size(ac, av);
	st_a->array = malloc(sizeof(int) * stack_size);
	if (!st_a->array)
		return (write(STDERR_FILENO, "Error\n", 6));
	st_b->array = malloc(sizeof(int) * stack_size);
	if (!st_b->array)
	{
		free(st_a->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	st_a->max_size = stack_size;
	st_b->max_size = stack_size;
	st_a->size = 0;
	st_b->size = 0;
	if (fill_stack(ac, av, st_a))
	{
		free(st_a->array);
		free(st_b->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}
