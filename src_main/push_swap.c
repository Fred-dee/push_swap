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
	char	*ret;

	if(a->size < 100)
	{
		ret = algo3(a, b, a->size);
	}
	else
		ret = algo5(a, b);
	ft_putstr(ret);
	//print_stacks(a, b, "rr");
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
