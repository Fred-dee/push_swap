/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:30:54 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/12 13:31:17 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	push_swap(t_stack *a, t_stack *b)
{
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec sa:");
	swap_a(a);
	print_stacks(a, b);
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec pb pb pb:");
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
	print_stacks(a, b);
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec ra rb (equivalent to rr):");
	rotate_r(a, b);
	print_stacks(a, b);

}

int		is_valid(int ac, char *av[])
{
	int		tmp;
	char	*str;
	int		arr[ac - 1];
	int		i;

	tmp = ac - 1;
	while (tmp > 0)
	{
		str = av[tmp];
		while(*str != '\0')
		{
			if(ft_isdigit(*str) == FALSE)
				return (FALSE);
			str++;
		}
		arr[tmp - 1] = ft_atoi(av[tmp]);
		tmp--; 
	}
	tmp = 0;
	while (tmp < ac - 2)
	{
		i = tmp + 1;
		while (i < ac - 1)
			if(arr[tmp] == arr[i++])
				return (FALSE);
		tmp++;
	}
	return (TRUE);
}

int		main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;
	int		count;
	int		*x;

	if (ac > 1)
	{
		if(is_valid(ac, av) == FALSE)
		{
			ft_putendl("Error");
		}
		else
		{
			b = ft_stacknew(NULL, 0);
			a = ft_stacknew(NULL, 0);
			count = ac - 1;
			x = (int *)malloc(sizeof(int));
			while (count > 0)
			{
				*x = ft_atoi(av[count--]);
				ft_stackpush(a, ft_lstnew(x, sizeof(x)));
			}
			free(x);
			print_stacks(a, b);
			push_swap(a, b);
		}
	}
	return (0);
}
