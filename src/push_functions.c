/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:55:33 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/12 10:55:48 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	if (ft_stackempty(b) == FALSE)
		ft_stackpush(a, ft_stackpop(b));
}

void	push_b(t_stack *a, t_stack *b)
{
	if(ft_stackempty(a) == FALSE)
		ft_stackpush(b, ft_stackpop(a));
}
