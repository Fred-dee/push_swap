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

#include "../includes/push_swap.h"

int		rotate_print(t_list *head_a, t_list *head_b, char *str)
{
	char	colour[4][8];
	t_list	*tail_a;
	t_list	*tail_b;

	tail_a = ft_lstgettail(head_a);
	tail_b = ft_lstgettail(head_b);
	set_rotate_colour(colour, str);
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
	print_rest(head_a, head_b, tail_a, tail_b);
	if (tail_a != NULL)
		print_single(colour[2], tail_b, *((int *)tail_a->content));
	if (tail_b != NULL)
		print_single(colour[3], tail_a, *((int *)tail_b->content));
	ft_putendl("\n_\t_\na\tb");
	return (1);
}

void	print_single(char const *colour, t_list *head, int value)
{
	ft_putnbr_clr(colour, value);
	if (head != NULL)
		ft_putchar('\t');
	else
		ft_putchar('\n');
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
	else if (ft_strcpy(str, "rrr") == 0)
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
	else if (ft_strcpy(str, "rr") == 0)
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
	if (ft_strcpy(str, "ss") == 0)
	{
		ft_strcpy(colour[0], RED);
		ft_strcpy(colour[1], RED);
		ft_strcpy(colour[2], GREEN);
		ft_strcpy(colour[3], GREEN);
	}
}
