#include "../includes/push_swap.h"
#include <stdio.h>

char	*algo5(t_stack *a, t_stack *b)
{
	int		converted[a->size][2];
	int		rank[3];
	char	*ret;
	char	*tmp;
	int		half;
	int		init_size;
	int		count;

	ret = ft_strnew(1);
	stack_to_int(a, converted);
	rank_arr(converted, a->size);
	half = ((int)a->size / 2);
	init_size = (int) a->size;
	if (a->size == 1)
		return ("");
	if (is_sorted(a->head) == FALSE)
	{
		while ((int) a->size > half && a->size >= 2)
		{
			rank[0] = get_rank(converted, init_size, *((int *)ft_stacktop(a)->content));
			count = 0;
			if (rank[0] < half)
			{
				if (b->size == 0)
				{
					push_b(a, b);
					swapnfree(&ret, ft_strjoin(ret, "pb\n"));
				}
				push_b(a, b);
				rank[1] = get_position(b);
				push_a(a, b);
				if (rank[1] > (int)b->size / 2)
					rank[3] = 1;
				else
					rank[3] = 0;
				while (count < rank[1])
				{
					if (rank[3] == 0)
					{
						if (get_rank(converted, init_size, *((int *)ft_stacktop(a)->content))
							>= half)
						{
							rotate_r(a, b);
							swapnfree(&ret, ft_strjoin(ret, "rr\n"));
						}
						else
						{
							rotate_b(b);
							swapnfree(&ret, ft_strjoin(ret, "rb\n"));
						}
					}
					else
					{
						if (get_rank(converted, init_size, *((int *)ft_stacktop(a)->content))
							< half)
						{
							revrotate_r(a, b);
							swapnfree(&ret, ft_strjoin(ret, "rrr\n"));
						}
						else
						{	
							revrotate_b(b);
							swapnfree(&ret, ft_strjoin(ret, "rrb\n"));
						}				
					}
					count++;
				}
				push_b(a, b);
				swapnfree(&ret, ft_strjoin(ret, "pb\n"));
				while (rank[1] > 0)
				{
					if (rank[3] == 0)
					{
						revrotate_b(b);
						swapnfree(&ret, ft_strjoin(ret, "rrb\n"));
					}
					else
					{
						rotate_b(b);
						swapnfree(&ret, ft_strjoin(ret, "rb\n"));						
					}
					rank[1]--;
				}	
			}
			else
			{	
				rotate_a(a);
				swapnfree(&ret, ft_strjoin(ret, "ra\n"));
			}
		}
	}
	tmp = algo3(a, b, half);
	swapnfree(&ret, ft_strjoin(ret, tmp));
	free(tmp);
	while ((int )b->size >= half)
	{
		push_a(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pa\n"));			
	}
	print_stacks(a, b, "ra");
	return (ret);
}

				/*if (get_rank(converted, init_size, *((int *)ft_stacktop(a)->content)) > half
					&& *((int *)ft_stacktop(b)->content) == *((int *)stack_min(b)->content))
				{
					rotate_r(a, b);
					swapnfree(&ret, ft_strjoin(ret, "rr\n"));
				}
				else if (*((int *)ft_stacktop(b)->content) == *((int *)stack_min(b)->content) && b->size > 1)
				{
					rotate_b(b);
					swapnfree(&ret, ft_strjoin(ret, "rb\n"));
					
				}
				else if (b->size >= 2 && *((int *)ft_stacktop(b)->content) < *((int *)b->head->next->content)
					&& (a->size >= 2 && *((int *)ft_stacktop(a)->content) > *((int *)a->head->next->content)))
				{
					swap_s(a, b);
					swapnfree(&ret, ft_strjoin(ret, "ss\n"));
				}
				else if(b->size >= 2 && *((int *)ft_stacktop(b)->content) < *((int *)b->head->next->content))
				{
					swap_b(b);
					swapnfree(&ret, ft_strjoin(ret, "sb\n"));
				} */