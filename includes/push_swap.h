/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 10:03:43 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/12 10:04:13 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H_
# define PUSH_SWAP_H_
# include "stack.h"
# include <stdlib.h>
# include <unistd.h>

void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_s(t_stack *a, t_stack *b);
void	push_a(t_stack *a, t_stack *b);
void	push_b(t_stack *a, t_stack *b);
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_r(t_stack *a, t_stack *b);
void	revrotate_a(t_stack *a);
void	revrotate_b(t_stack *b);
void	revrotate_r(t_stack *a, t_stack *b);
void	print_stacks(t_stack *a, t_stack *b);

#endif
