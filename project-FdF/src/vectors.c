/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 19:52:33 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/26 21:47:33 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vector	subtraction_vectors(t_vector fst_vector, t_vector scnd_vector)
{
	t_vector	sol;

	sol.x = fst_vector.x - scnd_vector.x;
	sol.y = fst_vector.y - scnd_vector.y;
	return (sol);
}

t_vector	create_vector(int x, int y, int z)
{
	t_vector	sol;

	sol.x = x;
	sol.y = y;
	sol.z = z;
	return (sol);
}
