/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:57:50 by mrollo            #+#    #+#             */
/*   Updated: 2022/07/27 18:01:49 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_list *a)
{
	t_list	*aux;
	t_list	*head;
	t_list	*lst;

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
	t_list	*aux;
	t_list	*head;
	t_list	*lst;

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
	t_list	*auxa;
	t_list	*auxb;
	t_list	*a_to_b;

	a_to_b = a->next;
	auxa = a->next->next;
	auxb = b->next;
	a->next = auxa;
	b->next = a_to_b;
	b->next->next = auxb;
	write(1, "pb\n", 3);
}

void	pa(t_list *a, t_list *b)
{
	t_list	*auxa;
	t_list	*auxb;
	t_list	*b_to_a;

	b_to_a = b->next;
	auxb = b->next->next;
	auxa = a->next;
	a->next = b_to_a;
	b->next = auxb;
	a->next->next = auxa;
	write(1, "pa\n", 3);
}
