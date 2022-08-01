/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:08:21 by mrollo            #+#    #+#             */
/*   Updated: 2022/08/01 17:35:57 by mrollo           ###   ########.fr       */
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

long int	ft_atoi(const char *nptr)
{
	long int				i;
	long int				n;
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

int	main(int argc, char *argv[])
{
	int			len_stack;
	int 		*stack_i;
	int			*stack_i_copy;
	int 		j;
	int 		k;
	long int	num;
	int			i;
	int			*tab;
	t_list		*a;
	t_list		*b;
	t_list		*new;
	int			y;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			k = strlen(argv[i]);
			if (k == 0)
			{
				write(2, "Error\n", 6);
				exit (1);
			}
			is_numeric(argv[i]);
			i++;
		}
		j = 0;
		k = 1;
		len_stack = argc - 1;
		stack_i = (int *)malloc(argc * sizeof(int));
		if (stack_i == NULL)
			return NULL;
		//CREANDO EL ARRAY DE LOS ARGUMENTOS
		while (j < len_stack)
		{
			num = ft_atoi(argv[k]);
			if (num > INT_MAX || num < INT_MIN)
			{
				write(2, "Error\n", 6);
				exit (1);
			}
			stack_i[j] = (int)num;
			j++;
			k++;
		}
		check_doubles(stack_i, len_stack);
		stack_i_copy = (int *)malloc(argc * sizeof(int));
		if (stack_i_copy == NULL)
			return NULL;
		//COPIA DE STACK_I
		i = 0;
		while (i < len_stack)
		{
			stack_i_copy[i] = stack_i[i];
			i++;
		}
		tab = (int *)malloc(len_stack * sizeof(int));
		if (tab == NULL)
			return NULL;
		tab = ft_sort_int_tab(stack_i_copy, len_stack);
		//free (stack_i_copy);
		//INI STACK
		a = (t_list *)malloc(sizeof(t_list));
		b = (t_list *)malloc(sizeof(t_list));
		if (a == NULL || b == NULL)
			return NULL;
		i = 0;
		while (i < len_stack)
		{
			y = 0;
			while (y < len_stack)
			{
				if (stack_i[i] == tab[y])
				{
					new = ft_lstnew(stack_i[i]);
					new->position = y;
					ft_lstadd_back(a, new);
				}
				y++;
			}
			i++;
		}
		free (stack_i);
		free (tab);
		if (len_stack == 2)
		{
			if (a->next->position > a->next->next->position)
				sa(a);
		}
		else if (len_stack == 3)
			quick_sort(a);
		else if (len_stack == 4)
			quick_sort_4(a, b);
		else if (len_stack == 5)
			quick_sort_5(a, b);
		else
			sort(a, b, len_stack);
		//IMPRIMIR CONTENIDO LISTAS
		//print_lst(a, b);
	}
}
