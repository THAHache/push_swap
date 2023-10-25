/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:51:20 by jperez-r          #+#    #+#             */
/*   Updated: 2023/10/25 18:14:20 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}*/

/*void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}*/

/**
 * Comprobar si el caracter es un número
*/
/*int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}*/
/**
 * Atoi devuelve un entero a partir de una cadena
*/
/*int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num += (int)str[i] - 48;
		i++;
	}
	return (num * neg);
}*/

/*long	ft_atoilong(const char *str)
{
	long	num;
	long	signo;
	long	i;

	num = 0;
	signo = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signo = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * signo);
}*/
/**
 * Funcion para ir al final de la lista
*/
/*t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}*/
/**
 * Función para agregar un luevo nodo a la lista
*/
/*t_list	*ft_lstnew(void const *content)
{
	t_list	*lis;

	lis = malloc(sizeof(*lis));
	if (!lis)
		return (0);
	lis->content = (void *)content;
	lis->next = NULL;
	return (lis);
}*/

/**
 * Añadir nodo al final de la lista
*/
/*void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}*/

/**
 * Añadir nodo al inicio de la lista
*/
/*void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}*/

/**
 * Función para copiar los argumentos en la lista a
*/
void	lstfill(t_list **lsta, char **s)
{
	int i;

	i = 1;
	while (s[i]!= '\0')
	{
		ft_lstadd_back(lsta, ft_lstnew((void *) ft_atoilong(s[i])));
		i++;
	}
	//ft_lstadd_front(lstb, ft_lstnew(NULL));

		/**
		 * Esos prints comprueban que los nodos se crean correctamente
		*/
		//printf("%ld\n", l);
		//printf("%ld", (long)(*lst)->next->content);
}

/**
 * Comprobar si la lista está ya ordenada
*/
int	lstisOrder(t_list *lst)
{
	while(lst->next!=NULL)
	{
		if(lst->content > lst->next->content)
			return (0);
	//write(1, "aqui\n", 5);
		lst = lst->next;
	}
	return(1);
}

/**
 * Función para borrar el primer nodo
*/

/*
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
		lst = NULL;
	}
}
*/
void	delnode (t_list *lst)
{
	t_list *aux;

	aux = NULL;
	if(lst->next)
	{
		aux = lst;
		lst = aux->next;
	}
	else
		lst = aux;
	//printf("%ld\n", (long)lsta->content);
	free (aux);

}

/*int	ft_lstsize(t_list *lst)
{
	int size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}*/
