#include "../includes/push_swap.h"

void	print_stacks_clr(t_stack *a, t_stack *b, char *str)
{

}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_stacktop(a);
	head_b = ft_stacktop(b);
	while (head_b != NULL || head_a != NULL)
	{
		if (head_a != NULL)
		{
			ft_putnbr(*((int *)head_a->content));
			ft_putchar('\t');
			head_a = head_a->next;
		}
		else
			ft_putchar('\t');
		if (head_b != NULL)
		{
			ft_putnbr(*((int *)head_b->content));
			head_b = head_b->next;
		}
		ft_putchar('\n');
	}
	ft_putendl("_\t_");
	ft_putendl("a\tb\n");
}