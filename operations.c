/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:39:45 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/15 20:39:48 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_list *a)
{
	t_list *aux1;
  	t_list *aux2;

	aux1 = a->next; //8                                                                                             
	aux2 = aux1->next->next;
	//printf("aux1: %d\n", aux1->content);                                                                          
	//printf("aux2: %d\n", aux2->content);                                                                          
    a->next = a->next->next;
	//printf("elemento 1: %d\n", a->next->content);
	aux1->next = aux2;
	a->next->next = aux1;
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
}
