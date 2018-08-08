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

	ret = ft_strnew(1);
	stack_to_int(a, converted);
	rank_arr(converted, a->size);
	half = ((int)a->size /2) + 1;
	init_size = (int) a->size;
	if (a->size == 1)
		return ("");
	if (is_sorted(a->head) == FALSE)
	{
		while ((int) a->size > half)
		{
			if (get_rank(converted, init_size, *((int *)ft_stacktop(a)->content)) < half)
			{
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
				}
				else if (b->size >= 3 && *((int *)ft_stacktop(b)->content) < *((int *)b->head->next->content))
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
		swapnfree(&ret, ft_strjoin(ret, algo5_help(a, b)));
		while (ft_stackempty(b) == FALSE)
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
	}
	return (ret);
}