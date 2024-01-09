/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:50:42 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 13:21:58 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Funcion para encontrar un numero menor que la media
*/

int	low_num(t_list *lst, int len, int am, int ci)
{
	int	min;
	int	max;

	min = 0;
	while (min < am && ((long)lst->content > len - 5
			|| (long)lst->content > 9 + ci))
	{
		min++;
		lst = lst->next;
	}
	max = 0;
	while (lst)
	{
		if ((long)lst->content > len - 5 || (long)lst->content > 9 + ci)
			max++;
		else
			max = 1;
		lst = lst->next;
	}
	if (min > max)
		min = len - ci - max;
	return (min);
}

/**
 * Movimientos en el stack a antes de hacer pb
*/
void	move_a(int len, t_list **lsta, t_list **lstb, int ci)
{
	int	nmov;

	if ((long)(*lsta)->content > 9 + ci || (long)(*lsta)->content > len - 5)
	{
		nmov = low_num(*lsta, len, calc_am(len - ci), ci);
		if (nmov < calc_am(len - ci))
		{
			while (nmov > 0)
			{
				ra(*lsta, *lstb);
				nmov--;
			}
		}
		else
		{
			while (len - ci - nmov > 0)
			{
				rra(*lsta, *lstb);
				nmov++;
			}
		}
	}
}

/**
 * Funcion para encontrar la posicion del numero mas grande de b
*/
int	big_position(t_list *lst)
{
	int	pos;

	pos = 1;
	while (lst->next && (long)lst->content != big_num(lst))
	{
		if ((long)(lst)->content != big_num(lst))
			pos++;
		lst = (lst)->next;
	}
	return (pos);
}

/**
 * Movimientos en el stack b antes de hacer pa
*/
void	move_b(t_list **lsta, t_list **lstb, int len)
{
	int	nmov;

	nmov = big_position(*lstb);
	if (nmov < calc_am(len))
	{
		while (nmov > 1)
		{
			rb(*lstb, *lsta);
			nmov--;
		}
	}
	else
	{
		while (len - nmov >= 0)
		{
			rrb(*lstb, *lsta);
			nmov++;
		}
	}
}

/**
 * Funcion para poner el numero mas alto del stack b en la primera posicion
*/
int	check_big_b(t_list **lsta, t_list **lstb)
{
	if (val_node((*lstb)->next) - val_node(*lstb) == 1)
		sb(lsta, lstb);
	if (val_node(*lstb) != big_num(*lstb))
		move_b(lsta, lstb, ft_lstsize(*lstb));
	return (1);
}
