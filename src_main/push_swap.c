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
	t_list *tail;
	t_list *second;
	t_list *tsecond;

	while (a->size > 2 && is_sorted(a->head) == FALSE)
	{
		tmp = stack_min(a);
		while (*((int *)ft_stacktop(a)->content) !=  *((int *)tmp->content))
		{
			tail = ft_lstgettail(a->head);
			second = ft_stacktop(a)->next;
			tsecond = ft_lstat(a->head, a->size - 2);
			if(*((int *)tail->content) == *((int *)tmp->content))
			{
				revrotate_a(a);
				ft_putendl("rra");
			}
			else if(*((int *)second->content) ==  *((int *)tmp->content))
			{
				swap_a(a);
				ft_putendl("sa");
			}
			else if(tsecond != NULL && *((int *)tsecond->content) == *((int *)tmp->content))
			{
				revrotate_a(a);
				ft_putendl("rra");
			}
			else
			{
				rotate_a(a);
				ft_putendl("ra");
			}
		}
		if(is_sorted(a->head) == FALSE)
		{
			push_b(a, b);
			ft_putendl("pb");
		}
	}
	if (is_sorted(a->head) == FALSE && a->size == 2)
	{
		rotate_a(a);
		ft_putendl("ra");
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

