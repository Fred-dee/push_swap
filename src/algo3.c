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

#include <push_swap.h>

char	*algo3(t_stack *a, t_stack *b)
{
	char	*ret;
	int		flag;
	t_list	*min;
	t_list 	*min_next;

	ret = ft_strnew(1);
	while (is_sorted(a->head) == FALSE && a->size > 3)
	{
		min = stack_min(a);
		min_next = stack_minnext(a, min);
		flag = 0;
		if (ft_stack_indexof(a, min) > (int) a->size / 2)
		{	if (min_next != NULL)
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
		}
		else
		{
			if(min_next != NULL)
				if (ft_stack_indexof(a, min_next) < (int) a->size / 2 && 
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
				if(a->size >= 2 && *((int *)ft_stacktop(a)->next->content) == *((int *)min->content))
				{
					swap_a(a);
					swapnfree(&ret, ft_strjoin(ret, "sa\n"));
				}
				else
				{
					rotate_a(a);
					swapnfree(&ret, ft_strjoin(ret, "ra\n"));		
				}
			}
		}
		if (flag == 1)
		{
			push_b(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pb\n"));
			swap_b(b);
			swapnfree(&ret, ft_strjoin(ret, "sb\n"));
		} 
		if (flag == 0)
		{
			push_b(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pb\n"));
		}
	}
	if (a->size <= 3)
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
	while (b->size > 0)
	{
		push_a(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pa\n"));
	}
	return (ret);
}