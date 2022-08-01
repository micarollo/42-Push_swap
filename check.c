/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:35:29 by mrollo            #+#    #+#             */
/*   Updated: 2022/08/01 16:31:05 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_doubles(int *stack, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
			{
				write(2, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
}

void	is_numeric(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '+' || argv[i] == '-')
			i++;
		if (argv[i] < 48 || argv[i] > 57)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}
