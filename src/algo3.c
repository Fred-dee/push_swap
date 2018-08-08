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
	min = stack_min(a);
	while ((int )a->size > half)
	{
		if (ft_stack_indexof(a, min) > (int) a->size / 2)
		{
			while(ft_memcmp(ft_stacktop(a)->content, min->content, min->content_size) != 0)
			{
				revrotate_a(a);
				swapnfree(&ret, ft_strjoin(ret, "rra"));
			}

		}
		else
		{
			while(ft_memcmp(ft_stacktop(a)->content, min->content, min->content_size) != 0)
			{
				rotate_a(a);
				swapnfree(&ret, ft_strjoin(ret, "ra"));
			}
		}
		push_b(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pb"));
	}
	swapnfree(&ret, ft_strjoin(ret, algo2(a, b)));
	return (ret);
}