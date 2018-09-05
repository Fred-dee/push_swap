/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 10:44:59 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/24 10:45:00 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		flag_check(t_flags *flag)
{
	if (flag->v > 0)
	{
		ft_putstr_clr(LIGHT_GREEN, "Debugging mode enabled.\n");
	}
	if (flag->c > 0)
	{
		if (flag->v > 0)
			ft_putstr_clr(LIGHT_GREEN, "Colour mode enabled.\n");
		else
			ft_putstr_clr(LIGHT_RED, "Colour mode requires -v to be set.\n");
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
