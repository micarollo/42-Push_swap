/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:57:05 by mrollo            #+#    #+#             */
/*   Updated: 2022/07/18 13:01:58 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	int				content;
	int				position;
	char			*binario;
	struct s_list	*next;
}			t_list;

t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list *lst, t_list *new);
t_list  *ft_lstnew(int content);
void    ft_swap(int *a, int *b);
int    *ft_sort_int_tab(int *tab, int size);
void    pb(t_list *a, t_list *b);
void    pa(t_list *a, t_list *b);
void    ra(t_list *a);
int check_doubles(int *stack, int len);
//void	check_stack(int *stack, int len);
void    sa(t_list *a);
void    sb(t_list *b);
void	quick_sort(t_list *a, int len_stack);
void	print_lst(t_list *a, t_list *b);
void	rra(t_list *a);

#endif
