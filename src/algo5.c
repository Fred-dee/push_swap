/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 09:12:48 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/05 09:12:49 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	first_two(t_stack *a, t_stack *b, char **ret)
{
	push_b(a, b);
	push_b(a, b);
	swapnfree(ret, ft_strjoin(*ret, "pb\npb\n"));
	if (is_sorted_desc(b->head) == FALSE)
	{
		swap_b(b);
		swapnfree(ret, ft_strjoin(*ret, "sb\n"));
	}
}

void	min_score(t_stack *a, t_stack *b, t_rank *rank, int score[3])
{
	int		count;
	t_list	*iter;

	count = 0;
	iter = a->head;
	while (iter != NULL)
	{
		score[2] = get_position(b, iter);
		score[0] = (count > (int)a->size / 2) ? (int)a->size - count : count;
		score[1] = (score[2] > (int)b->size / 2) ? ((int)b->size - score[2])
					: score[2];
		if (score[0] + score[1] < rank->mov_a + rank->mov_b)
		{
			rank->val = *((int *)iter->content);
			rank->pos_a = count;
			rank->pos_b = score[2];
			rank->dir_a = (count > (int)a->size / 2) ? 1 : 0;
			rank->dir_b = (rank->pos_b > (int)b->size / 2) ? 1 : 0;
			rank->mov_a = score[0];
			rank->mov_b = score[1];
		}
		count++;
		iter = iter->next;
	}
}

void	init_rank(t_rank *rank, t_stack *a, t_stack *b)
{
	rank->val = *((int *)ft_stacktop(a)->content);
	rank->pos_a = 0;
	rank->pos_b = get_position(b, a->head);
	rank->dir_a = 0;
	rank->mov_a = 0;
	if (rank->pos_b > (int)b->size / 2)
	{
		rank->mov_b = ((int)b->size - rank->pos_b);
		rank->dir_b = 1;
	}
	else
	{
		rank->mov_b = rank->pos_b;
		rank->dir_b = 0;
	}
}

void	meat(t_stack *a, t_stack *b, char **ret, t_rank *rank)
{
	if (rank->dir_a == 0 && rank->dir_b == 0)
		apply_rotr(a, b, rank, ret);
	else if (rank->dir_a == 1 && rank->dir_b == 1)
		apply_revrotr(a, b, rank, ret);
	else
	{
		apply_rota(a, ret, rank->val, rank->dir_a);
		apply_rotb(b, ret, rank, 0);
		push_b(a, b);
		swapnfree(ret, ft_strjoin(*ret, "pb\n"));
	}
}

char	*algo5(t_stack *a, t_stack *b)
{
	char	*ret;
	int		score[3];
	t_rank	rank;

	ret = ft_strnew(1);
	if (a->size == 1)
		return ("");
	if (is_sorted(a->head) == FALSE)
	{
		first_two(a, b, &ret);
		while (a->size > 0)
		{
			init_rank(&rank, a, b);
			min_score(a, b, &rank, score);
			meat(a, b, &ret, &rank);
		}
	}
	final_rotates(b, &ret);
	while (b->size > 0)
	{
		push_a(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pa\n"));
	}
	return (ret);
}
