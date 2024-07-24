/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 19:34:13 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 19:01:18 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	swap(t_stack *s, char ab)
{
	int	tmp;

	tmp = s->stack[(s->front + 1) % s->size];
	s->stack[(s->front + 1) % s->size] = s->stack[(s->front + 2) % s->size];
	s->stack[(s->front + 2) % s->size] = tmp;
	if (ab == 'a')
		ft_putstr_fd("sa\n", 1);
	if (ab == 'b')
		ft_putstr_fd("sb\n", 1);
}

int	push(t_ab *ab, char c)
{
	if (c == 'a')
	{
		if (!is_empty(ab->b))
		{
			add_front(ab->a, pop_front(ab->b));
			ft_putstr_fd("pa\n", 1);
			return (1);
		}
	}
	if (c == 'b')
	{
		if (!is_empty(ab->a))
		{
			add_front(ab->b, pop_front(ab->a));
			ft_putstr_fd("pb\n", 1);
			return (1);
		}
	}
	return (0);
}

void	rotate(t_stack *s, char c)
{
	add_rear(s, pop_front(s));
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rev_rotate(t_stack *s, char c)
{
	add_front(s, pop_rear(s));
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	ss(t_ab *ab)
{
	swap(ab->a, 0);
	swap(ab->b, 0);
	ft_putstr_fd("ss\n", 1);
}
