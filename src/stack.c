/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:08:29 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/16 22:10:12 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	init_stack(t_ab *ab, int *arr, int size)
{
	ab = (t_ab *)malloc(sizeof(t_ab));
	if (!ab)
		return (0);
	ab->a = (t_stack *)malloc(sizeof(t_stack));
	ab->b = (t_stack *)malloc(sizeof(t_stack));
	if (!ab->a || !ab->b)
	{
		free(ab->a);
		free(ab->b);
		free(ab);
		return (0);
	}
	ab->b->stack = (int *)malloc(sizeof(int) * size);
	if (!ab->b->stack)
	{
		free(ab->a);
		free(ab->b);
		free(ab);
	}
	ab->a->stack = arr;
	ab->size = size;
	ab->a->front = 0;
	ab->b->rear = size - 1;
	ab->b->front = 0;
	ab->b->rear = 0;
}


