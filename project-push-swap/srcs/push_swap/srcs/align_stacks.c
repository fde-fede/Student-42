/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:11:52 by fde-fede          #+#    #+#             */
/*   Updated: 2022/09/29 18:45:50 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calcul_align_a(size_t *pos, size_t *mvt,
	t_stack *st_a, t_stack *st_b)
{
	*pos = 0;
	*mvt = 0;
	if (is_stack_ordered(st_a, ASC))
	{
		while (*pos < st_a->size - 1 && st_a->array[*pos]
			< st_a->array[*pos + 1])
			(*pos)++;
		if (*pos > st_b->size / 2)
			*mvt = st_a->size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

void	calcul_align_b(size_t *pos, size_t *mvt, t_stack *st_b)
{
	*pos = 0;
	*mvt = 0;
	if (is_stack_ordered(st_b, DESC))
	{
		while (*pos < st_b->size - 1 && st_b->array[*pos]
			> st_b->array[*pos + 1])
			(*pos)++;
		if (*pos > st_b->size / 2)
			*mvt = st_b->size - (*pos + 1);
		else
			*mvt = *pos + 1;
	}
}

int	align_st_a(t_program *prg)
{
	size_t			i;
	size_t			num;
	t_instruction	*tmp;

	calcul_align_a(&i, &num, &prg->st_a, &prg->st_b);
	while (num--)
	{
		if (i > prg->st_b.size / 2)
			tmp = add_instruction(&prg->instr, "rra");
		else
			tmp = add_instruction(&prg->instr, "ra");
		if (!tmp)
			return (1);
		ex_in(tmp, &prg->st_a, &prg->st_b, prg->debug);
	}
	return (0);
}

int	align_st_b(t_program *prg)
{
	size_t			i;
	size_t			num;
	t_instruction	*tmp;

	calcul_align_b(&i, &num, &prg->st_b);
	while (num--)
	{
		if (i > prg->st_b.size / 2)
			tmp = add_instruction(&prg->instr, "rrb");
		else
			tmp = add_instruction(&prg->instr, "rb");
		if (!tmp)
			return (1);
		ex_in(tmp, &prg->st_a, &prg->st_b, prg->debug);
	}
	return (0);
}
