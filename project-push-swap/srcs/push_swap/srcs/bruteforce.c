/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 14:47:35 by fde-fede          #+#    #+#             */
/*   Updated: 2022/09/29 18:45:50 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bruteforce_solution(t_state *states, t_state **result)
{
	while (states && !(*result))
	{
		if (!states->st_b->size && !is_stack_ordered(states->st_a, ASC))
		{
			if (!add_state(result, states))
			{
				free_states(states);
				return (1);
			}
		}
		states = states->next;
	}
	return (0);
}

t_state	*pick_bruteforce_solution(t_state *states, size_t pos[2],
t_stack *st_b)
{
	t_state		*result;
	t_state		*new_states;
	t_state		*tmp;

	result = NULL;
	while (!result)
	{
		new_states = NULL;
		tmp = states;
		while (tmp)
		{
			if (bruteforce_choice_a(&new_states, tmp, pos, st_b))
			{
				free_states(new_states);
				return (NULL);
			}
			tmp = tmp->next;
		}
		free_states(states);
		states = new_states;
		if (check_bruteforce_solution(states, &result))
			return (NULL);
	}
	free_states(states);
	return (result);
}

int	bruteforce_order_a(t_program *prg)
{
	size_t	pos[2];
	t_state	*result;
	t_state	*states;

	calcul_align_b(&pos[0], &pos[1], &prg->st_b);
	states = new_empty_state(&prg->st_a, NULL, prg->st_a.max_size);
	if (!states)
		return (1);
	result = pick_bruteforce_solution(states, pos, &prg->st_b);
	if (!result)
	{
		free_states(states);
		return (1);
	}
	ex_in(result->instructions, &prg->st_a,
		&prg->st_b, prg->debug);
	if (!copy_and_concat_instructions(&prg->instr, result->instructions))
	{
		free_states(result);
		return (1);
	}
	free_states(result);
	return (0);
}
