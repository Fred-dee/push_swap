#include "../includes/push_swap.h"
#include <stdio.h>

char	*algo5(t_stack *a, t_stack *b)
{
	int		converted[a->size][2];
	char	*ret;
	(void)	b;

	ret = NULL;
	stack_to_int(a, converted);
	rank_arr(converted, a->size);
	return (ret);
}