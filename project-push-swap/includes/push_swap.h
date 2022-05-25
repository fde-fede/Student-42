/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 13:22:46 by fde-fede          #+#    #+#             */
/*   Updated: 2022/05/19 13:22:46 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

int     main(int argc, char **argv);
void    sort_stack(t_stack **root_a, t_stack **root_b);
void    sort_three(t_stack **root_a);
void    sort_five(t_stack **root_a, t_stack **root_b, int lo, int size);
void    big_sort(t_stack **root_a, t_stack **root_b, int size);
int     shortest_way(t_stack *root, int value);

#endif