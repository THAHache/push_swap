/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:21:09 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 14:21:39 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Función para mover nodos de una lista a la otra
*/

void	push(t_list **lstori, t_list **lstdst)
{
	t_list	*aux;

	aux = NULL;
	aux = (*lstori)->next;
	(*lstori)->next = *lstdst;
	*lstdst = *lstori;
	*lstori = aux;
	aux = NULL;
}

void	pab(char *s, t_list **lsta, t_list **lstb)
{
	if (s[1] == 'a')
	{
		push(lstb, lsta);
		ft_putstr_fd(s, 1);
	}
	else
	{
		push(lsta, lstb);
		ft_putstr_fd(s, 1);
	}
}
