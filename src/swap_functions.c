/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:52:44 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/12 10:53:08 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_a(t_stack *a)
{
	if (a != NULL)
	{
		ft_stack_swap_top(a);
	}
}

void	swap_b(t_stack *b)
{
	if(b != NULL)
	{
		ft_stack_swap_top(b);
	}
}

void	swap_s(t_stack *a, t_stack *b)
{
	if (a != NULL && b != NULL)
	{
		swap_a(a);
		swap_b(b);
	}
}
