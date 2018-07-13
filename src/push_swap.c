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
	(void) a;
	(void) b;
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
			push_swap(a, b);
		}
	}
	return (0);
}

