/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:46:10 by fde-fede          #+#    #+#             */
/*   Updated: 2022/04/28 18:11:23 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

void	ft_putchar_i(char c, int *i);
void	ft_putint_i(int nb, int *i2);
void	ft_putnbr_base_i(unsigned int n, char *base, int *i);
void	ft_putstr_i(char *str, int *i2);
void	ft_putui_i(unsigned int nb, int *i);
void	ft_puthex_i(unsigned long long nb, int *i);
int		ft_printf(const char *str, ...);

#endif
