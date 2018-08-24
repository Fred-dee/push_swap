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

char	*algo3(t_stack *a, t_stack *b, int init_half)
{
	char	*ret;
	char	*tmp;
	int		half;
	int		flag;
	t_list	*min;
	t_list 	*min_next;

	ret = ft_strnew(1);
	half = (int) a->size / 2;
	if (a->size > 3)
	{
		while ((int )a->size > half)
		{
			min = stack_min(a);
			min_next = stack_minnext(a, min);
			flag = 0;
			if (ft_stack_indexof(a, min) > (int) a->size / 2)
			{
				if (ft_stack_indexof(a, min_next) >= (int) a->size / 2 && 
					ft_stack_indexof(a, min_next) > ft_stack_indexof(a, min))
				{
					flag = 1;
					while(*((int *)ft_stacktop(a)->content) != *((int *)min_next->content))
					{
						revrotate_a(a);
						swapnfree(&ret, ft_strjoin(ret, "rra\n"));
					}
					push_b(a, b);
					swapnfree(&ret, ft_strjoin(ret, "pb\n"));
				} 
				while(*((int *)ft_stacktop(a)->content) != *((int *)min->content))
				{
					revrotate_a(a);
					swapnfree(&ret, ft_strjoin(ret, "rra\n"));
				}
				if (flag == 1)
				{
					swap_b(b);
					swapnfree(&ret, ft_strjoin(ret, "sb\n"));
				} 
			}
			else
			{
				if (ft_stack_indexof(a, min_next) <= (int) a->size / 2 && 
					ft_stack_indexof(a, min_next) < ft_stack_indexof(a, min))
				{
					flag = 1;
					while(*((int *)ft_stacktop(a)->content) != *((int *)min_next->content))
					{
						rotate_a(a);
						swapnfree(&ret, ft_strjoin(ret, "ra\n"));
					}
					push_b(a, b);
					swapnfree(&ret, ft_strjoin(ret, "pb\n"));
				} 
				while(*((int *)ft_stacktop(a)->content) != *((int *)min->content))
				{
					rotate_a(a);
					swapnfree(&ret, ft_strjoin(ret, "ra\n"));
				}
				if (flag == 1)
				{
					swap_b(b);
					swapnfree(&ret, ft_strjoin(ret, "sb\n"));
				}
			}
			push_b(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pb\n"));
		}
	}
	else
	{
		if (a->size == 2)
		{
			if (is_sorted(a->head) == FALSE)
			{
				swap_a(a);
				return("sa\n");
			}
		}
		else
			 test_2_sizeof3(&ret, a);
	}
	tmp = algo2(a, b, init_half);
	swapnfree(&ret, ft_strjoin(ret, tmp));
	free(tmp);
	return (ret);
}