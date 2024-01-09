/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:11:07 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 12:54:38 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Funciones para conseguir los dos numeros mas grandes y mas pequeños
*/
int	big_num(t_list *lst)
{
	int	bn;

	bn = (long)lst->content;
	while (lst->next)
	{
		if (bn < (long)lst->next->content)
			bn = (long)lst->next->content;
		lst = lst->next;
	}
	return (bn);
}

int	sec_big_num(t_list *lst)
{
	int	sbn;
	int	bn;

	bn = big_num(lst);
	if ((long)lst->content == bn)
		lst = lst->next;
	sbn = (long)lst->content;
	while (lst->next)
	{
		if (sbn < (long)lst->next->content
			&& (long)lst->next->content != bn)
			sbn = (long)lst->next->content;
		lst = lst->next;
	}
	return (sbn);
}

int	lil_num(t_list *lst)
{
	int	ln;

	ln = (long)lst->content;
	while (lst->next)
	{
		if (ln > (long)lst->next->content)
			ln = (long)lst->next->content;
		lst = lst->next;
	}
	return (ln);
}

int	sec_lil_num(t_list *lst)
{
	int	sln;
	int	ln;

	ln = lil_num(lst);
	if ((long)lst->content == ln)
		lst = lst->next;
	sln = (long)lst->content;
	while (lst->next)
	{
		if (sln > (long)lst->next->content
			&& (long)lst->next->content != ln)
			sln = (long)lst->next->content;
		lst = lst->next;
	}
	return (sln);
}
