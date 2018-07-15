/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdilapi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 11:06:36 by mdilapi           #+#    #+#             */
/*   Updated: 2018/07/12 11:06:40 by mdilapi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int main(int ac, char *av[])
{
	int tmp;
	int *x;
	t_stack *a;
	t_list *head;

	if (ac > 1)
	{
		printf("I am in my main\n");
		x = (int *)malloc(sizeof(int));
		a = ft_stacknew(NULL, 0);
		tmp = ac -1;
		while (tmp > 0)
		{
			*x = ft_atoi(av[tmp--]);
			ft_stackpush(a, ft_lstnew(x, sizeof(x)));
		}
		head = ft_stacktop(a);
		if (head == NULL)
			printf("there was nothing pushed to my stack");
		else
			printf("heres the stack without any functions applied\n");
		while(head != NULL)
		{
			x = (int *)head->content;
			printf("%d\n", *x);
			head = head->next;
		}
		printf("heres the stack after ft_stackrotate\n");
		ft_stackrotate(a);
		head =  ft_stacktop(a);
		while(head != NULL)
		{
			x = (int *)head->content;
			printf("%d\n", *x);
			head = head->next;
		}
		printf("heres the stack after ft_stackrevrotate\n");
		ft_stackrevrotate(a);
		head = ft_stacktop(a);
		while(head != NULL)
		{
			x = (int *)head->content;
			printf("%d\n", *x);
			head = head->next;
		}
		printf("heres the stack after ft_stack_swap_top\n");
		ft_stack_swap_top(a);
		head = ft_stacktop(a);
		while(head != NULL)
		{
			x = (int *)head->content;
			printf("%d\n", *x);
			head = head->next;
		}
		printf("Here is the max of the struct\n");
		head = ft_stackmax(a, &int_cmp);
		x = (int *)head->content;
		printf("%d\n", *x);
	}
}
