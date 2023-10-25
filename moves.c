/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:50:42 by jperez-r          #+#    #+#             */
/*   Updated: 2023/10/11 13:41:10 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Función para mostrar la lista
*/
void	printlst(char c, t_list *lst)
{
	while (lst)
		{
			printf("%c: %ld\n", c, (long)lst->content);
			lst=lst->next;
		}
}
/**
 * SS
 * Función para intercambiar los dos primeros nodos de la lista.
 * SA y SB
*/

void ss(char *s, t_list **lst)
{
	t_list *aux;

	aux = NULL;
	if((*lst)->next)
	{
		aux = ft_lstnew((*lst)->content);
		(*lst)->content = (*lst)->next->content;
		(*lst)->next->content = aux->content;
		ft_putstr_fd(s, 1);
		free (aux);
	}
}

/**
 * RR
 * Función para pasar el primer nodo al final de la lista
 * RA y RB
*/

void rr(char *s, t_list *lst)
{
	t_list *aux;

	aux = NULL;

	if (lst->next)
	{
		aux = ft_lstnew(lst->content);
		//(*lst)->content = (*lst)->next->content;
		//(*lst)->next = (*lst)->next->next;
		while(lst->next)
		{
			//printf("antes%ld\n", (long)(*lst)->content);
			lst->content = lst->next->content;
			//(*lst)->next->content = aux->content;
			//printf("despues%ld\n", (long)(*lst)->content);
			lst = lst->next;
		}
		//ft_lstlast(lst)->next = aux;
		//*lst = ft_lstlast(*lst);
		lst->content = aux->content;
		//printf("hol%ld\n", (long)(*lst)->content);
		//printf("hol%ld\n", (long)ft_lstlast(*lst)->content);

		free (aux);
		ft_putstr_fd(s, 1);
	}
	/*if ((*lst)->next)
	{
		aux = ft_lstnew((*lst)->content);
		//(*lst)->content = (*lst)->next->content;
		//(*lst)->next = (*lst)->next->next;
		while((*lst)->next)
		{
			//printf("antes%ld\n", (long)(*lst)->content);
			(*lst)->content = (*lst)->next->content;
			//(*lst)->next->content = aux->content;
			//printf("despues%ld\n", (long)(*lst)->content);
			*lst = (*lst)->next;
		}
		ft_lstlast(*lst)->next = aux;
		//lst = ft_lstlast(*lst);
		//(*lst)->content = aux->content;
		//printf("hol%ld\n", (long)(*lst)->content);
		//printf("hol%ld\n", (long)ft_lstlast(*lst)->content);

		free (aux);
		ft_putstr_fd(s, 1);
	}*/
	/*if((*lst)->next)
	{
		aux = ft_lstnew((*lst)->content);
		(*lst)->content = ft_lstlast(lst)->content;
		//(*lst)->next->content;
		(*lst)->next->content = aux->content;
		ft_putstr_fd(s, 1);
		//write(1, "sa\n", 3);
	}*/
}

/**
 * RRR
 * Función para pasar el nodo final al principio de la lista
 * RRA y RRB
*/

void rrr(char *s, t_list *lst)
{
	t_list *aux;
	t_list *aux2;

	aux = NULL;
	aux2 = NULL;

	if (lst->next)
	{
		aux = ft_lstnew(lst->content);
		aux2 = ft_lstnew(lst->content);
		//(*lst)->content = (*lst)->next->content;
		//(*lst)->next = (*lst)->next->next;
		lst->content = ft_lstlast(lst)->content;
		//lst = lst->next;
		while(lst->next)
		{
			aux2->content = lst->next->content;
			lst->next->content = aux->content;
			aux->content = aux2->content;
			//aux->content = lst->next;
			//lst->content = lst->next->content;
			lst = lst->next;
		}
		//ft_lstlast(lst)->next = aux;
		//*lst = ft_lstlast(*lst);
		//lst->content = aux->content;
		//printf("hol%ld\n", (long)(*lst)->content);
		//printf("hol%ld\n", (long)ft_lstlast(*lst)->content);

		free (aux);
		ft_putstr_fd(s, 1);
	}
}

/**
 * Función para escribir PA o PB y ordenar el array
*/
void pab (char *s, t_list **lsta, t_list **lstb)
{
	t_list *aux;
	aux = NULL;
	if (s[1] == 'b')
	{
		aux = (*lsta)->next;
		//lstb = ft_lstnew(lsta->content);
		ft_lstadd_front(lstb, ft_lstnew((*lsta)->content));
		//lstb = lsta;
		(*lsta)->content = aux->content;
		(*lsta)->next = aux->next;
		//printf("a1:%ld\n", (long)(*lsta)->content);
		//printf("PB\n");
		//printf("b1:%ld\n", (long)&lstb->content);
	}
	/**
	 * Se podría reducir la función cambiando el nombre de las variables a lstorigen y lstdestino.
	 * Se ahorra tener que poner la flag y un if entero
	*/
	if (s[1] == 'a')
	{
		/*if((*lstb)->next)
			aux = (*lstb)->next;*/
		/*else
			aux = NULL;*/
		//printf("a1:%ld\n", (long)(*lsta)->content);
		ft_lstadd_front(lsta, ft_lstnew((*lstb)->content));
		//delnode(*lstb);
		if((*lstb)->next)
		{
			(*lstb)->content = (*lstb)->next->content;
			(*lstb)->next = (*lstb)->next->next;
		}
		else
			(*lstb)->content = NULL;
		//printf("a2:%ld\n", (long)(*lsta)->content);
		//printlst(*lsta);
		//(*lstb)->content = aux->content;
		//printf("hola\n___________________\n\n");
		/*if(!(*lstb)->next)
			return ;
		(*lstb)->next = aux->next;
		free (aux);*/
	}
	free (aux);
	ft_putstr_fd(s, 1);
}


		//lstb->next = NULL;
		//printf("b2:%ld\n", (long)lstb->next->content);
//printf("hola\n___________________\n\n");
//	}
	/*if (cab == 'a')
	{
		write(1, "pa\n", 3);
		ft_lstadd_front(&lsta, lstb);
		//lsta->content = lstb ->content;
		if (lstb->next)
			lstb = lstb->next;
		//lsta->next = NULL;
	}*/
	/*if (cab == 'b')
	{
		if (lsta->next)
			aux = lsta->next;
		ft_lstadd_front(&lstb, lsta);

			free(lsta);
		//lstb->content = lsta ->content;
			lsta = aux;
		//lstb->next = NULL;
		write(1, "pb\n", 3);

		//ft_lstadd_back(lst, ft_lstnew((void *) ft_atoilong(s[i])));
	}*/
//}

