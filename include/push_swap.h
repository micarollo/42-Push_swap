/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:57:05 by mrollo            #+#    #+#             */
/*   Updated: 2022/09/27 15:56:10 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

typedef struct s_stack
{
	int	len;
	int	*stack;
	int	*stack_copy;
	int	*order_stack;
}			t_stack;

typedef struct s_list
{
	int				content;
	int				position;
	char			*binario;
	struct s_list	*next;
}			t_list;

t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list *lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_swap(int *a, int *b);
int		*ft_sort_int_tab(int *tab, int size);
void	pb(t_list *a, t_list *b);
void	pa(t_list *a, t_list *b);
void	ra(t_list *a);
void	check_doubles(int *stack, int len);
void	sa(t_list *a);
void	sb(t_list *b);
void	print_lst(t_list *a, t_list *b);
void	rra(t_list *a);
void	clean_b(t_list *a, t_list *b);
int		is_sorted(t_list *a);
int		count_bit(int n);
void	quick_sort(t_list *a);
void	sort_n1(t_list *a, t_list *b);
void	sort_n2(t_list *a, t_list *b);
void	quick_sort_5(t_list *a, t_list *b);
void	quick_sort_4(t_list *a, t_list *b);
void	sort(t_list *a, t_list *b, int len_stack);
void	control_1(int argc, char *argv[]);
void	is_numeric(char *argv);
int		init_array(t_stack *master, int argc, char *argv[]);
int		order_array(t_stack *master);
void	init_a(t_stack *master, t_list *a);
void	ft_free(t_stack *master, t_list *a, t_list *b);

#endif
