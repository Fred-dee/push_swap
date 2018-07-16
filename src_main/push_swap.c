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
	t_list *tmp;
	while (a->size > 1)
	{
		tmp = stack_min(a);
		while (*((int *)ft_stacktop(a)->content) !=  *((int *)tmp->content))
		{
			rotate_a(a);
			ft_putendl("ra");
		}
		push_b(a, b);
		ft_putendl("pb");
	}
	while(ft_stackempty(b) == FALSE)
	{
		push_a(a, b);
		ft_putendl("pa");
	}
}

void	work(int count, char **av)
{
	t_stack *a;
	t_stack *b;
	int		*x;

	if(is_valid(count, av) == FALSE)
	{
		ft_putendl_fd("Error", 2);
	}
	else
	{
		b = ft_stacknew(NULL, 0);
		a = ft_stacknew(NULL, 0);
		x = (int *)malloc(sizeof(int));
		while (count >= 0)
		{
			*x = ft_atoi(av[count--]);
			ft_stackpush(a, ft_lstnew(x, sizeof(x)));
		}
		free(x);
		push_swap(a, b);
	}
}

int		main(int ac, char **av)
{
	int		count;
	char	**split;

	if (ac > 1)
	{
		if(ac == 2)
		{
			count = 0;
			split = ft_strsplit(av[1], ' ');
			while (split[count] != '\0')
				count++;
			work(count - 1, split);
		}
		else
		{
			split = av + 1;
			work(ac - 2, split);
		}

	}
	return (0);
}

