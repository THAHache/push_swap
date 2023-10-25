/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:43:21 by jperez-r          #+#    #+#             */
/*   Updated: 2023/10/25 18:27:36 by jperez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include "./libft/libft.h"

/*typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
long	ft_atoilong(const char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void const *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);*/
void	lstfill(t_list **lsta, char **s);
int		lstisOrder(t_list *lst);
void	delnode (t_list *lsta);
//int		ft_lstsize(t_list *lst);

void	printlst(char c, t_list *lst);
void	ss(char *s, t_list **lst);
void	rr(char *s, t_list *lst);
void	rrr(char *s, t_list *lst);
void	pab (char *s, t_list **lsta, t_list **lstb);
void	pa (char *s, t_list *lsta, t_list *lstb);

//void	ssCheck(t_list **lsta, t_list **lstb);

void	threeArgs(t_list **lst);
void	fourArgs(t_list **lsta, t_list **lstb);
void	fiveArgs(t_list **lsta, t_list **lstb);
int		main(int argc, char *argv[]);

#endif
