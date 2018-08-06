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

t_list	*stack_min_range(t_stack *s, int range)
{
	t_list *tmp;
	t_list *ret;
	int		i;

	ret = NULL;
	i = 0;
	if (s != NULL)
	{
		tmp = s->head;
		ret = tmp;
		while (tmp != NULL && i < range)
		{
			i++;
			if (*((int *)tmp->content) < *((int *)ret->content))
				ret = tmp;
			tmp = tmp->next;
		}
	}
	return (ret);
}

t_list *list_max_range(t_list *lst, int range)
{
	t_list	*tmp;
	t_list	*ret;
	int		i;

	ret = NULL;
	i = 0;
	if(lst != NULL)
	{
		tmp = lst;
		ret = tmp;
		while (tmp != NULL && i < range)
		{
			i++;
			if (*((int *)tmp->content) > *((int *)ret->content))
				ret = tmp;
			tmp = tmp->next;
		}
	}
	return (ret);
}

t_list *list_min_range(t_list *lst, int range)
{
	t_list	*tmp;
	t_list	*ret;
	int		i;

	ret = NULL;
	i = 0;
	if(lst != NULL)
	{
		tmp = lst;
		ret = tmp;
		while (tmp != NULL && i < range)
		{
			i++;
			if (*((int *)tmp->content) < *((int *)ret->content))
				ret = tmp;
			tmp = tmp->next;
		}
	}
	return (ret);
}

t_list	*stack_max_range(t_stack *s, int range)
{
	t_list *tmp;
	t_list *ret;
	int		i;

	ret = NULL;
	i = 0;
	if (s != NULL)
	{
		tmp = s->head;
		ret = tmp;
		while (tmp != NULL && i < range)
		{
			i++;
			if (*((int *)tmp->content) > *((int *)ret->content))
				ret = tmp;
			tmp = tmp->next;
		}
	}
	return (ret);
}
