/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:45:26 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/23 18:17:55 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	init(int *num, int size)
{
	t_ab	*ab;

	ab = (t_ab *)malloc(sizeof(t_ab));
	if (!ab)
		return ;
	if (!init_ab(ab, num, size))
		return (delete_ab(ab));
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
		push_swap(ab);
	delete_ab(ab);
}

void	under_five(t_ab *ab, int size)
{
	int	idx;

	idx = 0;
	while (idx != size - 3)
	{
		if (get_front(ab->a) > 2)
		{
			push(ab, 'b');
			idx++;
		}
		else if (get_front(ab->a) <= 2)
			rotate(ab->a, 'a');
	}
	sort_three(ab->a);
	if (size > 3)
	{
		if (get_front(ab->a) > ab->b->stack[ab->b->rear])
			rotate(ab->b, 'b');
		push(ab, 'a');
		rotate(ab->a, 'a');
		if (push(ab, 'a'))
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

int	sorted(int *num, int size)
{
	int	idx;

	idx = 1;
	while (idx != size)
	{
		if (num[idx] > num[idx + 1])
			return (0);
		if (num[idx] == num[idx + 1])
		{
			free(num);
			print_error();
		}
		idx++;
	}
	free(num);
	return (1);
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
