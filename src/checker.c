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
		if(ft_strstr(str, "sa") != NULL)
			swap_a(a);
		else if (ft_strstr(str, "sb") != NULL)
			swap_b(b);
		else if (ft_strstr(str, "ss") != NULL)
			swap_s(a, b);
		else if (ft_strstr(str, "pa") != NULL)
			push_a(a, b);
		else if (ft_strstr(str, "pb") != NULL)
			push_b(a, b);
		else if (ft_strstr(str, "ra") != NULL)
			ft_stackrevrotate(a);
		else if (ft_strstr(str, "rb") != NULL)
			rotate_b(b);
		else if (ft_strstr(str, "rr") != NULL)
			rotate_r(a, b);
		else if (ft_strstr(str, "rra") != NULL)
			revrotate_a(a);
		else if (ft_strstr(str, "rrb") != NULL)
			revrotate_b(b);
		else if (ft_strstr(str, "rrr") != NULL)
			revrotate_r(a, b);
		else if (ft_strstr(str, "quit"))
			break;
		free(str);
	}
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
			read_apply(a, b);
			if(is_sorted(a->head) && ft_stackempty(b) == TRUE)
				ft_putendl("OK");
			else ft_putendl("KO");
		}
	}
	return (0);
}
