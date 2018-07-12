/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:02:01 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/12 15:02:03 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_a(t_stack *a)
{
	ft_stackrotate(a);
}

void	rotate_b(t_stack *b)
{
	ft_stackrotate(b);
}

void	rotate_r(t_stack *a, t_stack *b)
{
	rotate_a(a);
	rotate_b(b);
}

void	revrotate_a(t_stack *a)
{
	ft_stackrevrotate(a);
}

void	revrotate_b(t_stack *b)
{
	ft_stackrevrotate(b);
}

void	revrotate_r(t_stack *a, t_stack *b)
{
	ft_stackrevrotate(a);
	ft_stackrevrotate(b);
}
