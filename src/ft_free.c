/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 21:02:29 by mrollo            #+#    #+#             */
/*   Updated: 2022/08/03 16:58:43 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_free(t_stack *master, t_list *a, t_list *b)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = a->next;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free (tmp2);
	}
	free (master->stack);
	free (master->stack_copy);
	free (master);
	free (a);
	free (b);
}
