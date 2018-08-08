#include "../includes/push_swap.h"

char	*algo4(t_stack *a, t_stack *b)
{
	char	*ret;

	ret = ft_strnew(1);
	while (a->size != 0)
	{
		rotate_a(a);
		swapnfree(&ret, ft_strjoin(ret, "ra\n"));
		while (b->size != 0 && *((int *)ft_stacktop(b)->content)
			> *((int *)ft_lstgettail(a->head)->content))
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
		revrotate_a(a);
		swapnfree(&ret, ft_strjoin(ret, "rra\n"));
		push_b(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pb\n"));
	}
	while (b->size != 0)
	{
		push_a(a, b);
		swapnfree(&ret, ft_strjoin(ret, "pa\n"));
	}
	return (ret);
}