/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:14:06 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 14:21:32 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * SS
 * Función para intercambiar los dos primeros nodos de la lista.
 * SA, SB y SS
*/
void	swap(t_list **lst)
{
	t_list	*aux;

	aux = NULL;
	aux = ft_lstnew((*lst)->content);
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = aux->content;
	free (aux);
}

int	ss(t_list **lsta, t_list **lstb, int flag)
{
	if (rev_first_ord(*lsta))
	{
		swap(lsta);
		flag = 1;
	}
	if (first_ord(*lstb))
	{
		swap(lstb);
		flag = 1;
	}
	if (flag == 1)
		ft_putstr_fd("ss\n", 1);
	return (flag);
}

void	sa(t_list **lsta, t_list **lstb)
{
	int	flag;

	flag = 0;
	if ((*lsta)->next)
		swap(lsta);
	if (*lstb && (*lstb)->next != NULL)
		flag = ss(lsta, lstb, flag);
	if (!flag)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_list **lsta, t_list **lstb)
{
	int	flag;

	flag = 0;
	if ((*lstb)->next)
		swap(lstb);
	flag = ss(lsta, lstb, flag);
	if (!flag)
		ft_putstr_fd("sb\n", 1);
}
