/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:55:52 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 14:31:46 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Funcion para calcular la media sumando el modulo
*/
int	calc_am(int num)
{
	int	am;

	am = num / 2;
	if (num % 2 != 0)
		am++;
	return (am);
}

/**
 * Funcion para ir colocando el stack b mientras se va llenando
*/
void	order_b(t_list **lsta, t_list **lstb)
{
	if ((*lstb)->content < (*lstb)->next->content)
	{
		if ((long)(*lstb)->next->content - (long)(*lstb)->content > 2)
			rb(*lstb, *lsta);
		else
			sb(lsta, lstb);
	}
}

/**
 * Funcion para controlar el flujo de numeros en el stack a si hay mas de 5
*/
int	more_num(int len, t_list **lsta, t_list **lstb, int ci)
{
	if ((long)(*lsta)->content - (long)(*lsta)->next->content == 1)
		sa(lsta, lstb);
	move_a(len, lsta, lstb, ci);
	if (!lstis_order_strict(*lsta))
	{
		pab("pb\n", lsta, lstb);
		ci++;
	}
	if (*lstb && (*lstb)->next && val_node(*lstb) < val_node((*lstb)->next))
		order_b(lsta, lstb);
	if (ft_lstsize(*lsta) > 5 && !lstis_order_strict(*lsta))
		more_num(len, lsta, lstb, ci);
	else if (ft_lstsize(*lsta) == 5 && !lstis_order(*lsta))
		five_num(lsta, lstb);
	if (*lstb && (*lstb)->next)
		check_big_b(lsta, lstb);
	if (*lstb)
	{
		pab("pa\n", lsta, lstb);
		ci--;
	}
	return (1);
}
