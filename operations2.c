/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 18:01:11 by mrollo            #+#    #+#             */
/*   Updated: 2022/07/27 18:01:36 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_list *a)
{
	t_list	*temp;
	t_list	*first;
	t_list	*end;

	end = ft_lstlast(a);
	first = a->next;
	temp = first->next;
	a->next = temp;
	end->next = first;
	first->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_list *a)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;
	t_list	*temp;

	n1 = a->next;
	temp = n1;
	n2 = NULL;
	while (temp != NULL)
	{
		if (temp->next->next == NULL)
		{
			n2 = temp;
			break ;
		}
		temp = temp->next;
	}
	n3 = ft_lstlast(a);
	a->next = n3;
	a->next->next = n1;
	n2->next = NULL;
	write(1, "rra\n", 4);
}
