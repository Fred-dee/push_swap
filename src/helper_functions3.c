/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 10:44:59 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/24 10:45:00 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	flag_check(t_flags *flag)
{
	if (flag->v > 0)
	{
		ft_putstr_clr(LIGHT_GREEN, "Debugging mode enabled.\n");
	}
	if (flag->c > 0)
	{
		if (flag->v > 0)
			ft_putstr_clr(LIGHT_GREEN, "Colour mode enabled.\n");
		else
			ft_putstr_clr(LIGHT_RED, "Colour mode requires -v to be set.\n");
	}	
}
