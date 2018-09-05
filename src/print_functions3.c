/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 10:32:09 by mdilapi           #+#    #+#             */
/*   Updated: 2018/09/05 10:32:14 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	print_single(char const *colour, t_list *head, int value)
{
	ft_putnbr_clr(colour, value);
	if (head != NULL)
		ft_putchar('\t');
	else
		ft_putchar('\n');
}

void	r_p_help2(t_list *head_a, t_list *head_b, char colour[4][8])
{
	t_list	*tail_a;
	t_list	*tail_b;

	tail_a = ft_lstgettail(head_a);
	tail_b = ft_lstgettail(head_b);
	if (head_a != tail_a && head_b == NULL)
		print_rest(head_a, head_b, tail_a, NULL);
	else if (head_b != tail_b && head_a == NULL)
		print_rest(head_a, head_b, NULL, tail_b);
	if (tail_a != NULL && head_a != NULL)
		print_single(colour[2], tail_b, *((int *)tail_a->content));
	if (tail_b != NULL && head_b != NULL)
	{
		ft_putstr("\t");
		print_single(colour[3], tail_a, *((int *)tail_b->content));
	}
	ft_putendl("\n_\t_\na\tb");
}
