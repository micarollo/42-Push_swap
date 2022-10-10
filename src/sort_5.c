/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:52:23 by mrollo            #+#    #+#             */
/*   Updated: 2022/08/04 18:27:45 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	comb1(t_list *a, t_list *b)
{
	rra(a);
	pa(a, b);
	ra(a);
	ra(a);
}

void	comb2(t_list *a, t_list *b)
{
	ra(a);
	pa(a, b);
	sa(a);
	rra(a);
}

void	sort_n1(t_list *a, t_list *b)
{
	t_list	*last;
	t_list	*first;

	first = a->next;
	last = ft_lstlast(a);
	if (b->next->position < first->position)
		pa(a, b);
	else if (b->next->position > last->position)
	{
		pa(a, b);
		ra(a);
	}
	else
	{
		if (b->next->position > a->next->position
			&& b->next->position < a->next->next->position)
		{
			pa(a, b);
			sa(a);
		}
		else
			comb1(a, b);
	}
}

void	sort_n2(t_list *a, t_list *b)
{
	t_list	*last;
	t_list	*first;

	first = a->next;
	last = ft_lstlast(a);
	if (b->next->position < first->position)
		pa(a, b);
	else if (b->next->position > last->position)
	{
		pa(a, b);
		ra(a);
	}
	else if (b->next->position > a->next->next->next->position)
		comb1(a, b);
	else
	{
		if (b->next->position > a->next->position
			&& b->next->position < a->next->next->position)
		{
			pa(a, b);
			sa(a);
		}
		else
			comb2(a, b);
	}
}

void	quick_sort_5(t_list *a, t_list *b)
{
	if (!is_sorted(a))
	{
		pb(a, b);
		pb(a, b);
		quick_sort(a);
		sort_n1(a, b);
		sort_n2(a, b);
	}
}
