/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 03:10:42 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/09 18:43:18 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * Funcion que se encarga de gestionar que todos los caracteres que hay en las
 * cadenas sean números, espacios o los signos + y -
*/
int	ft_num_count(char **s, int count)
{
	int	i;
	int	j;

	i = 1;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			while (s[i][j] == 32)
				j++;
			if (s[i][j] == 43 || s[i][j] == 45)
				j++;
			while (s[i][j] && s[i][j] != 32)
			{
				if (!ft_isdigit(s[i][j]))
					return (0);
				j++;
			}
			if (s[i][j - 1] && ft_isdigit(s[i][j - 1]))
				count++;
		}
		i++;
	}
	return (count);
}

/**
 * Funcion para guardar los numeros en un array de enteros
*/
long	*ft_aatola(char **s, int len, int i, int j)
{
	int		k;
	char	**aux;
	long	*dst;

	dst = malloc(sizeof(long) * len + 1);
	if (!dst)
		return (0);
	aux = NULL;
	k = 0;
	while (s[i])
	{
		aux = ft_split(s[i], ' ');
		j = 0;
		while (aux[j])
		{
			dst[k] = ft_atoilong(aux[j]);
			free(aux[j]);
			k++;
			j++;
		}
		dst[k] = '\0';
		free(aux);
		i++;
	}
	return (dst);
}

/**
 * Funcion para comprobar si hay numeros repetidos y que entren dentro de los
 * valores INT_MAX e INT_MIN
*/
int	numrep(long *l, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		if (l[i] < -2147483648 || l[i] > 2147483647)
			return (0);
		while (j < len)
		{
			if (l[i] == l[j] || l[j] < -2147483648 || l[j] > 2147483647)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/**
 * Funcion para llenar la lista con los valores si todo está bien
*/
void	lstfill(t_list **lsta, long *ind)
{
	int	i;

	i = 0;
	while (ind[i])
	{
		ft_lstadd_back(lsta, ft_lstnew((void *) ind[i]));
		i++;
	}
}

/**
 * Funcion para darle los valores mas bajos posibles a la lista sin perder
 * el orden
*/
int	lstindex(long *ai, t_list **lst, int len, int i)
{
	long	*ind;
	int		j;
	int		cont;

	ind = malloc(sizeof(long) * len + 1);
	if (!ind)
		return (0);
	while (i < len)
	{
		j = 0;
		cont = 1;
		while (j < len)
		{
			if (ai[i] > ai[j])
				cont++;
			j++;
		}
		ind[i] = cont;
		i++;
	}
	ind[i] = '\0';
	lstfill(lst, ind);
	free (ind);
	return (1);
}
