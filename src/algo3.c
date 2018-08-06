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
#include <stdio.h>

char	*algo3(t_stack *a, t_stack *b)
{
	char	*ret;
	int		half;
	t_list	*max;
	t_list	*min;

	ret = ft_strnew(1);
	half = (int) a->size / 2;
	min = stack_min(a);
	max = stack_min_range(a, (int) a->size);
	if (((int *)min->content) < ((int *)max->content))
		printf("The min falls into the bottom half\n");
	swapnfree(&ret, ft_strjoin(ret, algo2(a, b)));
	return (ret);
}