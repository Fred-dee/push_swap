#include "../includes/push_swap.h"
#include <stdio.h>

/*
int		**stack_to_int(t_stack *s)
{
	t_list	*tmp;
	int		**ret;
	int		i;

	if (s != NULL && s->head != NULL)
	{
		if((ret = (int **)malloc(sizeof(int *) * s->size)) != NULL)
		{
			tmp = s->head;
			i = 0;
			while (tmp != NULL)
			{
				ret[i] = 
			}


		}	
	}

} */

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

int main(void)
{
	int arr[6][2];
	int **pointer;

	arr[0][0] = 34;
	arr[1][0] = 3;
	arr[2][0] = 31;
	arr[3][0] = 98;
	arr[4][0] = 92;
	arr[5][0] = 23;

	rank_arr(arr, 6);
	for (int i = 0; i < 6; i++)
		printf("value: %d rank: %d\n", arr[i][0],arr[i][1]);
}