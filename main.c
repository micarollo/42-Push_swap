/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:15:19 by mrollo            #+#    #+#             */
/*   Updated: 2022/06/01 20:31:27 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
		printf("argc = %d\n", argc);
		j = 0;
		k = 1;
		len_stack = argc - 1;
		//stack = (char **)malloc(sizeof(char *));
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
					printf("content: %d\n", new->content);
				}
				y++;
			}
			i++;
		}
		//printf("a->next: %d\n", a->next->content);
		//IMPRIMIENDO LA LISTA
		/*
		temp = a->next;
		while (temp != NULL)
		{
			printf("POSITION DESDE LIST: (%d)\n", temp->position);
			printf("CONTENT DESDE LIST: (%d)\n", temp->content);
			temp = temp->next;
			}*/
		//printf("A: %d\n", a->next->position);
		//BUSCAR UNA POSICION EN LA LISTA
		/*temp = a->next;
		while (temp != NULL)
		{
			if (temp->position == 0)
			{
				printf("BUSCANDO POS 0: %d\n", temp->content);
				break;
			}
			else
				temp = temp->next;
				}*/
		//RA
		//temp = a->next;
		//printf("RA: %d\n", temp->content);
		temp = ft_lstlast(a);
		printf("ultimo: %d\n", temp->content);
		
		temp = a->next;
                while (temp != NULL)
                {
                        printf("A position: (%d)\n", temp->position);
                        printf("A content: %d\n", temp->content);
                        temp = temp->next;
                }
		temp = b->next;
                while (temp != NULL)
                {
                        printf("B position: (%d)\n", temp->position);
                        printf("B content: %d\n", temp->content);
                        temp = temp->next;
		}
	}
}
