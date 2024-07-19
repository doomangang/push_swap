/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:45:26 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/19 23:12:08 by jihyjeon         ###   ########.fr       */
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
	delete_ab(ab);
}

void	under_five(t_ab *ab, int size)
{
	int mid;
	int	idx;

	mid = sort(ab->a->stack, size);
	idx = 1;
	while (idx != size - 3)
	{
		if (ab->a->stack[ab->a->rear] > mid)
		{
			rev_rotate(ab->a, 'a');
			push(ab, 'b');
			idx++;
		}
		if (ab->a->stack[ab->a->front] <= mid)
			rotate(ab->a, 'a');
		if (ab->a->stack[ab->a->front] > mid)
		{
			push(ab, 'b');
			idx++;
		}
	}
	if (ab->a->stack[ab->a->front] == mid)
		rotate(ab->a, 'a');
	if (ab->a->stack[ab->a->front] < ab->a->stack[ab->a->front + 1 % ab->size])
		swap(ab->a, 'a');
	if (!is_empty(ab->b) && ab->b->stack[ab->b->front] > ab->b->stack[ab->b->rear])
		rotate(ab->b, 'b');
	push(ab, 'a');
	rotate(ab->a, 'a');
	push(ab, 'a');
	rotate(ab->a, 'a');
}

int	sort(int *num, int size)
{
	int	idx;

	idx = 0;
	while (idx != size -1)
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

int	sorted(int *num, int size)
{
	int	idx;

	idx = 0;
	while (idx != size -1)
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
