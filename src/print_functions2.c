/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 11:44:32 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/23 11:44:33 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	r_p_help(t_list **head_a, t_list **head_b, char colour[4][8])
{
	if (*head_a != NULL)
	{
		print_single(colour[0], *head_b, *((int *)head_a[0]->content));
		*head_a = head_a[0]->next;
	}
	if (*head_b != NULL)
	{
		print_single(colour[1], *head_a, *((int *)head_b[0]->content));
		*head_b = head_b[0]->next;
		ft_putchar('\n');
	}
}

int		rotate_print(t_list *head_a, t_list *head_b, char *str)
{
	char	colour[4][8];
	t_list	*tail_a;
	t_list	*tail_b;

	tail_a = ft_lstgettail(head_a);
	tail_b = ft_lstgettail(head_b);
	set_rotate_colour(colour, str);
	r_p_help(&head_a, &head_b, colour);
	while (head_b != NULL && head_a != NULL &&
		head_b != tail_b && head_a != tail_a)
	{
		print_single(WHITE, head_b, *((int *)head_a->content));
		head_a = head_a->next;
		print_single(WHITE, head_a, *((int *)head_b->content));
		head_b = head_b->next;
		ft_putchar('\n');
	}
	r_p_help2(head_a, head_b, colour);
	return (1);
}

void	set_rotate_colour_help(char colour[4][8], char *str)
{
	if (ft_strcmp(str, "rra") == 0)
	{
		ft_strcpy(colour[0], GREEN);
		ft_strcpy(colour[1], WHITE);
		ft_strcpy(colour[2], RED);
		ft_strcpy(colour[3], WHITE);
	}
	else if (ft_strcmp(str, "rrb") == 0)
	{
		ft_strcpy(colour[0], WHITE);
		ft_strcpy(colour[1], GREEN);
		ft_strcpy(colour[2], WHITE);
		ft_strcpy(colour[3], RED);
	}
	else if (ft_strcmp(str, "rrr") == 0)
	{
		ft_strcpy(colour[0], GREEN);
		ft_strcpy(colour[1], GREEN);
		ft_strcpy(colour[2], RED);
		ft_strcpy(colour[3], RED);
	}
}

void	set_rotate_colour(char colour[4][8], char *str)
{
	if (ft_strcmp(str, "ra") == 0)
	{
		ft_strcpy(colour[0], RED);
		ft_strcpy(colour[1], WHITE);
		ft_strcpy(colour[2], GREEN);
		ft_strcpy(colour[3], WHITE);
	}
	else if (ft_strcmp(str, "rb") == 0)
	{
		ft_strcpy(colour[0], WHITE);
		ft_strcpy(colour[1], RED);
		ft_strcpy(colour[2], WHITE);
		ft_strcpy(colour[3], GREEN);
	}
	else if (ft_strcmp(str, "rr") == 0)
	{
		ft_strcpy(colour[0], RED);
		ft_strcpy(colour[1], RED);
		ft_strcpy(colour[2], GREEN);
		ft_strcpy(colour[3], GREEN);
	}
	else
		set_rotate_colour_help(colour, str);
}

void	set_swap_colour(char colour[4][8], char *str)
{
	if (ft_strcmp(str, "sa") == 0)
	{
		ft_strcpy(colour[0], RED);
		ft_strcpy(colour[1], WHITE);
		ft_strcpy(colour[2], GREEN);
		ft_strcpy(colour[3], WHITE);
	}
	if (ft_strcmp(str, "sb") == 0)
	{
		ft_strcpy(colour[0], WHITE);
		ft_strcpy(colour[1], RED);
		ft_strcpy(colour[2], WHITE);
		ft_strcpy(colour[3], GREEN);
	}
	if (ft_strcmp(str, "ss") == 0)
	{
		ft_strcpy(colour[0], RED);
		ft_strcpy(colour[1], RED);
		ft_strcpy(colour[2], GREEN);
		ft_strcpy(colour[3], GREEN);
	}
}
