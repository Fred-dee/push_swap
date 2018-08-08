#include "../includes/push_swap.h"

char	*algo5(t_stack *a, t_stack *b)
{
	int		**converted;

	converted = stack_to_int(a);
	rank_arr(converted);
	
}