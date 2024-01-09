/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:16:48 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 12:58:48 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * RR
 * Función para pasar el primer nodo al final de la lista
 * RA y RB
*/
void	rotate(t_list *lst)
{
	t_list	*aux;

	aux = NULL;
	aux = ft_lstnew(lst->content);
	while (lst->next)
	{
		lst->content = lst->next->content;
		lst = lst->next;
	}
	lst->content = aux->content;
	free (aux);
}

void	ra(t_list *lsta, t_list *lstb)
{
	if (lsta->next)
		rotate(lsta);
	if (lstb && lstb->next != NULL && lstb->content < ft_lstlast(lstb)->content)
	{
		rotate(lstb);
		ft_putstr_fd("rr\n", 1);
	}
	else
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_list *lsta, t_list *lstb)
{
	if (lsta->next)
		rotate(lsta);
	if (lstb && lstb->next != NULL && lstb->content > ft_lstlast(lstb)->content)
	{
		rotate(lstb);
		ft_putstr_fd("rr\n", 1);
	}
	else
		ft_putstr_fd("rb\n", 1);
}
