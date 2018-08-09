/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5_help2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:58:14 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/09 10:58:15 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*algo5_help2(t_stack *a, t_stack *b)
{
	char	*ret;
	t_list	*max;

	ret = ft_strnew(1);
	while(is_sorted_desc(b->head) == FALSE && b->size > 2)
	{
		max = stack_max(b);
		if(*((int *)b->head->content) != *((int *)max->content))
		{
			if(b->size >= 2 && *((int *)b->head->content) < *((int *)b->head->next->content))
			{
				swap_b(b);
				swapnfree(&ret, ft_strjoin(ret, "sb\n"));
				rotate_b(b);
				swapnfree(&ret, ft_strjoin(ret, "rb\n"));
			}
			else
			{
				rotate_b(b);
				swapnfree(&ret, ft_strjoin(ret, "rb\n"));			
			}
		}
		else
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
	}
	return (ret);
}
