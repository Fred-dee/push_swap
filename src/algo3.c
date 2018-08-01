/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 13:22:32 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/24 13:22:48 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	*algo3(t_stack *a, t_stack *b)
{
	int		half;
	char	*ret;
	t_list	*min;
	t_list	*max;

	half = a->size / 2;
	min = stack_min_range(a, half);
	max = stack_max_range(a + half, half);

	
	return (ret);
}