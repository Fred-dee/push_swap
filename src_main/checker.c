/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 09:02:18 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/13 09:02:21 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	select_move(t_stack *a, t_stack *b, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		swap_a(a);
	else if (ft_strcmp(str, "sb") == 0)
		swap_b(b);
	else if (ft_strcmp(str, "ss") == 0)
		swap_s(a, b);
	else if (ft_strcmp(str, "pa") == 0)
		push_a(a, b);
	else if (ft_strcmp(str, "pb") == 0)
		push_b(a, b);
	else if (ft_strcmp(str, "ra") == 0)
		rotate_a(a);
	else if (ft_strcmp(str, "rb") == 0)
		rotate_b(b);
	else if (ft_strcmp(str, "rr") == 0)
		rotate_r(a, b);
}

static void	read_apply(t_stack *a, t_stack *b, t_flags *f)
{
	char	*str;
	int		read_ret;

	while ((read_ret = get_next_line(0, &str)) > 0)
	{
		select_move(a, b, str);
		if (ft_strcmp(str, "rra") == 0)
			revrotate_a(a);
		else if (ft_strcmp(str, "rrb") == 0)
			revrotate_b(b);
		else if (ft_strcmp(str, "rrr") == 0)
			revrotate_r(a, b);
		else if (ft_strcmp(str, "quit") == 0)
		{
			ft_strdel(&str);
			break ;
		}
		if (f->v == 1 && f->c == 0)
			print_stacks(a, b, str);
		if (f->v == 1 && f->c == 1)
			print_stacks_clr(a, b, str);
		ft_strdel(&str);
	}
	ft_strdel(&str);
}

static int	work(int count, char **av, t_stack *a)
{
	int		*x;

	if (is_valid(count, av) == FALSE)
	{
		ft_putendl_fd("Error", 2);
		return (0);
	}
	else
	{
		x = (int *)malloc(sizeof(int));
		while (count >= 0)
		{
			*x = ft_atoi(av[count--]);
			ft_stackpush(a, ft_lstnew(x, sizeof(x)));
		}
		free(x);
	}
	return (1);
}

static int	parse_content(int ac, char **av, t_flags *flag, t_stack *a)
{
	int		count;
	char	**split;

	if (ac == 2 + flag->offset)
	{
		count = 0;
		split = ft_strsplit(av[1 + flag->offset], ' ');
		while (split[count] != '\0')
			count++;
		if (work(count - 1, split, a) == 0)
			return (0);
		free_split(split);
	}
	else
	{
		split = av + 1 + flag->offset;
		if (work(ac - 2 - flag->offset, split, a) == 0)
			return (0);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	t_flags	flag;

	if (ac > 1)
	{
		b = ft_stacknew(NULL, 0);
		a = ft_stacknew(NULL, 0);
		flag.v = 0;
		flag.c = 0;
		contains_flags(ac - 1, av, &flag);
		flag_check(&flag);
		if (parse_content(ac, av, &flag, a) == 0)
			return (0);
		read_apply(a, b, &flag);
		if (a->head != NULL && is_sorted(a->head) && ft_stackempty(b) == TRUE)
			ft_putendl("OK");
		else
			ft_putendl("KO");
		ft_stackdel(&a);
		ft_stackdel(&b);
	}
	return (0);
}
