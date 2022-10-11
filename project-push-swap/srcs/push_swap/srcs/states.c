/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:59:04 by fde-fede          #+#    #+#             */
/*   Updated: 2022/09/30 14:19:56 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_state	*new_state_instruction(t_state **states, t_state *old_state, char *line)
{
	t_state			*state;
	t_instruction	*instr;

	state = add_state(states, old_state);
	if (!state)
		return (NULL);
	instr = add_instruction(&state->instructions, line);
	if (!instr)
	{
		free_states(state);
		return (NULL);
	}
	state->last_instr = instr;
	ex_in(instr, state->st_a, state->st_b, 0);
	return (state);
}

void	free_states(t_state *states)
{
	t_state	*tmp;
	t_state	*next;

	tmp = states;
	while (tmp)
	{
		next = tmp->next;
		free_stack(tmp->st_a);
		free_stack(tmp->st_b);
		free_instructions(tmp->instructions);
		free(tmp);
		tmp = next;
	}
}

t_state	*add_state(t_state **states, t_state *state_from)
{
	t_state	*tmp;
	t_state	*new;

	new = malloc(sizeof(t_state));
	if (!new)
		return (NULL);
	clear_new(new);
	new->st_a = copy_stack(state_from->st_a);
	new->st_b = copy_stack(state_from->st_b);
	new->instructions = copy_instructions(state_from->instructions);
	if (!new->st_a || !new->st_b || (state_from->instructions
			&& !new->instructions))
	{
		free_states(new);
		return (NULL);
	}
	tmp = *states;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*states = new;
	return (new);
}

t_state	*new_empty_state(t_stack *st_a, t_stack *st_b, size_t max_size)
{
	t_state	*state;

	state = malloc(sizeof(t_state));
	if (!state)
		return (NULL);
	if (st_a)
		state->st_a = copy_stack(st_a);
	else
	{
		state->st_a = new_empty_stack(max_size);
		if (!state->st_a)
		{
			free(state);
			return (NULL);
		}
	}
	check_stack(state, max_size, st_b);
	if (!state->st_b)
		return (NULL);
	state->instructions = NULL;
	state->last_instr = NULL;
	state->next = NULL;
	return (state);
}
