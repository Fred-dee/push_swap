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
