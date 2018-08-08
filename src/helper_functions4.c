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
}
