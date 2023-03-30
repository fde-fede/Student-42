/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_analysis_flags_extras.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:17:39 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/22 17:17:53 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prinft_analysis_flag_width(const char **str)
{
	int	width;

	width = 0;
	if (ft_isdigit(**str))
	{
		width = ft_atoi(*str);
		(*str) += ft_intlen(width);
	}
	return (width);
}

int	ft_prinft_analysis_flag_precision(const char **str)
{
	int	precision;

	precision = 0;
	if (**str == '.')
	{
		(*str)++;
		if (!ft_isdigit(**str))
			return (1);
		precision = ft_atoi(*str);
		(*str) += ft_intlen(precision);
		precision++;
	}
	return (precision);
}

int	ft_prinft_analysis_precision_to_padding(t_placeholder *placeholder)
{
	int	precision;

	if (ft_isset(placeholder->type, "diuxX") && placeholder->precision >= 2)
	{
		precision = placeholder->precision;
		if (!(placeholder->data[0] == '-'))
			precision--;
		placeholder->zeropadding = 1;
		placeholder->width = precision;
	}
	return (0);
}
