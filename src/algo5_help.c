/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:57:38 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/09 10:57:40 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int		get_position(t_stack *b)
{
	int		converted[b->size][2];
	stack_to_int(b, converted);
	rank_arr_desc(converted, b->size);

	return (get_rank(converted, b->size, *((int *)ft_stacktop(b)->content)));
}

char	*algo5_help(t_stack *a, t_stack *b)
{
	(void) a;
	(void) b;
	return ("");
	/*char	*ret;
	int		half;
	int		flag;
	t_list	*max;
	t_list 	*max_next;

	ret = ft_strnew(1);
	half = (int) b->size / 2;
	(void)(init_half);
	while (is_sorted(b->head) == FALSE && b->size > 3)
	{
		max = stack_max(b);
		max_next = stack_maxnext(b, max);
		flag = 0;
		if (ft_stack_indexof(a, max) > (int) a->size / 2)
		{	if (max_next != NULL)
				if (ft_stack_indexof(a, max_next) >= (int) a->size / 2 && 
					ft_stack_indexof(a, max_next) > ft_stack_indexof(a, max))
				{
					flag = 1;
					while(*((int *)ft_stacktop(a)->content) != *((int *)max_next->content))
					{
						revrotate_a(a);
						swapnfree(&ret, ft_strjoin(ret, "rra\n"));
					}
					push_b(a, b);
					swapnfree(&ret, ft_strjoin(ret, "pb\n"));
				} 
			while(*((int *)ft_stacktop(a)->content) != *((int *)max->content))
			{
				revrotate_a(a);
				swapnfree(&ret, ft_strjoin(ret, "rra\n"));
			}
		}
		else
		{
			if(max_next != NULL)
				if (ft_stack_indexof(a, max_next) < (int) a->size / 2 && 
					ft_stack_indexof(a, max_next) < ft_stack_indexof(a, max))
				{
					flag = 1;
					while(*((int *)ft_stacktop(a)->content) != *((int *)max_next->content))
					{
						rotate_a(a);
						swapnfree(&ret, ft_strjoin(ret, "ra\n"));
					}
					push_b(a, b);
					swapnfree(&ret, ft_strjoin(ret, "pb\n"));
				} 
			while(*((int *)ft_stacktop(a)->content) != *((int *)max->content))
			{
				if(a->size >= 2 && *((int *)ft_stacktop(a)->next->content) == *((int *)max->content))
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
	} */
}
