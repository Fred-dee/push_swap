#include "../includes/push_swap.h"
#include <stdio.h>

int		get_rank(int arr[][2], int size, int elem)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (elem == arr[i][0])
			return (arr[i][1]);
		i++;
	}
	return (-1);
}

char	*algo5(t_stack *a, t_stack *b)
{
	int		converted[a->size][2];
	char	*ret;
	int		half;
	int		init_size;
	int		count;

	ret = ft_strnew(1);
	stack_to_int(a, converted);
	rank_arr(converted, a->size);
	half = ((int)a->size /2);
	init_size = (int) a->size;
	count = 0;
	if (a->size == 1)
		return ("");
	if (is_sorted(a->head) == FALSE)
	{
		while ((int) a->size >= half && a->size > 2)
		{
			if (get_rank(converted, init_size, *((int *)ft_stacktop(a)->content)) <= half)
			{
				if(get_rank(converted, init_size, *((int *)ft_stacktop(a)->next->content)) <= half &&
					*((int *)ft_stacktop(a)->next->content) < *((int *)ft_stacktop(a)->content))
				{
					swap_a(a);
					swapnfree(&ret, ft_strjoin(ret, "sa\n"));
				}
				push_b(a, b);
				swapnfree(&ret, ft_strjoin(ret, "pb\n"));
				if (get_rank(converted, init_size, *((int *)ft_stacktop(a)->content)) > half
					&& *((int *)ft_stacktop(b)->content) == *((int *)stack_min(b)->content))
				{
					rotate_r(a, b);
					swapnfree(&ret, ft_strjoin(ret, "rr\n"));
				}
				else if (*((int *)ft_stacktop(b)->content) == *((int *)stack_min(b)->content) && b->size > 1)
				{
					rotate_b(b);
					swapnfree(&ret, ft_strjoin(ret, "rb\n"));
					count++;
				}
				else if (b->size >= 2 && *((int *)ft_stacktop(b)->content) < *((int *)b->head->next->content)
					&& (a->size >= 2 && *((int *)ft_stacktop(a)->content) > *((int *)a->head->next->content)))
				{
					swap_s(a, b);
					swapnfree(&ret, ft_strjoin(ret, "ss\n"));
				}
<<<<<<< HEAD
				else if (b->size >= 2 && *((int *)ft_stacktop(b)->content) < *((int *)b->head->next->content)
					&& (a->size >= 2 && *((int *)ft_stacktop(a)->content) > *((int *)a->head->next->content)))
				{
					swap_s(a, b);
					swapnfree(&ret, ft_strjoin(ret, "ss\n"));
				}
=======
>>>>>>> a4140dd61480a574da8e5b08386262d9ba95b984
				else if(b->size >= 2 && *((int *)ft_stacktop(b)->content) < *((int *)b->head->next->content))
				{
					swap_b(b);
					swapnfree(&ret, ft_strjoin(ret, "sb\n"));
				}
			}
			else
			{
				rotate_a(a);
				swapnfree(&ret, ft_strjoin(ret, "ra\n"));
			}
		}
		swapnfree(&ret, ft_strjoin(ret, algo3(a, b, half)));
<<<<<<< HEAD
		swapnfree(&ret, ft_strjoin(ret, algo5_help(a, b)));
		//swapnfree(&ret, ft_strjoin(ret, algo5_help2(a, b)));
=======
		//swapnfree(&ret, ft_strjoin(ret, algo5_help(a, b)));
		swapnfree(&ret, ft_strjoin(ret, algo5_help2(a, b)));
>>>>>>> a4140dd61480a574da8e5b08386262d9ba95b984
		while (ft_stackempty(b) == FALSE)
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
	}
	return (ret);
}