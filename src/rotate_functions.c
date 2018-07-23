/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:02:01 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/23 11:15:30 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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
