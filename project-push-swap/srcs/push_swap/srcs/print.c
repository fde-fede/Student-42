/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:23:32 by fde-fede          #+#    #+#             */
/*   Updated: 2022/09/29 18:25:28 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instruction(t_instruction *instr)
{
	write(STDOUT_FILENO, instr->line, ft_strlen(instr->line));
	write(STDOUT_FILENO, "\n", 1);
}

void	print_instructions(t_instruction *instr)
{
	while (instr)
	{
		print_instruction(instr);
		instr = instr->next;
	}
}

void	print_bottom_stack(int max_size_nbr[2])
{
	write(STDOUT_FILENO, " ", 1);
	write_n_char(max_size_nbr[0], '_');
	write(STDOUT_FILENO, " ", 1);
	write_n_char(max_size_nbr[1], '_');
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, " ", 1);
	write_n_char(max_size_nbr[0] - 1, ' ');
	write(STDOUT_FILENO, "a ", 2);
	write_n_char(max_size_nbr[1] - 1, ' ');
	write(STDOUT_FILENO, "b", 1);
	write(STDOUT_FILENO, "\n", 1);
}

void	print_numbers_stack(int max_size, int max_size_nbr[2],
	t_stack *st_a, t_stack *st_b)
{
	int	i;

	i = -1;
	while (++i < max_size)
	{
		write(STDERR_FILENO, " ", 1);
		if ((int)(st_a->size - max_size + i) >= 0)
			write_n_char(max_size_nbr[0] - size_nbr(st_a->array[st_a->size
					- max_size + i]), ' ');
		if ((int)(st_a->size - max_size + i) >= 0)
			ft_putnbr(st_a->array[st_a->size - max_size + i]);
		else
			write_n_char(max_size_nbr[0], ' ');
		write(STDOUT_FILENO, " ", 1);
		if ((int)(st_b->size - max_size + i) >= 0)
			write_n_char(max_size_nbr[1] - size_nbr(st_b->array[st_b->size
					- max_size + i]), ' ');
		if ((int)(st_b->size - max_size + i) >= 0)
			ft_putnbr(st_b->array[st_b->size - max_size + i]);
		else
			write_n_char(max_size_nbr[1], ' ');
		write(STDOUT_FILENO, "\n", 1);
	}
}

void	print_stacks(t_stack *st_a, t_stack *st_b)
{
	int	max_size_nbr[2];
	int	max_size;

	max_size = st_a->size;
	if (st_b->size > st_a->size)
		max_size = st_b->size;
	write(STDOUT_FILENO, _YELLOW, ft_strlen(_YELLOW));
	write(STDOUT_FILENO, "stacks\n", 7);
	write(STDOUT_FILENO, _END, ft_strlen(_END));
	max_size_nbr[0] = get_max_size_nbr_stack(st_a);
	max_size_nbr[1] = get_max_size_nbr_stack(st_b);
	print_numbers_stack(max_size, max_size_nbr, st_a, st_b);
	print_bottom_stack(max_size_nbr);
}
