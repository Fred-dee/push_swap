/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:04:26 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/16 15:04:39 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	test_1(char **ret, t_list *tmp, t_stack *a)
{
	t_list *second;
	t_list *tsecond;

	second = ft_stacktop(a)->next;
	tsecond = ft_lstat(a->head, a->size - 2);
	if(*((int *)ft_lstgettail(a->head)->content) == *((int *)tmp->content))
	{
		revrotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "rra\n"));
	}
	else if(*((int *)second->content) ==  *((int *)tmp->content))
	{
		swap_a(a);
		swapnfree(ret, ft_strjoin(*ret, "sa\n"));
	}
	else if(tsecond != NULL && *((int *)tsecond->content) == *((int *)tmp->content))
	{
		revrotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "rra\n"));
	}
	else
	{
		rotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "ra\n"));
	}
}

static void	test_2(char **ret, t_stack *a, t_stack *b)
{
	if (is_sorted(a->head) == FALSE && a->size == 2)
	{
		rotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "ra\n"));
	}
	while(ft_stackempty(b) == FALSE)
	{
		push_a(a, b);
		swapnfree(ret, ft_strjoin(*ret, "pa\n"));
	}
}

char		*algo1(t_stack *a, t_stack *b)
{
	t_list *tmp;
	char	*ret;

	ret = ft_strnew(1);
	while (a->size > 2 && is_sorted(a->head) == FALSE)
	{
		tmp = stack_min(a);
		while (*((int *)ft_stacktop(a)->content) !=  *((int *)tmp->content))
		{
			test_1(&ret, tmp, a);
		}
		if(is_sorted(a->head) == FALSE)
		{
			push_b(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pb\n"));
		}
	}
	test_2(&ret, a, b);
	return (ret);
}
