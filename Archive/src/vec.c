/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jestrada <jestrada@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:45:39 by jestrada          #+#    #+#             */
/*   Updated: 2022/05/18 22:01:40 by jestrada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//return subtraction of vectors

t_vec	subtraction_vectors(t_vec vec1, t_vec vec2)
{
	t_vec	ret;

	ret.x = vec1.x - vec2.x;
	ret.y = vec1.y - vec2.y;
	return (ret);
}

t_vec	create_vector(int x, int y, int z)
{
	t_vec	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}
