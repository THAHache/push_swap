/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 13:05:05 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 12:58:17 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_num(t_list **lsta, t_list **lstb)
{
	if ((long)(*lsta)->content == big_num(*lsta))
		ra(*lsta, *lstb);
	else if ((long)(*lsta)->next->content == big_num(*lsta))
		rra(*lsta, *lstb);
	if ((*lsta)->content > (*lsta)->next->content)
		sa(lsta, lstb);
}

/**
 * Funcion para encontrar pequeños grupos de numeros ordenados
*/

int	order_group(t_list *lst)
{
	int		*lint;
	int		count;
	long	i;

	lint = iltoa(lst);
	count = 0;
	while (lst->next && count == 0)
	{
		i = 0;
		if ((long)lst->next->content - (long)lst->content > 0)
		{
			count = 1;
			while (i <= ft_lstsize(lst) && count == 1)
			{
				if (lint[i] > (long)lst->content
					&& lint[i] < (long)lst->next->content)
					count = 0;
				i++;
			}
		}
		lst = lst->next;
	}
	free (lint);
	return (count);
}

/**
 * Función para 4 argumentos
*/
void	four_num(t_list **lsta, t_list **lstb)
{
	while (!lstis_order(*lsta))
	{
		if (rev_first_ord(*lsta) || (val_node((*lsta)->next) == lil_num(*lsta)
				&& val_node(*lsta) == sec_big_num(*lsta))
			|| (val_node(*lsta) == lil_num(*lsta) && order_group(*lsta) != 0
				&& val_node((*lsta)->next) == big_num(*lsta)))
			sa(lsta, lstb);
		else if (val_node(*lsta) == lil_num(*lsta) && (order_group(*lsta) == 0
				|| val_node((*lsta)->next) == sec_lil_num(*lsta)))
		{
			pab("pb\n", lsta, lstb);
			three_num(lsta, lstb);
			pab("pa\n", lsta, lstb);
		}
		else
		{
			if ((val_node(*lsta) == big_num(*lsta)
					&& val_node(ft_lstlast(*lsta)) == sec_big_num(*lsta))
				|| (val_node((*lsta)->next) == big_num(*lsta)
					&& val_node(ft_lstlast(*lsta)) == lil_num(*lsta)))
				ra(*lsta, *lstb);
			else
				rra(*lsta, *lstb);
		}
	}
}
