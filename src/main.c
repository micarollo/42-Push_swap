/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 19:53:10 by mrollo            #+#    #+#             */
/*   Updated: 2022/08/03 18:24:57 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sorting_a(t_list *a, t_list *b, t_stack *master)
{
	if (master->len == 2)
	{
		if (a->next->position > a->next->next->position)
			sa(a);
	}
	else if (master->len == 3)
		quick_sort(a);
	else if (master->len == 4)
		quick_sort_4(a, b);
	else if (master->len == 5)
		quick_sort_5(a, b);
	else
		sort(a, b, master->len);
}

int	main(int argc, char *argv[])
{
	t_stack	*master;
	t_list	*a;
	t_list	*b;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
	{
		control_1(argc, argv);
		master = (t_stack *)malloc(sizeof(t_stack));
		if (!master)
			return (1);
		init_array(master, argc, argv);
		order_array(master);
		a = (t_list *)malloc(sizeof(t_list));
		b = (t_list *)malloc(sizeof(t_list));
		if (!a || !b)
			return (1);
		init_a(master, a);
		sorting_a(a, b, master);
		ft_free(master, a, b);
	}
}
