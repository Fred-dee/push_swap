#include "../includes/push_swap.h"

static void	test_1(char **ret, t_list *tmp, t_stack *b)
{
	t_list *n2;
	t_list *t2;

	n2 = ft_stacktop(b)->next;
	t2 = ft_lstat(b->head, b->size - 2);
	if (*((int *)ft_lstgettail(b->head)->content) == *((int *)tmp->content))
	{
		revrotate_b(b);
		swapnfree(ret, ft_strjoin(*ret, "rrb\n"));
	}
	else if (*((int *)n2->content) == *((int *)tmp->content))
	{
		swap_b(b);
		swapnfree(ret, ft_strjoin(*ret, "sb\n"));
	}
	else if (t2 != NULL && *((int *)t2->content) == *((int *)tmp->content))
	{
		revrotate_b(b);
		swapnfree(ret, ft_strjoin(*ret, "rrb\n"));
	}
	else
	{
		rotate_b(b);
		swapnfree(ret, ft_strjoin(*ret, "rb\n"));
	}
}

static void	help_1(t_stack *b, char **ret)
{
	revrotate_b(b);
	swapnfree(ret, ft_strjoin(*ret, "rrb\n"));
	if (*(int *)b->head->content < *(int *)b->head->next->content)
	{
		swap_b(b);
		swapnfree(ret, ft_strjoin(*ret, "sb\n"));
	}
}

static void	help_2(t_stack *b, char **ret)
{
	rotate_b(b);
	swapnfree(ret, ft_strjoin(*ret, "rb\n"));
	if (*(int *)b->head->content < *(int *)b->head->next->content)
	{
		swap_b(b);
		swapnfree(ret, ft_strjoin(*ret, "sb\n"));
	}
}

void		test_2_sizeof3_inv(char **ret, t_stack *b)
{
	t_list	*tail;
	t_list	*n2;
	t_list	*max;

	if (is_sorted_desc(b->head) == FALSE && b->size == 3)
	{
		tail = ft_lstgettail(b->head);
		n2 = b->head->next;
		max = stack_max(b);
		if (*((int *)tail->content) == *((int *)max->content))
		{
			swap_b(b);
			swapnfree(ret, ft_strjoin(*ret, "sb\n"));
		}
		else if (n2 != NULL && *((int *)n2->content) == *((int *)max->content))
			help_2(b, ret);
		else
			help_1(b, ret);
	}
}

char		*algo5_help(t_stack *a, t_stack *b)
{
	t_list	*tmp;
	char	*ret;

	ret = ft_strnew(1);
	while (b->size > 3 && is_sorted(b->head) == FALSE)
	{
		tmp = stack_max(b);
		while (*((int *)ft_stacktop(b)->content) != *((int *)tmp->content))
		{
			test_1(&ret, tmp, b);
		}
		if (is_sorted(b->head) == FALSE)
		{
			push_a(a, b);
			swapnfree(&ret, ft_strjoin(ret, "pa\n"));
		}
	}
	test_2_sizeof3_inv(&ret, b);
	return (ret);
}