/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 00:40:21 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 00:40:42 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

void	add_front(t_stack *s, int val)
{
	s->stack[s->front] = val;
	s->front = (s->front - 1 + s->size) % s->size;
}

void	add_rear(t_stack *s, int val)
{
	s->rear = (s->rear + 1) % s->size;
	s->stack[s->rear] = val;
}

int	pop_front(t_stack *s)
{
	s->front = (s->front + 1) % s->size;
	return (s->stack[s->front]);
}

int	pop_rear(t_stack *s)
{
	int	prev;

	prev = s->rear;
	s->rear = (s->rear - 1 + s->size) % s->size;
	return (s->stack[prev]);
}

int	get_front(t_stack *s)
{
	return (s->stack[(s->front + 1) % s->size]);
}
