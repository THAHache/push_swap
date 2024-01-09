/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:45:22 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/09 18:44:07 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Función para copiar una lista de enteros en un array
*/
int	*iltoa(t_list *lst)
{
	int	*dst;
	int	i;

	i = 0;
	dst = malloc(ft_lstsize(lst) * sizeof(int));
	if (!dst)
		return (0);
	while (lst->next)
	{
		dst[i] = (long)lst->content;
		i++;
		lst = lst->next;
	}
	dst[i] = (long)lst->content;
	return (dst);
}

/**
 * Funcion para devolver el valor de un nodo de la lista en tipo long
*/
long	val_node(t_list *lst)
{
	return ((long) lst->content);
}

/**
 * Funcion para el control de errores.
 * Sólo hay números, los símbolos + y - y el espacio
 * No habrá números repetidos
 * Los valores tienen que estar comprendidos entre el intmin(-2147483648) y el
 * intmax (2147483647)
*/

int	error_controlps(char **s, t_list **lst)
{
	int		numlen;
	long	*nums;

	numlen = ft_num_count(s, 0);
	if (!numlen)
		return (0);
	nums = ft_aatola(s, numlen, 1, 0);
	if (!numrep(nums, numlen) || !lstindex(nums, lst, numlen, 0))
	{
		free(nums);
		return (0);
	}
	free(nums);
	return (1);
}

/**
 * Funcion para controlar el flujo del programa
*/
int	push_swap(t_list **a, t_list **b, int lstsize)
{
	if (lstis_order_strict(*a))
		return (1);
	if (lstsize == 2)
		write(1, "sa\n", 3);
	if (lstsize == 3)
		three_num(a, b);
	if (lstsize == 4)
		four_num(a, b);
	if (lstsize == 5)
		five_num(a, b);
	if (lstsize > 5)
		more_num(lstsize, a, b, 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!error_controlps(argv, &a))
	{
		ft_putstr_fd("Error\n", 2);
		freeab(&a, &b);
		return (0);
	}
	if (!lstis_order_strict(a))
		push_swap(&a, &b, ft_lstsize(a));
	freeab(&a, &b);
	return (1);
}
