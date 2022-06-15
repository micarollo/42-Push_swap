/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:57:05 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/15 21:17:20 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				content;
	int				position;
	char			*binario;
	struct s_list	*next;
}			t_list;

//char    **ft_split(char const *s, char c);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list *lst, t_list *new);
t_list  *ft_lstnew(int content);
void    ft_swap(int *a, int *b);
int    *ft_sort_int_tab(int *tab, int size);
void    swap(t_list *a);
void    pb(t_list *a, t_list *b);
void    pa(t_list *a, t_list *b);
void    ra(t_list *a);

#endif
