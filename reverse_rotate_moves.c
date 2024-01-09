/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:17:10 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 13:01:03 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * RRR
 * Función para pasar el nodo final al principio de la lista
 * RRA y RRB
*/
void	reverse_rotate(t_list *lst)
{
	t_list	*aux;
	t_list	*aux2;

	aux = NULL;
	aux2 = NULL;
	aux = ft_lstnew(lst->content);
	aux2 = ft_lstnew(lst->content);
	lst->content = ft_lstlast(lst)->content;
	while (lst->next)
	{
		aux2->content = lst->next->content;
		lst->next->content = aux->content;
		aux->content = aux2->content;
		lst = lst->next;
	}
	free (aux);
	free (aux2);
}

void	rra(t_list *lsta, t_list *lstb)
{
	if (lsta->next)
		reverse_rotate(lsta);
	if (lstb && lstb->next && lstb->next->content - lstb->content > 2)
	{
		reverse_rotate(lstb);
		ft_putstr_fd("rrr\n", 1);
	}
	else
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_list *lsta, t_list *lstb)
{
	if (lsta->next)
		reverse_rotate(lsta);
	if (lstb && lstb->next && lstb->content > ft_lstlast(lstb)->content)
	{
		reverse_rotate(lstb);
		ft_putstr_fd("rrr\n", 1);
	}
	else
		ft_putstr_fd("rrb\n", 1);
}
