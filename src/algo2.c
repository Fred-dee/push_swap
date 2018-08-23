/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 08:53:14 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/23 11:25:34 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	test_1(char **ret, t_list *tmp, t_stack *a)
{
	t_list *n2;
	t_list *t2;

	n2 = ft_stacktop(a)->next;
	t2 = ft_lstat(a->head, a->size - 2);
	if (*((int *)ft_lstgettail(a->head)->content) == *((int *)tmp->content))
	{
		revrotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "rra\n"));
	}
	else if (*((int *)n2->content) == *((int *)tmp->content))
	{
		swap_a(a);
		swapnfree(ret, ft_strjoin(*ret, "sa\n"));
	}
	else if (t2 != NULL && *((int *)t2->content) == *((int *)tmp->content))
	{
		revrotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "rra\n"));
	}
	else if (ft_stack_indexof(a, tmp) <= (int)a->size / 2)
	{
		rotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "ra\n"));
	}
	else
	{
		revrotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "rra\n"));		
	}
}

static void	help_1(t_stack *a, char **ret)
{
	revrotate_a(a);
	swapnfree(ret, ft_strjoin(*ret, "rra\n"));
	if (*(int *)a->head->content > *(int *)a->head->next->content)
	{
		swap_a(a);
		swapnfree(ret, ft_strjoin(*ret, "sa\n"));
	}
}

static void	help_2(t_stack *a, char **ret)
{
	rotate_a(a);
	swapnfree(ret, ft_strjoin(*ret, "ra\n"));
	if (*(int *)a->head->content > *(int *)a->head->next->content)
	{
		swap_a(a);
		swapnfree(ret, ft_strjoin(*ret, "sa\n"));
	}
}

void		test_2_sizeof3(char **ret, t_stack *a)
{
	t_list	*tail;
	t_list	*n2;
	t_list	*max;

	if (is_sorted(a->head) == FALSE && a->size == 3)
	{
		tail = ft_lstgettail(a->head);
		n2 = a->head->next;
		max = stack_max(a);
		if (*((int *)tail->content) == *((int *)max->content))
		{
			swap_a(a);
			swapnfree(ret, ft_strjoin(*ret, "sa\n"));
		}
		else if (n2 != NULL && *((int *)n2->content) == *((int *)max->content))
			help_1(a, ret);
		else
			help_2(a, ret);
	}
}

char		*algo2(t_stack *a, t_stack *b, int init_half)
{
	t_list	*tmp;
	char	*ret;

	ret = ft_strnew(1);
	while (a->size > 3 && is_sorted(a->head) == FALSE)
	{
		tmp = stack_min(a);
		while (*((int *)ft_stacktop(a)->content) != *((int *)tmp->content))
		{
			test_1(&ret, tmp, a);
		}
		if (is_sorted(a->head) == FALSE)
		{
			push_b(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pb\n"));
		}
	}
	test_2_sizeof3(&ret, a);
	if(a->size == 2 && is_sorted(a->head) == FALSE)
	{
		swap_a(a);
		swapnfree(&ret, ft_strjoin(ret, "sa\n"));
	}
	while (ft_stackempty(b) == FALSE && (int) a->size < init_half)
	{
		push_a(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pa\n"));
	}
	return (ret);
}
