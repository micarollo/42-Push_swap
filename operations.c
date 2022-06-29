/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:39:45 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/29 15:29:00 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
	//printf("end: %d\n", end->content);
	first = a->next; // primer valor de la lista
	//printf("first: %d\n", first->content);
	temp = first->next; //segundo valor
	//printf("temp: %d\n", temp->content);
	a->next = temp;
	//printf("a->next: %d\n", a->next->content);
	end->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}
