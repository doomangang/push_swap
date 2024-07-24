/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:00:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 20:05:00 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_swap(int *num, int size)
{
	t_ab	*ab;
	int		chunk;

	ab = (t_ab *)malloc(sizeof(t_ab));
	if (!ab)
		return (free(num));
	if (!init_ab(ab, num, size))
		return ;
	if (size == 2)
	{
		ft_putstr_fd("sa\n", 1);
		return (delete_ab(ab));
	}
	if (!convert(ab))
		return (delete_ab(ab));
	if (size <= 5)
		under_five(ab, size);
	else
	{
		chunk = 0.000000053 * size * size + 0.03 * size + 14.5;
		a_to_b(ab, chunk);
		b_to_a(ab);
	}
	delete_ab(ab);
}

void	a_to_b(t_ab *ab, int ch)
{
	int	i;

	i = 0;
	while (i != ab->size - 1)
	{
		if (i * 2 < ab->size - 1 && get_rear(ab->a) <= i + ch)
			rev_rotate(ab->a, 'a');
		if (get_front(ab->a) <= i)
		{
			push(ab, 'b');
			i++;
		}
		else if (get_front(ab->a) > i && get_front(ab->a) <= i + ch)
		{
			push(ab, 'b');
			if (get_front(ab->a) > i + ch)
				rr(ab);
			else
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

void	under_five(t_ab *ab, int size)
{
	int	max;

	while (size != 3)
	{
		max = get_max(ab->a);
		if (max <= size / 2 + 1)
		{
			while (--max > 0)
				rotate(ab->a, 'a');
		}
		else
		{
			while (max++ < size + 1)
				rev_rotate(ab->a, 'a');
		}
		push(ab, 'b');
		size--;
	}
	sort_three(ab->a);
	while (!is_empty(ab->b))
	{
		push(ab, 'a');
		rotate(ab->a, 'a');
	}
}

void	sort_three(t_stack *s)
{
	int	a;
	int	b;
	int	c;

	a = s->stack[(s->front + 1) % s->size];
	b = s->stack[(s->front + 2) % s->size];
	c = s->stack[(s->front + 3) % s->size];
	if (a > b && b < c && a < c)
		swap(s, 'a');
	else if (a > b && b > c)
	{
		swap(s, 'a');
		rev_rotate(s, 'a');
	}
	else if (a > b && b < c && a > c)
		rotate(s, 'a');
	else if (a < b && b > c && a < c)
	{
		swap(s, 'a');
		rotate(s, 'a');
	}
	else if (a < b && b > c && a > c)
		rev_rotate(s, 'a');
}
