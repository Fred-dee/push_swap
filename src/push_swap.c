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
	/*
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec sa:");
	swap_a(a);
	print_stacks(a, b);
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec pb pb pb:");
	push_b(a, b);
	push_b(a, b);
	push_b(a, b);
	swap_a(a);
	rotate_a(a);
	print_stacks(a, b);
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec ra rb (equivalent to rr):");
	rotate_r(a, b);
	print_stacks(a, b);
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec rra rrb (equivalent to rrr):");
	revrotate_r(a, b);
	print_stacks(a, b);
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec sa:");
	swap_a(a);
	print_stacks(a, b);
	ft_putendl("---------------------------------------------------------------");
	ft_putendl("Exec pa pa pa:");
	push_a(a, b);
	push_a(a, b);
	push_a(a, b);
	print_stacks(a, b); */
	/* input of 3 2 1 0 */
	(void) a;
	(void) b;
	ft_putendl("rra");
	ft_putendl("pb");
	ft_putendl("sa");
	ft_putendl("rra");
	ft_putendl("pa");

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
			ft_putendl_fd("Error", 2);
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
		//	print_stacks(a, b);
			push_swap(a, b);
		}
	}
	return (0);
}

