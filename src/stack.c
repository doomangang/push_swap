/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:08:29 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 22:11:15 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	init_ab(t_ab *ab, int *arr, int size)
{
	ab->a = (t_stack *)malloc(sizeof(t_stack));
	ab->b = (t_stack *)malloc(sizeof(t_stack));
	if (ab->a && ab->b)
	{
		ab->size = size + 1;
		ab->a->stack = arr;
		ab->b->stack = (int *)malloc(sizeof(int) * (size + 1));
		if (ab->b)
		{
			ab->a->front = 0;
			ab->a->rear = size;
			ab->b->front = 0;
			ab->b->rear = 0;
			ab->a->size = size + 1;
			ab->b->size = size + 1;
			return (1);
		}
	}
	free(ab->b->stack);
	free(ab->b);
	free(ab->a);
	free(ab);
	return (0);
}

int	convert(t_ab *ab)
{
	int	*new;
	int	*tmp;
	int	i;
	int	j;

	new = (int *)malloc(sizeof(int) * (ab->size));
	if (!new)
		return (0);
	tmp = sort(ab->a);
	if (!tmp)
		return (0);
	i = -1;
	while (++i != ab->size - 1)
	{
		j = -1;
		while (++j != ab->size)
		{
			if (tmp[i] == ab->a->stack[(ab->a->front + 1 + j) % ab->size])
				new[(ab->a->front + 1 + j) % ab->size] = i;
		}
	}
	free(tmp);
	free(ab->a->stack);
	ab->a->stack = new;
	return (1);
}

int	is_empty(t_stack *s)
{
	return (s->front == s->rear);
}

int	is_full(t_stack *s)
{
	return ((s->rear + 1) % s->size == s->front);
}

void	delete_ab(t_ab *ab)
{
	free(ab->b->stack);
	free(ab->a->stack);
	free(ab->b);
	free(ab->a);
	free(ab);
}
