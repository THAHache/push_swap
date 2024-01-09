/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:43:21 by jperez-r          #+#    #+#             */
/*   Updated: 2024/01/05 14:32:15 by jperez-r         ###   ########.fr       */
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

int		ft_num_count(char **s, int count);
long	*ft_aatola(char **s, int len, int i, int j);
int		numrep(long *l, int len);
void	lstfill(t_list **lsta, long *ind);
int		lstindex(long *ai, t_list **lst, int len, int i);

void	free_lst(t_list **lst);
void	freeab(t_list **a, t_list **b);

int		first_ord(t_list *lst);
int		rev_first_ord(t_list *lst);
int		lstis_order(t_list *lst);
int		lstis_order_strict(t_list *lst);
int		reverse_order(t_list *lst);

int		lil_num(t_list *lst);
int		sec_lil_num(t_list *lst);
int		big_num(t_list *lst);
int		sec_big_num(t_list *lst);

void	swap(t_list **lsta);
int		ss(t_list **lsta, t_list **lstb, int flag);
void	sa(t_list **lsta, t_list **lstb);
void	sb(t_list **lsta, t_list **lstb);

void	push(t_list **lstori, t_list **lstdst);
void	pab(char *s, t_list **lsta, t_list **lstb);

void	rotate(t_list *lst);
void	ra(t_list *lsta, t_list *lstb);
void	rb(t_list *lsta, t_list *lstb);

void	reverse_rotate(t_list *lst);
void	rra(t_list *lsta, t_list *lstb);
void	rrb(t_list *lsta, t_list *lstb);

int		low_num(t_list *lst, int len, int am, int ci);
void	move_a(int len, t_list **lsta, t_list **lstb, int ci);
int		big_position(t_list *lst);
void	move_b(t_list **lsta, t_list **lstb, int len);
int		check_big_b(t_list **lsta, t_list **lstb);

void	three_num(t_list **lsta, t_list **lstb);
int		order_group(t_list *lst);
void	four_num(t_list **lsta, t_list **lstb);

void	reverse_five(t_list **lsta, t_list **lstb);
void	five_num(t_list **lsta, t_list **lstb);

int		calc_am(int num);
void	order_b(t_list **lsta, t_list **lstb);
int		more_num(int len, t_list **lsta, t_list **lstb, int ci);

int		*iltoa(t_list *lst);
long	val_node(t_list *lst);
int		error_controlps(char **s, t_list **lst);
int		push_swap(t_list **a, t_list **b, int lstsize);
int		main(int argc, char *argv[]);

#endif
