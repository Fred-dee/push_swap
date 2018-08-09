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
	int		count;

	ret = ft_strnew(1);
	count = 0;
	while ((int )b->size > 0 && is_sorted_desc(b->head) == FALSE)
	{
		max = stack_max(b);
		if (*((int *)ft_stacktop(b)->content) == *((int *)max->content))
<<<<<<< HEAD
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
		else
		{
=======
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
		else
		{
>>>>>>> a4140dd61480a574da8e5b08386262d9ba95b984
			if (ft_stack_indexof(b, max) > (int) b->size / 2)
			{
				while(*((int *)ft_stacktop(b)->content) != *((int *)max->content))
				{
					revrotate_b(b);
					swapnfree(&ret, ft_strjoin(ret, "rrb\n"));
				}
			}
			else
			{
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
			}
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
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
<<<<<<< HEAD
}
=======
}
>>>>>>> a4140dd61480a574da8e5b08386262d9ba95b984
