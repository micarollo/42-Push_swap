/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:47:21 by mrollo            #+#    #+#             */
/*   Updated: 2022/07/27 17:57:02 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	clean_b(t_list *a, t_list *b)
{
	t_list	*temp;
	int		i;
	int		count;

	i = 0;
	temp = b->next;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	count = 0;
	while (count < i)
	{
		pa(a, b);
		count++;
	}
}

int	is_sorted(t_list *a)
{
	t_list	*temp;

	temp = a->next;
	while (temp->next != NULL)
	{
		if (temp->position > temp->next->position)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	count_bit(int n)
{
	int	i;
	int	temp;

	i = 0;
	while (n)
	{
		temp = n & 1;
		i++;
		n = n >> 1;
	}
	return (i);
}

void	sort(t_list *a, t_list *b, int len_stack)
{
	int	bit;
	int	i;
	int	j;
	int	n;
	int	temp;

	bit = count_bit(len_stack);
	i = 0;
	while (is_sorted(a) == 0 && i < bit)
	{
		j = 0;
		while (j < len_stack)
		{
			n = a->next->position;
			n = n >> i;
			temp = n & 1;
			if (temp)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		clean_b(a, b);
		i++;
	}
}
