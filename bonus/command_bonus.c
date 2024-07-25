/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 23:50:21 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 02:29:00 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

void	swap(t_ab *ab, char c)
{
	int		tmp;
	t_stack	*s;

	if (c == 'a')
		s = ab->a;
	if (c == 'b')
		s = ab->b;
	tmp = s->stack[(s->front + 1) % s->size];
	s->stack[(s->front + 1) % s->size] = s->stack[(s->front + 2) % s->size];
	s->stack[(s->front + 2) % s->size] = tmp;
}

int	push(t_ab *ab, char c)
{
	if (c == 'a')
	{
		if (!is_empty(ab->b))
		{
			add_front(ab->a, pop_front(ab->b));
			return (1);
		}
	}
	if (c == 'b')
	{
		if (!is_empty(ab->a))
		{
			add_front(ab->b, pop_front(ab->a));
			return (1);
		}
	}
	return (0);
}

void	rotate(t_ab *ab, char c)
{
	t_stack	*s;

	if (c == 'a')
		s = ab->a;
	if (c == 'b')
		s = ab->b;
	add_rear(s, pop_front(s));
}

void	rev_rotate(t_ab *ab, char c)
{
	t_stack	*s;

	if (c == 'a')
		s = ab->a;
	if (c == 'b')
		s = ab->b;
	add_front(s, pop_rear(s));
}

void	ss(t_ab *ab)
{
	swap(ab, 'a');
	swap(ab, 'b');
}
