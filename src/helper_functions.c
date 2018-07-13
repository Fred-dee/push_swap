/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 14:37:20 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/12 14:37:24 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	t_list	*head_a;
	t_list	*head_b;
	int		*tmp_a;
	int		*tmp_b;

	tmp_a = (int *)malloc(sizeof(int));
	tmp_b = (int *)malloc(sizeof(int));
	head_a = ft_stacktop(a);
	head_b = ft_stacktop(b);
	while (head_b != NULL || head_a != NULL)
	{
		if(head_a != NULL)
		{
			tmp_a = (int *)head_a->content;
			ft_putnbr(*tmp_a);
			ft_putchar(' ');
			head_a = head_a->next;
		}
		ft_putchar(' ');
		if(head_b != NULL)
		{
			tmp_b = (int *)head_b->content;
			ft_putnbr(*tmp_b);
			head_b = head_b->next;
		}
		ft_putchar('\n');
	}
	ft_putendl("_ _");
	ft_putendl("a b");
}

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