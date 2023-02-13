/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-fede <fde-fede@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 09:01:49 by fde-fede          #+#    #+#             */
/*   Updated: 2023/02/11 12:38:24 by fde-fede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstget_at(t_list *lst, int i)
{
	t_list	*target;
	int		j;

	j = 0;
	if (!lst)
		return (NULL);
	while (lst && j++ < i)
		lst = lst->next;
	target = lst;
	return (target);
}
