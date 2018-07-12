/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:30:54 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/12 13:31:17 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int		is_valid(int ac, char *av[])
{
	int		tmp;
	char	*str;
	int		arr[ac - 1];
	int		i;

	tmp = ac - 1;
	while (tmp > 0)
	{
		str = av[tmp];
		while(*str != '\0')
		{
			if(ft_isdigit(*str) == FALSE)
				return (FALSE);
			str++;
		}
		arr[tmp - 1] = ft_atoi(av[tmp]);
		tmp--; 
	}
	tmp = 0;
	while (tmp < ac - 2)
	{
		i = tmp + 1;
		while (i < ac - 1)
			if(arr[tmp] == arr[i++])
				return (FALSE);
		tmp++;
	}
	return (TRUE);
}

int		main(int ac, char *av[])
{
	t_stack *a;
	t_stack *b;

	if (ac > 1)
	{
		if(is_valid(ac, av) == FALSE)
		{
			ft_putendl("Error");
		}
		else
		{
			b = ft_stacknew(NULL, 0);
			(void)a;
		}
	}
	return (0);
}
