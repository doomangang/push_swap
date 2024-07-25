/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:31:19 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 03:21:29 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

void	check(int *num, int size)
{
	t_ab	*ab;

	ab = (t_ab *)malloc(sizeof(t_ab));
	if (!ab)
		return (free(num));
	if (!init_ab(ab, num, size))
		return ;
	if (!convert(ab))
		return (delete_ab(ab));
	if(!operate(ab))
		return (delete_ab(ab));
	if (!is_empty(ab->b) || !sorted_ab(ab->a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	delete_ab(ab);
}

int	operate(t_ab *ab)
{
	t_inst	*head;
	t_inst	*ptr;

	head = (t_inst *)malloc(sizeof(t_inst));
	if (!head)
		return (0);
	ptr = head;
	ptr->inst = get_next_line(0);
	ptr->next = 0;
	ptr->head = head;
	while (ptr->inst)
	{
		ptr->next = (t_inst *)malloc(sizeof(t_inst));
		if (!ptr->next)
			return (clear_inst(head));
		ptr = ptr->next;
		ptr->head = head;
		ptr->inst = get_next_line(0);
		ptr->next = NULL;
	}
	ptr = head;
	while (execute(ptr, ab))
		ptr = ptr->next;
	clear_inst(head);
	return (1);
}

int	execute(t_inst *ptr, t_ab *ab)
{
	if (!ptr->inst)
		return (0);
	if (!str_cmp(ptr->inst, "sa\n") || !str_cmp(ptr->inst, "sb\n"))
		swap(ab, ptr->inst[1]);
	else if (!str_cmp(ptr->inst, "ss\n"))
		ss(ab);
	else if (!str_cmp(ptr->inst, "pa\n") || !str_cmp(ptr->inst, "pb\n"))
		push(ab, ptr->inst[1]);
	else if (!str_cmp(ptr->inst, "ra\n") || !str_cmp(ptr->inst, "rb\n"))
		rotate(ab, ptr->inst[1]);
	else if (!str_cmp(ptr->inst, "rr\n"))
		rr(ab);
	else if (!str_cmp(ptr->inst, "rra\n") || !str_cmp(ptr->inst, "rrb\n"))
		rev_rotate(ab, ptr->inst[2]);
	else if (!str_cmp(ptr->inst, "rrr\n"))
		rrr(ab);
	else
	{
		delete_ab(ab);
		clear_inst(ptr->head);
		print_error();
	}
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

int	sorted_ab(t_stack *s)
{
	int	idx;
	int	f;
	int	r;
	int size;

	idx = 1;
	f = s->front;
	r = s->rear;
	size = s->size;
	while ((f + idx) % size != r)
	{
		if (s->stack[(f + idx) % size] > s->stack[(f + idx + 1) % size])
			return (0);
		idx++;
	}
	return (1);
}
