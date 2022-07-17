/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:55:20 by fde-fede          #+#    #+#             */
/*   Updated: 2022/07/16 17:13:48 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	check_arguments(int argc, char *argv[])
{
	if (argc > 501 && argc < 2)
	{
		ft_printf("%s\n", "please, insert from 1 to 500 numbers");
		return (0);
	}
	else
		return (1);
}
