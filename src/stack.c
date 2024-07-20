/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:08:29 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/20 17:02:16 by jihyjeon         ###   ########.fr       */
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
	free(ab->b);
	free(ab->a);
	free(ab);
}
