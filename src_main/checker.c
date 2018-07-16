/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:02:18 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/13 09:02:21 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	read_apply(t_stack *a, t_stack *b)
{
	char	*str;
	int		read_ret;

	while((read_ret = get_next_line(0, &str)) > 0)
	{
		if(ft_strcmp(str, "sa") == 0)
			swap_a(a);
		else if (ft_strcmp(str, "sb") == 0)
			swap_b(b);
		else if (ft_strcmp(str, "ss") == 0)
			swap_s(a, b);
		else if (ft_strcmp(str, "pa") == 0)
			push_a(a, b);
		else if (ft_strcmp(str, "pb") == 0)
			push_b(a, b);
		else if (ft_strcmp(str, "ra") == 0)
			rotate_a(a);
		else if (ft_strcmp(str, "rb") == 0)
			rotate_b(b);
		else if (ft_strcmp(str, "rr") == 0)
			rotate_r(a, b);
		else if (ft_strcmp(str, "rra") == 0)
			revrotate_a(a);
		else if (ft_strcmp(str, "rrb") == 0)
			revrotate_b(b);
		else if (ft_strcmp(str, "rrr") == 0)
			revrotate_r(a, b);
		else if (ft_strcmp(str, "quit") == 0)
			break;
		free(str);
		//print_stacks(a, b);
	}
}

void	work(int count, char **av, t_stack *a)
{
	int		*x;

	if(is_valid(count, av) == FALSE)
	{
		ft_putendl_fd("Error", 2);
	}
	else
	{
		x = (int *)malloc(sizeof(int));
		while (count >= 0)
		{
			*x = ft_atoi(av[count--]);
			ft_stackpush(a, ft_lstnew(x, sizeof(x)));
		}
		free(x);
	}
}

int		main(int ac, char **av)
{
	int		count;
	char	**split;
	t_stack *a;
	t_stack *b;

	if (ac > 1)
	{
		b = ft_stacknew(NULL, 0);
		a = ft_stacknew(NULL, 0);
		if(ac == 2)
		{
			count = 0;
			split = ft_strsplit(av[1], ' ');
			while (split[count] != '\0')
				count++;
			work(count - 1, split, a);
		}
		else
		{
			split = av + 1;
			work(ac - 2, split, a);
		}
		read_apply(a, b);
		if(is_sorted(a->head) && ft_stackempty(b) == TRUE)
			ft_putendl("OK");
		else ft_putendl("KO");
	}
	return (0);
}
