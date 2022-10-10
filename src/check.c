/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrollo <mrollo@student.42barcelon...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:35:29 by mrollo            #+#    #+#             */
/*   Updated: 2022/08/04 18:34:55 by mrollo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n])
	{
		n++;
	}
	return (n);
}

void	control_1(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = ft_strlen(argv[i]);
		if (j == 0)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		is_numeric(argv[i]);
		i++;
	}
}

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
	if (argv[0] == '+' || argv[0] == '-')
		i++;
	while (argv[i])
	{
		if (argv[i] < 48 || argv[i] > 57)
		{
			write(2, "Error\n", 6);
			exit (1);
		}
		i++;
	}
}
