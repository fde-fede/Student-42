/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:15:01 by fde-fede          #+#    #+#             */
/*   Updated: 2022/09/29 18:47:31 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	count_instructions(t_instruction *instr)
{
	size_t	nb;

	nb = 0;
	while (instr)
	{
		nb++;
		instr = instr->next;
	}
	return (nb);
}

int	pick_solution(t_program *prg, t_state *states)
{
	t_state		*solution;
	t_state		*tmp_state;

	solution = NULL;
	tmp_state = states->next;
	while (tmp_state)
	{
		if (!solution || count_instructions(tmp_state->instructions)
			< count_instructions(solution->instructions))
			solution = tmp_state;
		tmp_state = tmp_state->next;
	}
	if (!solution)
		solution = states;
	if (solution->instructions)
	{
		ex_in(solution->instructions, &prg->st_a, &prg->st_b, prg->debug);
		prg->instr = copy_instructions(solution->instructions);
		if (!(prg->instr))
		{
			free_states(states);
			return (1);
		}
	}
	return (0);
}

int	realign_and_fill_a(t_program *prg)
{
	t_instruction	*tmp;

	if (prg->st_b.size > 1 && align_st_b(prg))
		return (1);
	while (prg->st_b.size)
	{
		if (prg->st_b.array[0] > prg->st_a.array[prg->st_a.size - 1]
			|| (prg->st_b.array[0] < prg->st_a.array[0]
				&& prg->st_a.array[0]
				< prg->st_a.array[prg->st_a.size - 1]))
			tmp = add_instruction(&prg->instr, "pa");
		else
			tmp = add_instruction(&prg->instr, "rra");
		if (!tmp)
			return (1);
		ex_in(tmp, &prg->st_a, &prg->st_b, prg->debug);
	}
	if (align_st_a(prg))
		return (1);
	return (0);
}

int	resolve(t_program *prg)
{
	t_state		*states;

	states = new_empty_state(&prg->st_a,
			&prg->st_b, prg->st_a.max_size);
	if (!states)
		return (1);
	if (prg->st_a.size > 5 && (create_states_resolution(&states)
			|| large_resolve(states)))
		return (1);
	if (pick_solution(prg, states))
		return (1);
	free_states(states);
	if (bruteforce_order_a(prg))
		return (1);
	if (realign_and_fill_a(prg))
		return (1);
	return (0);
}

int	main(int ac, char *av[])
{
	t_program	prg;

	if (--ac < 1 || (!ft_strcmp(av[1], "-v") && ac == 1) || !ft_strlen(av[1]))
		return (0);
	prg.debug = 0;
	if (!ft_strcmp(av[1], "-v"))
	{
		prg.debug = 1;
		if (init_stacks(--ac, &av[2], &prg.st_a, &prg.st_b))
			return (1);
	}
	else if (init_stacks(ac, &av[1], &prg.st_a, &prg.st_b))
		return (1);
	if (prg.debug)
		print_stacks(&prg.st_a, &prg.st_b);
	prg.instr = NULL;
	if (is_stack_ordered(&prg.st_a, ASC) && resolve(&prg))
	{
		free_instructions(prg.instr);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	print_instructions(prg.instr);
	free_prg(&prg);
	return (0);
}
