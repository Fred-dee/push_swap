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
