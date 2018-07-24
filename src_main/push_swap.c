/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 10:45:05 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/23 10:45:07 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_swap(t_stack *a, t_stack *b)
{
	char	*ret[2];
	int		i;
	int		choice;
	int		min;

	i = 1;
	choice = 0;
	ret[0] = algo1(ft_stackdup(a), ft_stackdup(b));
	ret[1] = algo2(ft_stackdup(a), ft_stackdup(b));
	min = char_count(ret[0], '\n');
	while (i < 2)
	{
		if (char_count(ret[i], '\n') < min)
		{
			choice = i;
			min = char_count(ret[i], '\n');
		}
		i++;
	}
	ft_putstr(ret[choice]);
}

static void	work(int count, char **av)
{
	t_stack *a;
	t_stack *b;
	int		*x;

	if (is_valid(count, av) == FALSE)
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

int			main(int ac, char **av)
{
	int		count;
	char	**split;

	if (ac > 1)
	{
		if (ac == 2)
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
