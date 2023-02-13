/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttomatrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:17:38 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/11 12:38:24 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	**ft_lsttomatrix(t_list *lst)
{
	char	**matrix;
	t_list	*aux;
	char	*temp;

	aux = lst;
	matrix = NULL;
	while (aux)
	{
		temp = ft_strdup(aux->content);
		matrix = ft_extend_matrix(matrix, temp);
		aux = aux->next;
		free(temp);
	}
	return (matrix);
}
