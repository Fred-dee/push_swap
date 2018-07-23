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

void	print_single(char const *colour, t_list *head, int value)
{
	ft_putnbr_clr(colour, value);
	if(head != NULL)
		ft_putchar('\t');
	else
		ft_putchar('\n');
}
