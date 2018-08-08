#include "../includes/push_swap.h"
#include <stdio.h>

char	*algo5_help(t_stack *a, t_stack *b)
{
	char	*ret;
	int		half;
	t_list	*max;

	ret = ft_strnew(1);
	half = (int) b->size / 2;
	(void )half;
	if (b->size > 3)
	{
		while ((int )b->size > 0 && is_sorted_desc(b->head) == FALSE)
		{
			max = stack_max(b);
			if (*((int *)ft_stacktop(b)->content) == *((int *)max->content))
			{
				push_a(a, b);
				swapnfree(&ret, ft_strjoin(ret, "pa\n"));
			}
			else
			{
				if (ft_stack_indexof(b, max) > (int) b->size / 2)
				{
					while(*((int *)ft_stacktop(b)->content) != *((int *)max->content))
					{
						revrotate_b(b);
						swapnfree(&ret, ft_strjoin(ret, "rrb\n"));
					}
				}
				else
				{
					while(*((int *)ft_stacktop(b)->content) != *((int *)max->content))
					{
						rotate_b(b);
						swapnfree(&ret, ft_strjoin(ret, "rb\n"));
					}
				}
				push_a(a, b);
				swapnfree(&ret, ft_strjoin(ret, "pa\n"));
			}

		}
	}
	else
	{
		if (b->size == 2)
		{
			if (is_sorted_desc(b->head) == FALSE)
			{
				swap_b(b);
				return("sb\n");
			}
		}
		else
			 test_2_sizeof3(&ret, b);
	}
	return (ret);
}



			/*while(*((int *)ft_stacktop(b)->content) != *((int *)max->content))
			{	
				n2 = ft_stacktop(b)->next;
				t2 = ft_lstat(b->head, b->size - 2);
				if (*((int *)ft_lstgettail(b->head)->content) == *((int *)max->content))
				{
					revrotate_b(b);
					swapnfree(&ret, ft_strjoin(ret, "rrb\n"));
				}
				else if (*((int *)n2->content) == *((int *)max->content))
				{
					swap_b(b);
					swapnfree(&ret, ft_strjoin(ret, "sb\n"));
				}
				else if (t2 != NULL && *((int *)t2->content) == *((int *)max->content))
				{
					revrotate_b(b);
					swapnfree(&ret, ft_strjoin(ret, "rrb\n"));
				}
				else
				{
					rotate_b(b);
					swapnfree(&ret, ft_strjoin(ret, "rb\n"));
				}
			}
			if(is_sorted_desc(b->head) == FALSE)
			{
				push_a(a, b);
				swapnfree(&ret, ft_strjoin(ret, "pa\n"));
			} */