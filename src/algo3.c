/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:22:32 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/24 13:22:48 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

char	*algo3(t_stack *a, t_stack *b)
{
	char	*ret;
	int		half;
	t_list	*min;

	ret = ft_strnew(1);
	half = (int) a->size / 2;

	while ((int )a->size > half)
	{
		min = stack_min(a);
		if (ft_stack_indexof(a, min) > (int) a->size / 2)
		{
			while(*((int *)ft_stacktop(a)->content) != *((int *)min->content))
			{
				revrotate_a(a);
				swapnfree(&ret, ft_strjoin(ret, "rra\n"));
			}
		}
		else
		{
			while(*((int *)ft_stacktop(a)->content) != *((int *)min->content))
			{
				rotate_a(a);
				swapnfree(&ret, ft_strjoin(ret, "ra\n"));
			}
		}
		push_b(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pb\n"));
	}
	swapnfree(&ret, ft_strjoin(ret, algo2(a, b)));
	return (ret);
}