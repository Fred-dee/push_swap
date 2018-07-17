/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 12:13:45 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/09 12:13:46 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"
# define TRUE 1
# define FALSE 0

typedef struct	s_stack
{
	t_list		*head;
	size_t		size;
}				t_stack;

t_list			*ft_stacktop(t_stack *s);
void			ft_stackdel(t_stack *s);
int				ft_stackempty(t_stack *s);
size_t			ft_stacksize(t_stack *s);
void			ft_stackpush(t_stack *s, t_list *elem);
t_list			*ft_stackpop(t_stack *s);
t_stack			*ft_stacknew(void const *content, size_t content_size);
t_stack			*ft_stackdup(t_stack *s);
void			ft_stack_swap_top(t_stack *s);
void			ft_stackrotate(t_stack *s);
void			ft_stackrevrotate(t_stack *s);
#endif
