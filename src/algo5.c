#include "../includes/push_swap.h"
#include <stdio.h>


/**
** rank[0] = int that im selecting
** rank[1] = position of number in a
** rank[2] = rank of number in b
** rank[3] = direction 0 is r and 1 is rr in A
** rank[4] = direction 0 is r and 1 is rr in B
**/

char	*algo5(t_stack *a, t_stack *b)
{
	int		rank[7];
	char	*ret;
	int		count;
	t_list	*iter;
	int		score[3];
	int		reps;

	ret = ft_strnew(1);
	if (a->size == 1)
		return ("");
	if (is_sorted(a->head) == FALSE)
	{
		push_b(a, b);
		push_b(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pb\npb\n"));
		if (is_sorted_desc(b->head) == FALSE)
		{
			swap_b(b);
			swapnfree(&ret, ft_strjoin(ret, "sb\n"));
		}
		reps = 0;
		while (a->size > 0)
		{
			reps++;
			rank[0] = *((int *)ft_stacktop(a)->content);
			rank[1] = 0;
			rank[2] = get_position(b, a->head);
			rank[3] = 0;
			rank[4] = 0;

			rank[5] = 0;
			if (rank[2] > (int) b->size / 2)
				rank[6] = 2 * ((int) b->size - rank[2]);
			else
				rank[6] = 2 * rank[2];

			iter = ft_stacktop(a);
			count = 0;
			while (iter != NULL)
			{
				score[2] = get_position(b, iter);
				if (count > (int) a->size / 2)
					score[0] = (int) a->size - count;
				else
					score[0] = count;
				if (score[2] > (int)b->size / 2)
					score[1] = 2 * ((int) b->size - score[2]);
				else
					score[1] = 2 * score[2];
				printf("%d has score: %d %d\n", *(int *)iter->content, score[0], score[1]);

				if (score[0] + score[1] < rank[5] + rank[6])
				{
					rank[0] = *((int * )iter->content);
					rank[1] = count;
					rank[2] = get_position(b, iter);
					if(count > (int) a->size / 2)
						rank[3] = 1;
					else
						rank[3] = 0;
					if (rank[2] > (int) b->size / 2)
						rank[4] = 1;
					else
						rank[4] = 0;
					rank[5] = score[0];
					rank[6] = score[1];
				}
				count++;
				iter = iter->next;
			}
			if (reps == 10)
			{
				print_stacks(a, b, "ra");
				while (1)
					;
			} 
			if (rank[3] == 0 && rank[4] == 0)
			{
				apply_rotr(a, b, rank, &ret);
			}
			else if (rank[3] == 1 && rank[4] == 0)
			{
				apply_revrotr(a, b, rank, &ret);
			}
			else
			{
				apply_rota(a, &ret, rank[0], rank[3]);
				apply_rotb(a, b, &ret, rank[2], rank[4]);
			}
		}
	}
	while (b->size > 0)
	{
		push_a(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pa\n"));
	}
	return (ret); 
}
