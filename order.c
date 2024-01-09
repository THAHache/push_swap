/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:07:51 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 14:31:11 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Funcion para comprobar si entre el primer y segundo numero hay otro
 * mientras que el primero es superior al segundo
*/
int	rev_first_ord(t_list *lst)
{
	long	fir;
	long	sec;

	fir = (long)lst->content;
	sec = (long)lst->next->content;
	if (fir - sec < 1)
		return (0);
	while (lst->next && fir - sec != 1)
	{
		if (val_node(lst->next) < fir && val_node(lst->next) > sec)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	first_ord(t_list *lst)
{
	long	fir;
	long	sec;

	fir = (long)lst->content;
	sec = (long)lst->next->content;
	if (sec - fir < 1)
		return (0);
	while (lst->next && sec - fir != 1)
	{
		if (val_node(lst->next) > fir && val_node(lst->next) < sec)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/**
 * Comprobar si la lista está ya ordenada
*/
int	lstis_order(t_list *lst)
{
	while (lst->next != NULL)
	{
		if ((long)lst->content > (long)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	lstis_order_strict(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (val_node(lst->next) - val_node(lst) != 1)
			return (0);
		lst = lst->next;
	}
	return (1);
}

/**
 * Funcion para comprobar si la lista está ordenada del reves
*/
int	reverse_order(t_list *lst)
{
	while (lst->next != NULL)
	{
		if ((long)lst->content < (long)lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
