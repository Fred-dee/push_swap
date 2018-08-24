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

char	*algo5_help(t_stack *a, t_stack *b)
{
	char	*ret;
	t_list	*max;
	t_list	*max_next;
	int		flag;

	ret = ft_strnew(1);
	while ((int )b->size > 0 && is_sorted_desc(b->head) == FALSE)
	{
		max = stack_max(b);
		max_next = stack_maxnext(b, max);
		flag = 0;
		if (*((int *)ft_stacktop(b)->content) == *((int *)max->content))
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
		else
		{
			if (ft_stack_indexof(b, max) > (int) b->size / 2)
			{
				if (max_next != NULL)
					if (ft_stack_indexof(b, max_next) > (int) a->size / 2 && 
						ft_stack_indexof(b, max_next) > ft_stack_indexof(b, max))
					{
						flag = 1;
						while(*((int *)ft_stacktop(b)->content) != *((int *)max_next->content))
						{
							revrotate_b(b);
							swapnfree(&ret, ft_strjoin(ret, "rrb\n"));
						}
						push_a(a, b);
						swapnfree(&ret, ft_strjoin(ret, "pa\n"));
				} 
				while(*((int *)ft_stacktop(b)->content) != *((int *)max->content))
				{
					revrotate_b(b);
					swapnfree(&ret, ft_strjoin(ret, "rrb\n"));
				}
				if (flag == 1)
				{
					push_a(a, b);
					swapnfree(&ret, ft_strjoin(ret, "pa\n"));
					swap_a(a);
					swapnfree(&ret, ft_strjoin(ret, "sa\n"));
				}
			}
			else
			{
				if (max_next != NULL)
					if (ft_stack_indexof(b, max_next) <= (int) a->size / 2 && 
						ft_stack_indexof(b, max_next) < ft_stack_indexof(b, max))
					{
						flag = 1;
						while(*((int *)ft_stacktop(b)->content) != *((int *)max_next->content))
						{
							rotate_b(b);
							swapnfree(&ret, ft_strjoin(ret, "rb\n"));
						}
						push_a(a, b);
						swapnfree(&ret, ft_strjoin(ret, "pa\n"));
					} 
				while(*((int *)ft_stacktop(b)->content) != *((int *)max->content))
				{
					if(b->size >= 2 && *((int *)ft_stacktop(b)->next->content) == *((int *)max->content))
					{
						swap_b(b);
						swapnfree(&ret, ft_strjoin(ret, "sb\n"));
					}
					else
					{
						rotate_b(b);
						swapnfree(&ret, ft_strjoin(ret, "rb\n"));		
					}
				}
				if (flag == 1)
				{
					push_a(a, b);
					swapnfree(&ret, ft_strjoin(ret, "pa\n"));
					swap_a(a);
					swapnfree(&ret, ft_strjoin(ret, "sa\n"));
				}

			}
			if (flag == 0)
			{
				push_a(a, b);
				swapnfree(&ret, ft_strjoin(ret, "pa\n"));
			}
		}
	}
	if(is_sorted_desc(b->head) == TRUE)
	{
		while(b->size != 0)
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
	}
	return (ret);
}
