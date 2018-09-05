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

void	last_steps(t_stack *a, t_stack *b, char **ret)
{
	if (a->size <= 3)
	{
		if (a->size == 2)
		{
			if (is_sorted(a->head) == FALSE)
			{
				swap_a(a);
				swapnfree(ret, ft_strjoin(*ret, "sa\n"));
			}
		}
		else
			test_2_sizeof3(ret, a);
	}
	while (b->size > 0)
	{
		push_a(a, b);
		swapnfree(ret, ft_strjoin(*ret, "pa\n"));
	}
}

int		up_rot(t_stack *a, t_stack *b, char **ret, t_list *min)
{
	int		flag;
	t_list	*min_next;

	flag = 0;
	min_next = stack_minnext(a, min);
	if (min_next != NULL)
		if (ft_stack_indexof(a, min_next) >= (int)a->size / 2 &&
			ft_stack_indexof(a, min_next) > ft_stack_indexof(a, min))
		{
			flag = 1;
			while (*((int *)ft_stacktop(a)->content)
				!= *((int *)min_next->content))
			{
				revrotate_a(a);
				swapnfree(ret, ft_strjoin(*ret, "rra\n"));
			}
			push_b(a, b);
			swapnfree(ret, ft_strjoin(*ret, "pb\n"));
		}
	while (*((int *)ft_stacktop(a)->content) != *((int *)min->content))
	{
		revrotate_a(a);
		swapnfree(ret, ft_strjoin(*ret, "rra\n"));
	}
	return (flag);
}

void	down_rot_help(t_stack *a, char **ret, t_list *min)
{
	while (*((int *)ft_stacktop(a)->content) != *((int *)min->content))
	{
		if (a->size >= 2 && *((int *)ft_stacktop(a)->next->content)
			== *((int *)min->content))
		{
			swap_a(a);
			swapnfree(ret, ft_strjoin(*ret, "sa\n"));
		}
		else
		{
			rotate_a(a);
			swapnfree(ret, ft_strjoin(*ret, "ra\n"));
		}
	}
}

int		down_rot(t_stack *a, t_stack *b, char **ret, t_list *min)
{
	int		flag;
	t_list	*min_next;

	min_next = stack_minnext(a, min);
	flag = 0;
	if (min_next != NULL)
		if (ft_stack_indexof(a, min_next) < (int)a->size / 2 &&
			ft_stack_indexof(a, min_next) < ft_stack_indexof(a, min))
		{
			flag = 1;
			while (*((int *)ft_stacktop(a)->content)
				!= *((int *)min_next->content))
			{
				rotate_a(a);
				swapnfree(ret, ft_strjoin(*ret, "ra\n"));
			}
			push_b(a, b);
			swapnfree(ret, ft_strjoin(*ret, "pb\n"));
		}
	down_rot_help(a, ret, min);
	return (flag);
}

char	*algo3(t_stack *a, t_stack *b)
{
	char	*ret;
	int		flag;
	t_list	*min;

	ret = ft_strnew(1);
	while (is_sorted(a->head) == FALSE && a->size > 3)
	{
		min = stack_min(a);
		flag = 0;
		if (ft_stack_indexof(a, min) > (int)a->size / 2)
			flag = up_rot(a, b, &ret, min);
		else
			flag = down_rot(a, b, &ret, min);
		push_b(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pb\n"));
		if (flag == 1)
		{
			swap_b(b);
			swapnfree(&ret, ft_strjoin(ret, "sb\n"));
		}
	}
	last_steps(a, b, &ret);
	return (ret);
}
