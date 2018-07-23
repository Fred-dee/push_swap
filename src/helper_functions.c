/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:15:43 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/23 11:12:35 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*stack_min(t_stack *s)
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
			if (*((int *)tmp->content) < *((int *)ret->content))
				ret = tmp;
			tmp = tmp->next;
		}
	}
	return (ret);
}

int		is_sorted_desc(t_list *head)
{
	t_list	*tmp;
	t_list	*prev;
	int		*x;
	int		*y;

	tmp = head;
	if (tmp == NULL)
		return (TRUE);
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		x = (int *)prev->content;
		y = (int *)tmp->content;
		if (*x < *y)
			return (FALSE);
	}
	return (TRUE);
}

int		is_sorted(t_list *head)
{
	t_list	*tmp;
	t_list	*prev;
	int		*x;
	int		*y;

	tmp = head;
	if (tmp == NULL)
		return (TRUE);
	while (tmp->next != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		x = (int *)prev->content;
		y = (int *)tmp->content;
		if (*x > *y)
			return (FALSE);
	}
	return (TRUE);
}

int		duplicates(int ac, long arr[])
{
	int	tmp;
	int	i;

	tmp = 0;
	while (tmp < ac - 1)
	{
		i = tmp + 1;
		while (i <= ac)
		{
			if (arr[tmp] == arr[i++])
				return (FALSE);
		}
		tmp++;
	}
	return (TRUE);
}

int		is_valid(int ac, char *av[])
{
	int		tmp;
	char	*str;
	long	arr[ac];

	tmp = ac;
	while (tmp >= 0)
	{
		str = av[tmp];
		if (*str == '-' || *str == '+')
			str++;
		while (*str != '\0')
		{
			if (ft_isdigit(*str) == FALSE)
				return (FALSE);
			str++;
		}
		arr[tmp] = ft_atol(av[tmp]);
		if (arr[tmp] > MAX_INT || arr[tmp] < MIN_INT)
			return (FALSE);
		tmp--;
	}
	return (duplicates(ac, arr));
}
