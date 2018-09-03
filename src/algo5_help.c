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

int		get_position(t_stack *b, t_list *elem)
{
	int 	count;
	t_list	*tmp;

	if (b->size > 0 && is_sorted_desc(b->head))
	{
		count = 0;
		tmp = b->head;
		while (tmp != NULL && elem != NULL
			&& *(int *)elem->content <  *(int *) tmp->content)
		{
			tmp = tmp->next;
			count++;
		}
		return (count);		
	}
	return (0);
}

void	apply_rotr(t_stack *a, t_stack *b, int rank[7], char **ret)
{
	int	count;

	count = 0;
	while (*(int *)a->head->content != rank[0] && count < rank[2])
	{
		rotate_r(a, b);
		swapnfree(ret, ft_strjoin(*ret, "rr\n"));
		count++;
	}
	apply_rota(a, ret, rank[0], 0);
	apply_rotb(a, b, ret, rank[2] - count, 0);

}

void	apply_revrotr(t_stack *a, t_stack *b, int rank[7], char	**ret)
{
	int	count;

	count = 0;
	while (*(int *)a->head->content != rank[0] && count < (int) b->size - rank[2])
	{
		revrotate_r(a, b);
		swapnfree(ret, ft_strjoin(*ret, "rrr\n"));
		count++;
	}
	apply_rota(a, ret, rank[0], 1);
	apply_rotb(a, b, ret, (int)b->size - rank[2] - count, 1);
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

void	apply_rotb(t_stack *a, t_stack *b, char **ret, int pos, int dir)
{
	int	count;

	count = 0;
	if (dir == 0)
	{
		while (count < pos)
		{
			rotate_b(b);
			swapnfree(ret, ft_strjoin(*ret, "rb\n"));
			count++;
		}
		push_b(a, b);
		swapnfree(ret, ft_strjoin(*ret, "pb\n"));
		while (count > 0)
		{
			revrotate_b(b);
			swapnfree(ret, ft_strjoin(*ret, "rrb\n"));
			count--;
		}
	}
	else
	{
		while(count < (int)b->size - pos)
		{
			revrotate_b(b);
			swapnfree(ret, ft_strjoin(*ret, "rrb\n"));
			count++;				
		}
		push_b(a, b);
		swapnfree(ret, ft_strjoin(*ret, "pb\n"));
		while (count > -1)
		{
			rotate_b(b);
			swapnfree(ret, ft_strjoin(*ret, "rb\n"));
			count--;				
		}
	}
}
