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

#include <push_swap.h>

int		get_position(t_stack *b, t_list *elem)
{
	int		count;
	t_list	*tmp;
	int		val;

	if (b->size > 0 && elem != NULL)
	{
		count = 1;
		tmp = b->head;
		val = *(int *)elem->content;
		if (val > *(int *)stack_max(b)->content)
			return (ft_stack_indexof(b, stack_max(b)));
		if (val < *(int *)stack_min(b)->content)
			return (ft_stack_indexof(b, stack_max(b)));
		while (tmp->next != NULL)
		{
			if (*(int *)tmp->content > val && *(int *)tmp->next->content < val)
				return (count);
			tmp = tmp->next;
			count++;
		}
		return (count);
	}
	return (0);
}

void	apply_rotr(t_stack *a, t_stack *b, t_rank *rank, char **ret)
{
	int	count;

	count = 0;
	while (*(int *)a->head->content != rank->val && count < rank->pos_b)
	{
		rotate_r(a, b);
		swapnfree(ret, ft_strjoin(*ret, "rr\n"));
		count++;
	}
	apply_rota(a, ret, rank->val, 0);
	apply_rotb(b, ret, rank, count);
	push_b(a, b);
	swapnfree(ret, ft_strjoin(*ret, "pb\n"));
}

void	apply_revrotr(t_stack *a, t_stack *b, t_rank *rank, char **ret)
{
	int	count;

	count = 0;
	while (*(int *)a->head->content != rank->val && count
		< (int)b->size - rank->pos_b)
	{
		revrotate_r(a, b);
		swapnfree(ret, ft_strjoin(*ret, "rrr\n"));
		count++;
	}
	apply_rota(a, ret, rank->val, 1);
	apply_rotb(b, ret, rank, count);
	push_b(a, b);
	swapnfree(ret, ft_strjoin(*ret, "pb\n"));
}

void	apply_rota(t_stack *a, char **ret, int search, int dir)
{
	if (dir == 1)
	{
		while (*(int *)a->head->content != search)
		{
			revrotate_a(a);
			swapnfree(ret, ft_strjoin(*ret, "rra\n"));
		}
	}
	else
	{
		while (*(int *)a->head->content != search)
		{
			rotate_a(a);
			swapnfree(ret, ft_strjoin(*ret, "ra\n"));
		}
	}
}

void	apply_rotb(t_stack *b, char **ret, t_rank *rank, int count)
{
	if (rank->dir_b == 0)
	{
		while (count < rank->pos_b)
		{
			rotate_b(b);
			swapnfree(ret, ft_strjoin(*ret, "rb\n"));
			count++;
		}
	}
	else
	{
		while (count < (int)b->size - rank->pos_b)
		{
			revrotate_b(b);
			swapnfree(ret, ft_strjoin(*ret, "rrb\n"));
			count++;
		}
	}
}
