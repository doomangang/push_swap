/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:45:26 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/21 03:49:09 by jihyjeon         ###   ########.fr       */
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
		return ;
	if (size == 2)
		ft_putstr_fd("sa\n", 1);
	if (size <= 5)
		under_five(ab, size);
	// push_swap(ab);
	delete_ab(ab);
}

void	under_five(t_ab *ab, int size)
{
	int mid;
	int	idx;

	mid = sort(ab->a->stack, size);
	idx = 0;
	while (idx != size - 3)
	{
		if (ab->a->stack[(ab->a->front + 1) % ab->size] > mid)
		{
			push(ab, 'b');
			idx++;
		}
		else if (ab->a->stack[(ab->a->front + 1) % ab->size] <= mid)
			rotate(ab->a, 'a');
	}
	sort_three(ab->a);
	if (size > 3)
	{
		if (ab->b->stack[(ab->b->front + 1) % ab->size] > ab->b->stack[ab->b->rear])
			rotate(ab->b, 'b');
		push(ab, 'a');
		rotate(ab->a, 'a');
		if (push(ab, 'a'))
			rotate(ab->a, 'a');
	}
	idx = 0;
	while (idx != size)
	{
		printf("%d\t", ab->a->stack[(ab->a->front + idx + 1) % ab->size]);
		idx++;
	}
	printf("\n");
}

int	sort(int *num, int size)
{
	int	index;
	int	cmp;
	int	temp;
	int	tab[size];

	index = -1;
	while (++index != size)
	{
		tab[index] = num[index + 1];
	}
	index = -1;
	while (++index < size)
	{
		cmp = index;
		while (cmp++ < size - 1)
		{
			if (tab[index] > tab[cmp])
			{
				temp = tab[cmp];
				tab [cmp] = tab[index];
				tab[index] = temp;
			}
		}
	}
	return (tab[2]);
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
