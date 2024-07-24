/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:51:15 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 22:11:07 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	get_max(t_stack *s)
{
	int	count;
	int	m_val;
	int	m_idx;

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

int	get_rear(t_stack *s)
{
	return (s->stack[s->rear]);
}

void	rr(t_ab *ab)
{
	rotate(ab->a, 0);
	rotate(ab->b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_ab *ab)
{
	rev_rotate(ab->a, 0);
	rev_rotate(ab->b, 0);
	ft_putstr_fd("rrr\n", 1);
}
