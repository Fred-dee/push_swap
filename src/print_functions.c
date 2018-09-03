/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:43:39 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/23 11:43:42 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_rest(t_list *head_a, t_list *head_b, t_list *aterm, t_list *bterm)
{
	while ((head_b != bterm || head_a != aterm))
	{
		if (head_a != aterm && head_a != NULL)
		{
			ft_putnbr(*((int *)head_a->content));
			ft_putchar('\t');
			head_a = head_a->next;
		}
		else
			ft_putchar('\t');
		if (head_b != bterm && head_b != NULL)
		{
			ft_putnbr(*((int *)head_b->content));
			head_b = head_b->next;
		}
		ft_putchar('\n');
	}
	if (head_a == NULL && head_b == NULL)
	{
		ft_putendl("_\t_");
		ft_putendl("a\tb\n");
	}
}

int		swap_print(t_list *head_a, t_list *head_b, char *str)
{
	char	colour[4][8];
	int		i;

	i = 0;
	set_swap_colour(colour, str);
	while (i < 4)
	{
		if (head_a != NULL)
		{
			print_single(colour[i], head_b, *((int *)head_a->content));
			head_a = head_a->next;
		}
		i++;
		if (head_b != NULL)
		{
			print_single(colour[i], head_a, *((int *)head_b->content));
			head_b = head_b->next;
			ft_putchar('\n');
		}
		i++;
	}
	print_rest(head_a, head_b, NULL, NULL);
	return (1);
}

int		push_print(t_list *head_a, t_list *head_b, char *str)
{
	char	colour[2][8];

	if (ft_strcmp(str, "pa") == 0)
	{
		ft_strcpy(colour[0], GREEN);
		ft_strcpy(colour[1], RED);
	}
	if (ft_strcmp(str, "pb") == 0)
	{
		ft_strcpy(colour[0], RED);
		ft_strcpy(colour[1], GREEN);
	}
	if (head_a != NULL)
	{
		print_single(colour[0], head_b, *((int *)head_a->content));
		head_a = head_a->next;
	}
	if (head_b != NULL)
	{
		print_single(colour[1], head_a, *((int *)head_b->content));
		head_b = head_b->next;
		ft_putchar('\n');
	}
	print_rest(head_a, head_b, NULL, NULL);
	return (1);
}

void	print_stacks_clr(t_stack *a, t_stack *b, char *str)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_stacktop(a);
	head_b = ft_stacktop(b);
	ft_putstr_clr(LIGHT_BLUE, str);
	ft_putchar('\n');
	if (ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0)
		push_print(head_a, head_b, str);
	else if (ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
		|| ft_strcmp(str, "ss") == 0)
		swap_print(head_a, head_b, str);
	else if (ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0
		|| ft_strcmp(str, "rr") == 0 || ft_strcmp(str, "rra") == 0 ||
		ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0)
		rotate_print(head_a, head_b, str);
	else
		ft_putstr_clr(RED, "Invalid move selected\n");
}

void	print_stacks(t_stack *a, t_stack *b, char *str)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = ft_stacktop(a);
	head_b = ft_stacktop(b);
	ft_putendl_clr(LIGHT_BLUE, str);
	if(ft_strcmp(str, "pa") == 0 || ft_strcmp(str, "pb") == 0
		||ft_strcmp(str, "sa") == 0 || ft_strcmp(str, "sb") == 0
		|| ft_strcmp(str, "ss") == 0 ||ft_strcmp(str, "ra") == 0 || ft_strcmp(str, "rb") == 0
		|| ft_strcmp(str, "rr") == 0 || ft_strcmp(str, "rra") == 0 ||
		ft_strcmp(str, "rrb") == 0 || ft_strcmp(str, "rrr") == 0 || ft_strcmp(str, "Start:") == 0)
		print_rest(head_a, head_b, NULL, NULL);
	else
		ft_putstr_clr(RED, "Invalid move selected\n");
}
