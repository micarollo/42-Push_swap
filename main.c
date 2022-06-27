/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:15:19 by mrollo            #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int is_sorted(t_list *a)
{
	t_list *temp;

	temp = a->next;
	while (temp->next != NULL)
	{
		printf("temp->position: %d\n", temp->position);
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

void	sort(t_list *a, t_list *b, int len_stack)
{
	(void)b;
	int	bit;
	int i;
	int j;
	int n;
	int temp;

	bit = count_bit(len_stack);
	printf("bits desde sort: %d\n", bit);
	i = 0;
	while (i < bit)
	{
		printf("hola");
		j = 0;
		while (j < len_stack)
		{
			n = a->next->position;
			n = n >> i;
			temp = n & 1;
			if (temp)
			{
				//printf("%d", temp);
				ra(a);
			}
			else
			{
				printf("0");
				//pb(a, b);
			}
			j++;
		}
		printf("chau");
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	len_stack;
	//char **stack;
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
	//int x;
	int y;
	t_list *temp;

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
		stack_i_copy = (int *)malloc(argc * sizeof(int));
		//COPIA DE STACK_I
		i = 0;
		while (stack_i[i])
		{
			stack_i_copy[i] = stack_i[i];
			i++;
		}
		tab = (int *)malloc(len_stack * sizeof(int));
		tab = ft_sort_int_tab(stack_i_copy, len_stack);
		//INI STACK
		a = (t_list *)malloc(sizeof(t_list));
		b = (t_list *)malloc(sizeof(t_list));
		i = 0;
		while (stack_i[i])
		{
			y = 0;
			while (tab[y])
			{
				if (stack_i[i] == tab[y])
				{
					new = ft_lstnew(stack_i[i]);
					new->position = y;
					ft_lstadd_back(a, new);
					//printf("content: %d\n", new->content);
				}
				y++;
			}
			i++;
		}
		printf("len_stack: %d\n", len_stack);
		printf("is sorted: %d\n", is_sorted(a));
		//sort(a, b, len_stack);
		temp = a->next;
		while (temp != NULL)
		{
			printf("A position: (%d) ", temp->position);
			printf("content: %d\n", temp->content);
			temp = temp->next;
		}
		temp = b->next;
		while (temp != NULL)
		{
			printf("B position: (%d) ", temp->position);
			printf("content: %d\n", temp->content);
			temp = temp->next;
		}
	}
}
