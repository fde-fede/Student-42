/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 11:44:24 by fde-fede          #+#    #+#             */
/*   Updated: 2022/09/29 18:25:28 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	can_pb(t_stack *st_a, t_stack *st_b)
{
	if (!st_a->size)
		return (0);
	if (st_b->size < 2)
		return (1);
	else if (st_a->array[0] > st_b->array[0])
	{
		if (st_a->array[0] < st_b->array[st_b->size - 1]
			&& st_b->array[0] < st_b->array[st_b->size - 1])
			return (1);
		else if (st_a->array[0] > st_b->array[st_b->size - 1]
			&& st_b->array[0] > st_b->array[st_b->size - 1])
			return (1);
	}
	else if (st_a->array[0] < st_b->array[st_b->size - 1]
		&& st_b->array[st_b->size - 1] < st_b->array[0])
		return (1);
	return (0);
}

size_t	closer_pos_to_inf(int nb, t_stack *stack)
{
	size_t	pos;

	pos = 0;
	if (nb > stack->array[0] && nb < stack->array[stack->size - 1])
		return (pos);
	while (pos < stack->size && nb > stack->array[pos])
		pos++;
	if (pos != stack->size)
	{
		while (pos < stack->size - 1 && nb < stack->array[pos])
			pos++;
		if (pos == stack->size - 1 && stack->array[pos] > nb)
			pos = stack->size;
	}
	if (pos == stack->size)
	{
		pos = 1;
		while (pos < stack->size && stack->array[pos - 1] > stack->array[pos])
			pos++;
	}
	if (pos == stack->size)
		pos = 0;
	return (pos);
}

size_t	less_mvt_at_begin(size_t minimal_mvt, size_t *min_mvt,
	t_stack *st_a, t_stack *st_b)
{
	size_t	i;
	size_t	min;
	size_t	tmp[2];

	if (minimal_mvt > st_b->size / 2)
		minimal_mvt = st_b->size - minimal_mvt;
	min = minimal_mvt + 1;
	i = 0;
	while (++i < st_a->size && i < minimal_mvt)
	{
		tmp[0] = closer_pos_to_inf(st_a->array[i], st_b);
		tmp[1] = st_b->size - tmp[0];
		if ((tmp[0] > st_b->size / 2 && i + tmp[1] < min)
			|| (tmp[0] >= i && tmp[0] < min) || (tmp[0] < i && i < min))
			*min_mvt = tmp[0];
		if (tmp[0] > st_b->size / 2 && i + tmp[1] < min)
			min = i + tmp[1];
		else if (tmp[0] >= i && tmp[0] < min)
			min = tmp[0];
		else if (tmp[0] < i && i < min)
			min = i;
	}
	return (min);
}

size_t	less_mvt_at_end(size_t minimal_mvt, size_t *min_mvt,
	t_stack *st_a, t_stack *st_b)
{
	size_t	i;
	size_t	m;
	size_t	t[2];

	if (minimal_mvt > st_b->size / 2)
		minimal_mvt = st_b->size - minimal_mvt;
	m = minimal_mvt + 1;
	i = st_a->size;
	while (--i > 0 && (st_a->size - i) < minimal_mvt)
	{
		t[0] = closer_pos_to_inf(st_a->array[i], st_b);
		t[1] = st_b->size - t[0];
		if ((t[0] > st_b->size / 2 && t[1] >= (st_a->size - i) && t[1] < m)
			|| (t[0] > st_b->size / 2 && t[1] < (st_a->size - i)
				&& (st_a->size - i) < m) || ((st_a->size - i) + t[0] < m))
			*min_mvt = t[0];
		if (t[0] > st_b->size / 2 && t[1] >= (st_a->size - i) && t[1] < m)
			m = t[1];
		else if (t[0] > st_b->size / 2 && t[1] < (st_a->size - i)
			&& (st_a->size - i) < m)
			m = (st_a->size - i);
		else if ((st_a->size - i) + t[0] < m)
			m = (st_a->size - i) + t[0];
	}
	return (m);
}
