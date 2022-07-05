/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:39:45 by mrollo            #+#    #+#             */

/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_list *a)
{
	t_list *aux;
	t_list *head;
	t_list *lst;

	aux = a->next;
	head = a->next->next;
	lst = head->next;
	a->next = head;
	a->next->next = aux;
	a->next->next->next = lst;
	write(1, "sa\n", 3);
}

void	sb(t_list *b)
{
	t_list *aux;
	t_list *head;
	t_list *lst;

	aux = b->next;
	head = b->next->next;
	lst = head->next;
	b->next = head;
	b->next->next = aux;
	b->next->next->next = lst;
	write(1, "sb\n", 3);
}

void	pb(t_list *a, t_list *b)
{
	t_list *auxa;
	t_list *auxb;
	t_list *a_to_b;

	a_to_b = a->next;
	auxa = a->next->next;
	auxb = b->next;
	a->next = auxa;
	b->next = a_to_b;
	b->next->next = auxb;
	write(1, "pb\n", 3);
}

void    pa(t_list *a, t_list *b)
{
	t_list *auxa;
	t_list *auxb;
	t_list *b_to_a;

	b_to_a = b->next;
	auxb = b->next->next;
	auxa = a->next;
	a->next = b_to_a;
	b->next = auxb;
	a->next->next = auxa;
	write(1, "pa\n", 3);
}

void	ra(t_list *a)
{
	t_list *temp;
	t_list *first;
	t_list *end;

	end = ft_lstlast(a);
	first = a->next;
	temp = first->next;
	a->next = temp;
	end->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}
