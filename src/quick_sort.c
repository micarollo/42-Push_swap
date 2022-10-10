/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 17:50:50 by mrollo            #+#    #+#             */
/*   Updated: 2022/07/27 17:52:04 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	comb_ra(t_list *a)
{
	ra(a);
	ra(a);
}

void	comb_ra_sa(t_list *a)
{
	ra(a);
	sa(a);
}

void	comb_sa_ra(t_list *a)
{
	sa(a);
	ra(a);
}

void	quick_sort(t_list *a)
{
	t_list	*last;

	last = ft_lstlast(a);
	if (a->next->position > a->next->next->position
		&& a->next->position > last->position
		&& last->position > a->next->next->position)
		ra(a);
	else if (a->next->position < a->next->next->position
		&& last->position < a->next->position)
		comb_ra(a);
	else if (a->next->position > a->next->next->position
		&& last->position > a->next->position)
		sa(a);
	else if (a->next->position < last->position
		&& a->next->next->position > last->position)
		comb_sa_ra(a);
	else if (a->next->position > a->next->next->position
		&& a->next->next->position > last->position)
		comb_ra_sa(a);
}
