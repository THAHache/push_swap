/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:14:49 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 13:25:59 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Función para evaluar los casos en los que haya 5 argumentos
 * En el caso más pequeño, hago PB y PA y a correr.
 * SA PB PB es equivalente a PB PB SB y PA PA SA = SB PA PA, entonces SA PB PB
 * SA = PB PB SS y SA PA PA SA = SS PA PA
*/
void	reverse_five(t_list **lsta, t_list **lstb)
{
	if (reverse_order(*lsta))
	{
		pab("pb\n", lsta, lstb);
		if (ft_lstsize(*lsta) > 4)
			five_num(lsta, lstb);
		else
			four_num(lsta, lstb);
		if (lstb)
			pab("pa\n", lsta, lstb);
	}
}

void	five_num(t_list **lsta, t_list **lstb)
{
	reverse_five(lsta, lstb);
	while (!lstis_order(*lsta))
	{
		if ((*lsta)->content > (*lsta)->next->content)
		{
			if ((*lsta)->content > ft_lstlast(*lsta)->content)
				ra(*lsta, *lstb);
			else
				sa(lsta, lstb);
		}
		else
		{
			if ((*lsta)->content > ft_lstlast(*lsta)->content)
				rra(*lsta, *lstb);
			else
			{
				pab("pb\n", lsta, lstb);
				four_num(lsta, lstb);
				if (lstb)
					pab("pa\n", lsta, lstb);
			}
		}
	}
}
