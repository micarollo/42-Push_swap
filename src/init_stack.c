/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:04:29 by mrollo            #+#    #+#             */
/*   Updated: 2022/08/03 17:40:53 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_clean_atoi(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\t')
		i++;
	return (i);
}

static long int	ft_atoi(const char *nptr)
{
	long int	i;
	long int	n;
	long int	result;

	n = 1;
	result = 0;
	i = ft_clean_atoi(nptr);
	if (nptr[i] == '-')
	{
		n = n * -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - 48);
		i++;
	}
	return (result * n);
}

void	init_a(t_stack *master, t_list *a)
{
	int		i;
	int		j;
	t_list	*new;

	i = 0;
	while (i < master->len)
	{
		j = 0;
		while (j < master->len)
		{
			if (master->stack[i] == master->order_stack[j])
			{
				new = ft_lstnew(master->stack[i]);
				new->position = j;
				ft_lstadd_back(a, new);
			}
			j++;
		}
		i++;
	}
}

int	order_array(t_stack *master)
{
	int	i;

	i = 0;
	master->stack_copy = (int *)malloc((master->len + 1) * sizeof(int));
	if (!master->stack_copy)
		return (1);
	while (i < master->len)
	{
		master->stack_copy[i] = master->stack[i];
		i++;
	}
	master->order_stack = ft_sort_int_tab(master->stack_copy, master->len);
	return (0);
}

int	init_array(t_stack *master, int argc, char *argv[])
{
	int			i;
	int			j;
	long int	num;

	master->len = argc - 1;
	master->stack = (int *)malloc(argc * sizeof(int));
	if (!master->stack)
		return (1);
	i = 0;
	j = 1;
	while (i < master->len)
	{
		num = ft_atoi(argv[j]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		master->stack[i] = num;
		i++;
		j++;
	}
	check_doubles(master->stack, master->len);
	return (0);
}
