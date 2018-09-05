/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 10:57:52 by mdilapi           #+#    #+#             */
/*   Updated: 2018/08/09 10:57:53 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	free_split(char **arr)
{
	int i;

	if (arr != NULL)
	{
		i = 0;
		while (arr[i] != 0)
			free(arr[i++]);
		free(arr[i]);
		free(arr);
	}
	arr = NULL;
}

t_list	*stack_minnext(t_stack *s, t_list *min)
{
	t_list *tmp;
	t_list *ret;

	ret = NULL;
	if (s != NULL)
	{
		tmp = s->head;
		ret = tmp;
		while (tmp != NULL)
		{
			if (*((int *)tmp->content) != *((int *)min->content) &&
				*((int *)tmp->content) < *((int *)ret->content))
				ret = tmp;
			tmp = tmp->next;
		}
	}
	return (ret);
}

t_list	*stack_maxnext(t_stack *s, t_list *max)
{
	t_list *tmp;
	t_list *ret;

	ret = NULL;
	if (s != NULL)
	{
		tmp = s->head;
		ret = tmp;
		while (tmp != NULL)
		{
			if (*((int *)tmp->content) != *((int *)max->content) &&
				*((int *)tmp->content) > *((int *)ret->content))
				ret = tmp;
			tmp = tmp->next;
		}
	}
	return (ret);
}

void	final_rotates(t_stack *b, char **ret)
{
	t_list	*tmp;

	tmp = stack_max(b);
	if (ft_stack_indexof(b, tmp) > (int)b->size / 2)
		while (*(int *)ft_stacktop(b)->content != *(int *)tmp->content)
		{
			revrotate_b(b);
			swapnfree(ret, ft_strjoin(*ret, "rrb\n"));
		}
	else
		while (*(int *)ft_stacktop(b)->content != *(int *)tmp->content)
		{
			rotate_b(b);
			swapnfree(ret, ft_strjoin(*ret, "rb\n"));
		}
}
