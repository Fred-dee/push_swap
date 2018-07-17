/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:07:46 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/16 15:07:49 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swapnfree(char **var, char *new_val)
{
	char	*tmp;

	free(*var);
	tmp = new_val;
	*var = tmp;
}

int		char_count(const char *s, char c)
{
	char	*tmp;
	int		ret;

	tmp = (char *)s;
	ret = 0;
	while(*tmp != '\0')
	{
		if(*tmp == c)
			ret++;
		tmp++;
	}
	return (ret);
}

t_list	*stack_max(t_stack *s)
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
			if (*((int *)tmp->content) > *((int *)ret->content))
				ret = tmp;
			tmp = tmp->next;
		}
	}
	return (ret);
}