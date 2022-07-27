/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:08:21 by mrollo            #+#    #+#             */
/*   Updated: 2022/07/27 17:48:09 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

/*void	clean_b(t_list *a, t_list *b)
{
	t_list *temp;
	int i;
	int count;

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

int is_sorted(t_list *a)
{
	t_list *temp;

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
	int i;
	int temp;

	i = 0;
	while (n)
	{
		temp = n & 1;
		i++;
		n = n >> 1;
	}
	return (i);
}

void	quick_sort(t_list *a, int len_stack)
{
	t_list *last;

	last = ft_lstlast(a); 
	if (len_stack == 2)
	{
		if (a->next->position > a->next->next->position)
			sa(a);
	}
	else if (len_stack == 3)
	{
		if (a->next->position > a->next->next->position && a->next->position > last->position && last->position > a->next->next->position)
			ra(a);
		else if (a->next->position < a->next->next->position && last->position < a->next->position)
		{
			ra(a);
			ra(a);
		}
		else if (a->next->position > a->next->next->position && last->position > a->next->position)
			sa(a);
		else if (a->next->position < last->position && a->next->next->position > last->position)
		{
			sa(a);
			ra(a);
		}
		else if (a->next->position > a->next->next->position && a->next->next->position > last->position)
		{
			ra(a);
			sa(a);
		}
	}
}

void	sort_n1(t_list *a, t_list *b)
{
	t_list *last;
	t_list *first;

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
		if (b->next->position > a->next->position && b->next->position < a->next->next->position)
		{
			pa(a, b);
			sa(a);
		}
		else
		{
			rra(a);
			pa(a, b);
			ra(a);
			ra(a);
		}
    }
		
}

void    sort_n2(t_list *a, t_list *b)
{
	t_list *last;
    t_list *first;

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
	{
        rra(a);
        pa(a, b);
        ra(a);
        ra(a);
	}
	else
	{
		if (b->next->position > a->next->position && b->next->position < a->next->next->position)
        {
            pa(a, b);
            sa(a);
        }
		else
		{
			ra(a);
			pa(a, b);
			sa(a);
			rra(a);
		}
	}
		
}

void	quick_sort_5(t_list *a, t_list *b)
{
	pb(a, b);
	pb(a, b);
	quick_sort(a, 3);
	sort_n1(a, b);
	sort_n2(a, b);
}

void	quick_sort_4(t_list *a, t_list *b)
{
	pb(a, b);
    pb(a, b);
	printf("aqui\n");
    quick_sort(a, 3);
	printf("sort\n");
	sort_n1(a, b);
}

void	sort(t_list *a, t_list *b, int len_stack)
{
	int	bit;
	int i;
	int j;
	int n;
	int temp;

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
*/
int	main(int argc, char *argv[])
{
	int	len_stack;
	int *stack_i;
	int *stack_i_copy;
	int j;
	int k;
	int num;
	int i;
	int *tab;
	t_list *a;
	t_list *b;
	t_list *new;
	int y;
//	t_list *temp;

	if (argc < 2)
	{
		printf("Error\n");
		return (0);
	}
	else
	{
		j = 0;
		k = 1;
		len_stack = argc - 1;
		stack_i = (int *)malloc(argc * sizeof(int));
		//CREANDO EL ARRAY DE LOS ARGUMENTOS
		while (j < len_stack)
		{
			num = atoi(argv[k]);
			stack_i[j] = num;
			j++;
			k++;
		}
		check_doubles(stack_i, len_stack);
		stack_i_copy = (int *)malloc(argc * sizeof(int));
		//COPIA DE STACK_I
		i = 0;
		while (i < len_stack)
		{
			stack_i_copy[i] = stack_i[i];
			i++;
		}
		tab = (int *)malloc(len_stack * sizeof(int));
		tab = ft_sort_int_tab(stack_i_copy, len_stack);
		//free (stack_i_copy);
		//INI STACK
		a = (t_list *)malloc(sizeof(t_list));
		b = (t_list *)malloc(sizeof(t_list));
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
		print_lst(a, b);
	}
}
