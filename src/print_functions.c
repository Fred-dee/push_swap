#include "../includes/push_swap.h"

void	print_rest(t_list *head_a, t_list *head_b)
{
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

void	swap_print(t_list *head_a, t_list *head_b, char *str)
{
	char	*colour1;
	char	*colour2;

	if (ft_strcmp(str, "sa") == 0  || ft_strcmp(str, "sb") == 0)
	{
		colour1 = ft_strdup(RED);
		colour2 = ft_strdup(GREEN);
	}
	if (ft_strcmp(str, "ss") == 0)
	{
		colour1 = ft_strdup(GREEN);
		colour2 = ft_strdup(GREEN);
	}
	if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss"))
	{
		if (head_a != NULL)
		{
			ft_putnbr_clr(colour1, *((int *)head_a->content));
			if(head_b != NULL)
				ft_putchar('\t');
			else
				ft_putchar('\n');
			head_a = head_a->next;
		}
		if (head_b != NULL)
		{
			if(head_a == NULL)
				ft_putchar('\t');
			ft_putnbr_clr(colour1, *((int *)head_b->content));
			head_b = head_b->next;
			ft_putchar('\n');
		}
		if (head_a != NULL)
		{
			ft_putnbr_clr(colour2, *((int *)head_a->content));
			if(head_b != NULL)
				ft_putchar('\t');
			else
				ft_putchar('\n');
			head_a = head_a->next;
		}
		if (head_b != NULL)
		{
			if(head_a == NULL)
				ft_putchar('\t');
			ft_putnbr_clr(colour2, *((int *)head_b->content));
			head_b = head_b->next;
			ft_putchar('\n');
		}
//		free(colour2);
//		free(colour1);
		print_rest(head_a, head_b);
	}
}

void	push_print(t_list *head_a, t_list *head_b, char *str)
{
	char	*colour1;
	char	*colour2;
	if(ft_strcmp(str, "pa") == 0)
	{
		colour1 = ft_strdup(RED);
		colour2 = ft_strdup(GREEN);
	}
	if(ft_strcmp(str, "pb") == 0)
	{
		colour1 = ft_strdup(GREEN);
		colour2 = ft_strdup(RED);
	}
	if(ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0)
	{
		if (head_a != NULL)
		{
			ft_putnbr_clr(colour1, *((int *)head_a->content));
			if(head_b != NULL)
				ft_putchar('\t');
			else
				ft_putchar('\n');
			head_a = head_a->next;
		//	free(colour1);
		}
		if (head_b != NULL)
		{
			if(head_a == NULL)
				ft_putchar('\t');
			ft_putnbr_clr(colour2, *((int *)head_b->content));
			head_b = head_b->next;
			ft_putchar('\n');
		//	free(colour2);
		}
		print_rest(head_a, head_b);		
	}	
}
void	print_stacks_clr(t_stack *a, t_stack *b, char *str)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_stacktop(a);
	head_b = ft_stacktop(b);
	push_print(head_a, head_b, str);
	swap_print(head_a, head_b, str);

}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_stacktop(a);
	head_b = ft_stacktop(b);
	print_rest(head_a, head_b);
}