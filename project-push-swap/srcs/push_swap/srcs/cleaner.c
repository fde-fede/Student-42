/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:20:19 by fde-fede          #+#    #+#             */
/*   Updated: 2022/09/30 14:18:50 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_instructions(t_instruction *instructions)
{
	t_instruction	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions->line);
		free(instructions);
		instructions = next;
	}
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

void	free_prg(t_program *prg)
{
	free_instructions(prg->instr);
	free(prg->st_a.array);
	free(prg->st_b.array);
}

void	clear_new(t_state *new)
{
	new->st_a = NULL;
	new->st_b = NULL;
	new->instructions = NULL;
	new->last_instr = NULL;
	new->next = NULL;
}

void	check_stack(t_state *state, size_t max_size, t_stack *st_b)
{
	if (st_b)
		state->st_b = copy_stack(st_b);
	else
	{
		state->st_b = new_empty_stack(max_size);
		if (!state->st_b)
		{
			free_stack(state->st_a);
			free(state);
		}
	}
}
