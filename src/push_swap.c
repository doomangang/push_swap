/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:00:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/23 23:01:26 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_swap(t_ab *ab)
{
	int	chunk;
	int	sz;

	sz = ab->size - 1;
	chunk = 0.000000053 * sz * sz + 0.03 * sz + 14.5;
	a_to_b(ab, chunk);
	b_to_a(ab);
}

void	a_to_b(t_ab *ab, int ch)
{
	int	i;

	i = 0;
	while (i != ab->size - 1)
	{
		if (get_front(ab->a) <= i)
		{
			push(ab, 'b');
			i++;
		}
		else if (get_front(ab->a) > i && get_front(ab->a) <= i + ch)
		{
			push(ab, 'b');
			rotate(ab->b, 'b');
			i++;
		}
		else if (get_front(ab->a) > i + ch)
			rotate(ab->a, 'a');
	}
}

void	b_to_a(t_ab *ab)
{
	int	max;
	int	size;

	size = ab->b->size - 1;
	while (size != 0)
	{
		max = get_max(ab->b);
		if (max <= size / 2)
		{
			while (--max > 0)
				rotate(ab->b, 'b');
		}
		else
		{
			while (max++ < size)
				rev_rotate(ab->b, 'b');
			rev_rotate(ab->b, 'b');
		}
		push(ab, 'a');
		size--;
	}
}

int	get_max(t_stack *s)
{
	int	count;
	int m_val;
	int m_idx;

	count = 1;
	m_val = 0;
	m_idx = 1;
	while ((count + s->front) % s->size != (s->rear + 1) % s->size)
	{
		if (s->stack[(count + s->front) % s->size] > m_val)
		{
			m_idx = count;
			m_val = s->stack[(count + s->front) % s->size];
		}
		count++;
	}
	return (m_idx);
}
