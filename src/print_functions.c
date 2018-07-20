#include "../includes/push_swap.h"

void	print_rest(t_list *head_a, t_list *head_b, t_list *aterm, t_list *bterm)
{
	while (head_b != bterm || head_a != bterm)
	{
		if (head_a != aterm)
		{
			ft_putnbr(*((int *)head_a->content));
			ft_putchar('\t');
			head_a = head_a->next;
		}
		else
			ft_putchar('\t');
		if (head_b !=  bterm)
		{
			ft_putnbr(*((int *)head_b->content));
			head_b = head_b->next;
		}
		ft_putchar('\n');
	}
	ft_putendl("_\t_");
	ft_putendl("a\tb\n");
}


int	rotate_print(t_list *head_a, t_list *head_b, char *str)
{
	char	*colour1;
	char	*colour2;
	t_list	*tail_a;
	t_list	*tail_b;

	tail_a = ft_lstgettail(head_a);
	tail_b = ft_lstgettail(head_b);
	if(ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0 || ft_strcmp(str, "rr") == 0)
	{
		colour1 = ft_strdup(RED);
		colour2 = ft_strdup(GREEN);
	}
	if(ft_strcmp(str, "ra") == 0)
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
			ft_putnbr_clr(WHITE, *((int *)head_b->content));
			head_b = head_b->next;
			ft_putchar('\n');
		}
		print_rest(head_a, head_b, tail_a, tail_b);
		if (tail_a != NULL)
		{
			ft_putnbr_clr(colour2, *((int *)tail_a->content));
			if(tail_b != NULL)
				ft_putchar('\t');
			else
				ft_putchar('\n');
		}
		if (tail_b != NULL)
		{
			if(tail_a == NULL)
				ft_putchar('\t');
			ft_putnbr_clr(WHITE, *((int *)tail_b->content));
			ft_putchar('\n');
		}	
		return (1);	
	}
	return (0);
}

int	swap_print(t_list *head_a, t_list *head_b, char *str)
{
	char	*colour1;
	char	*colour2;

	if(ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
	{
		colour1 = ft_strdup(RED);
		colour2 = ft_strdup(GREEN);
	}
	if (ft_strcmp(str, "sa") == 0 )
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
			ft_putnbr_clr(WHITE, *((int *)head_b->content));
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
			ft_putnbr_clr(WHITE, *((int *)head_b->content));
			head_b = head_b->next;
			ft_putchar('\n');
		}

	}
	if (ft_strcmp(str, "sb") == 0)
	{
		if (head_a != NULL)
		{
			ft_putnbr_clr(WHITE, *((int *)head_a->content));
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
			ft_putnbr_clr(WHITE, *((int *)head_a->content));
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
	}
	if (ft_strcmp(str, "ss") == 0)
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
	}
	if(ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0 || ft_strcmp(str, "ss") == 0)
	{
		print_rest(head_a, head_b, NULL, NULL);
		return (1);
	}
	return (0);
}

int	push_print(t_list *head_a, t_list *head_b, char *str)
{
	char	*colour1;
	char	*colour2;
	if(ft_strcmp(str, "pa") == 0)
	{
		colour1 = ft_strdup(GREEN);
		colour2 = ft_strdup(RED);
	}
	if(ft_strcmp(str, "pb") == 0)
	{
		colour1 = ft_strdup(RED);
		colour2 = ft_strdup(GREEN);
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
		}
		if (head_b != NULL)
		{
			if(head_a == NULL)
				ft_putchar('\t');
			ft_putnbr_clr(colour2, *((int *)head_b->content));
			head_b = head_b->next;
			ft_putchar('\n');
		}
		print_rest(head_a, head_b, NULL, NULL);
		free(colour1);
		free(colour2);
		return (1);
	}
	return (0);	
}
void	print_stacks_clr(t_stack *a, t_stack *b, char *str)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_stacktop(a);
	head_b = ft_stacktop(b);
	if(push_print(head_a, head_b, str) != 1)
	{
		if(swap_print(head_a, head_b, str) != 1)
		{
			if(rotate_print(head_a, head_b, str) != 1)
				ft_putstr_clr(RED, "Invalid move selected\n");
		}
	}
}

void	print_stacks(t_stack *a, t_stack *b)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_stacktop(a);
	head_b = ft_stacktop(b);
	print_rest(head_a, head_b, NULL, NULL);
}