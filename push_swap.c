/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:45:22 by jperez-r          #+#    #+#             */
/*   Updated: 2023/10/25 16:50:50 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Función para ordenar si hay 3 argumentos
 * Si me paso de líneas, puedo devolver un booleano para repetir el proceso haciendo una primera vez
 * los sa y en la segunda vuelta los ra o rra. También se podría hacer de manera recursiva,
 * que quizá ocupe menos.
*/
void	threeArgs(t_list **lst)
{
	if ((*lst)->content < (*lst)->next->content)
	{
		if ((*lst)->content < ft_lstlast(*lst)->content &&
			(*lst)->next->content > ft_lstlast(*lst)->content)
		{
			//write(1, "sa\nra\n", 6);
			ss("sa\n", lst);
			rr("ra\n", *lst);
		}
		if ((*lst)->content > ft_lstlast(*lst)->content)
			//write(1, "rra\n", 4);
			rrr("rra\n", *lst);
	}
	else
	{
		if ((*lst)->next->content > ft_lstlast(*lst)->content)
		{
			//write(1, "sa\nrra\n", 7);
			ss("sa\n", lst);
			rrr("rra\n", *lst);
		}
		else
		{
			if((*lst)->content < ft_lstlast(*lst)->content)
				//write(1, "sa\n", 3);
				ss("sa\n", lst);
			else
				//write(1, "ra\n", 3);
				rr("ra\n", *lst);
		}
	}
	//printf("hola\n___________________\n\n");
}


/**
 * Función para 4 argumentos
 * En muchos casos el camino más corto es enviar el elemento más pequeño entre
 * las posiciones 1, 2 y 4
*/
void	fourArgs(t_list **lsta, t_list **lstb)
{
	while(!lstisOrder(*lsta))
	{
		/*if ((*lsta)->content > (*lsta)->next->content)
		{
			if((*lsta)->next->content < ft_lstlast(*lsta)->content)
				ss("sa\n", lsta);
			else
				rr("ra\n", *lsta);
		}*/
		if ((*lsta)->content > (*lsta)->next->content)
		{
			if((*lsta)->next->content > ft_lstlast(*lsta)->content &&
				(*lsta)->next->content > (*lsta)->next->next->content)
				ss("sa\n", lsta);
				//printf("hola\n___________________\n\n");
				/**
				 * if(((*lsta)->next->content > ft_lstlast(*lsta)->content && (*lsta)->next->content > (*lsta)->next->next->content) ||
				((*lsta)->next->content > ft_lstlast(*lsta)->content && (*lsta)->next->content < (*lsta)->next->next->content && (*lsta)->next->next->content > ft_lstlast(*lsta)->content && (*lsta)->content > (*lsta)->next->next->content))
					rrr("rra\n", *lsta);
				else if((*lsta)->content > ft_lstlast(*lsta)->content && (*lsta)->next->content < ft_lstlast(*lsta)->content)
					rr("ra\n", *lsta);
				*/
			if((*lsta)->next->content > ft_lstlast(*lsta)->content)
			{
				if (((*lsta)->next->content > (*lsta)->next->next->content) ||
					((*lsta)->next->content < (*lsta)->next->next->content &&
					(*lsta)->next->next->content > ft_lstlast(*lsta)->content &&
					(*lsta)->content > (*lsta)->next->next->content))
					rrr("rra\n", *lsta);
				else
					ss("sa\n", lsta);
			}
			else if((*lsta)->content > ft_lstlast(*lsta)->content)
				rr("ra\n", *lsta);
			else
				ss("sa\n", lsta);
		}
		else
		{
			/*if((*lsta)->content > ft_lstlast(*lsta)->content)
				rrr("rra\n", *lsta);*/
			if((*lsta)->next->content > ft_lstlast(*lsta)->content &&
				(*lsta)->next->next->content < ft_lstlast(*lsta)->content &&
				(*lsta)->content < ft_lstlast(*lsta)->content)
				ss("sa\n", lsta);
			else if(((*lsta)->next->next->content > (*lsta)->next->content &&
				(*lsta)->next->content > ft_lstlast(*lsta)->content) ||
				((*lsta)->content > ft_lstlast(*lsta)->content &&
				(*lsta)->next->next->content < ft_lstlast(*lsta)->content))
				rrr("rra\n", *lsta);
				//printf("hola\n___________________\n\n");
			else if((*lsta)->next->next->content < (*lsta)->next->content &&
				(*lsta)->next->next->content > ft_lstlast(*lsta)->content &&
				(*lsta)->content > ft_lstlast(*lsta)->content)
				rr("ra\n", *lsta);
			else
			{
				pab("pb\n", lsta,  lstb);
				//printf("hola\n___________________\n\n");
				threeArgs(lsta);
				if(lstb)
					pab("pa\n", lsta,  lstb);
			}
		}



		/*if((*lsta)->content > (*lsta)->next->content && (*lsta)->next->content < ft_lstlast(*lsta)->content)
		{
			//printlst('a', *lsta);
			ss("sa\n", lsta);

			//printf("hola\n___________________\n\n");
		}
		else if((*lsta)->content < (*lsta)->next->content && (*lsta)->content < ft_lstlast(*lsta)->content)
		{
			pab("pb\n", lsta,  lstb);
			//printf("hola\n___________________\n\n");
			threeArgs(lsta);
			if(lstb)
				pab("pa\n", lsta,  lstb);
		}
		else if((*lsta)->content < (*lsta)->next->content && (*lsta)->content > ft_lstlast(*lsta)->content)
		{
			rrr("rra\n", *lsta);
		}
		else
			rr("ra\n", *lsta);*/

	}



		//printf("b:%ld\n", (long)lstb->content);

	//if(lstisOrder(lsta))
		//printf("hola\n___________________\n\n");
		//pab('a', &lsta,  &lstb);
	//printf("a:%ld\n", (long)lsta->content);
	//printf("a:%ld\n", (long)lsta->next->content);
	//printf("b:%ld\n", (long)lstb->content);
	//printf("%ld\n", (long)lstb->next->content);
	//printf("%ld\n", (long)ft_lstlast(lstb)->content);
	//threeArgs(lsta);
	//pab('a', lsta,  lstb);

}


/*void fourArgs(int *sa, int *sb)
{
	int aux;
	if (sa[0] < sa[1] && sa[0] < sa[3])
	{
		sb[0] = sa[0];
		sa = pab('b', sa);
	}

	aux = 0;
	while (sa[aux] != '\0')
	{
		//write(1, sa[aux]+'0', 3);
		write(1, "\n", 1);
		aux++;
	}
}*/


/**
 * Función para evaluar los casos en los que haya 5 argumentos
 * En el caso más pequeño, hago PB y PA y a correr.
 * SA PB PB es equivalente a PB PB SB y PA PA SA = SB PA PA, entonces SA PB PB SA = PB PB SS y
 * SA PA PA SA = SS PA PA
*/

void	fiveArgs(t_list **lsta, t_list **lstb)
{
	int con = 7; //Para evitar bucle infinito

	while(!lstisOrder(*lsta) && con > 0)
	//while(!lstisOrder(*lsta))
	{
		if((*lsta)->content > (*lsta)->next->content)
		{
			//printf("holaa\n___________________\n\n");
			/*if((*lsta)->next->content > ft_lstlast(*lsta)->content)
				ss("sa\n", lsta);*/
			if((*lsta)->content > ft_lstlast(*lsta)->content)
				rr("ra\n", *lsta);
			else
				ss("sa\n", lsta);
				//ssCheck(lsta, lstb);
		}
		else
		{
			//printf("holab\n___________________\n\n");
			if((*lsta)->content > ft_lstlast(*lsta)->content/* ||
				((*lsta)->content < ft_lstlast(*lsta)->content &&
				(*lsta)->next->content > ft_lstlast(*lsta)->content)*/)
				rrr("rra\n", *lsta);
			else{
				pab("pb\n", lsta,  lstb);
				if(ft_lstsize(*lsta) > 4)
					fiveArgs(lsta, lstb);
				else
					fourArgs(lsta, lstb);
				//printf("hola\n___________________\n\n");
				if(lstb)
					pab("pa\n", lsta,  lstb);
			}
		}
		con--;
	}
}



int	main(int argc, char *argv[])
{
	//int *a;
	//int *b;
	int i;
	char *carg;
	t_list *a;
	t_list *b;
	//long l;
/**
 * ¿Pasar primero el atoi a la lista para validar la entrada con argumentos?
 * Por ejemplo, para meter {./push_swap "2 3 1 4"}, que ahora mismo no haría nada
*/
	//Siempre inicializar las listas a NULL para evitar problemas
	a = NULL;
	b = NULL;
	i = 0;
	carg = NULL;

	if(argc == 2)
	{
		/**
		//carg = argv[1];
		while (argv[1][i] != '\0')
		{
			if(carg)
			i++;
		}
*/
		//Utilizar split para separar la cadena por espacios (o el caracter que sea)
		/*lstfill(&a, &carg);
		printf("hola\n___________________\n\n");

		printlst('a', a);*/
	}
	if(argc>2) //&& !isOrder(argv))
	{
		lstfill(&a, argv);
		if(lstisOrder(a))
			return (1);
		if (argc == 3)
			write(1, "sa\n", 3);
		if (argc == 4)
			threeArgs(&a);
		if (argc == 5)
			fourArgs(&a, &b);
		if (argc > 5)
			fiveArgs(&a, &b);
		//printlst('a', a);
		//printlst('b', b);
		free(a);
		free(b);
	}
	return (1);
}
