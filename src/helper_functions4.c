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

#include "../includes/push_swap.h"
#include <stdio.h>


void	stack_to_int(t_stack *s, int arr[][2])
{
	t_list	*tmp;
	int		i;

	if (s != NULL && s->head != NULL)
	{
		tmp = s->head;
		i = 0;
		while (tmp != NULL)
		{
			arr[i][0] = *((int *)tmp->content);
			arr[i][1] = 0;
			tmp = tmp->next;
			i++;
		}	
	}
}

void	rank_arr(int arr[][2], int size)
{
	int		*tmp;
	int		i;
	int		j;
	int		hold;
	int		flag;

	tmp = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		tmp[i] = arr[i][0];
		i++;
	}
	i = 0;
	while (i < size -1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp[i] > tmp[j])
			{
				hold = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = hold;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < size)
	{
		j = 0;
		flag = 0;
		while (j < size && flag == 0)
		{
			if (arr[i][0] == tmp[j])
			{
				arr[i][1] = j;
				flag = 1;
			}
			j++;
		}
		i++;
	}
	free(tmp);
}

int		get_rank(int arr[][2], int size, int elem)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (elem == arr[i][0])
			return (arr[i][1]);
		i++;
	}
	return (-1);
}

int		get_elem_atrank(int arr[][2], int size, int rank)
{
	int i;

	i = 0;
	while (i < size && rank < size)
	{
		if (rank == arr[i][1])
			return (arr[i][0]);
		i++;
	}
	return (-1);
}

void	free_split(char **arr)
{
	int i;

	if(arr != NULL)
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
				*((int *)tmp->content) < *((int *)ret->content) )
				ret = tmp;
			tmp = tmp->next;
			//printf("stuck in stack_minnext\n");
		}
	}
	return (ret);
}
