/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:31:19 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 04:51:23 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

void	check(int *num, int size)
{
	t_ab	*ab;
	char	*line;

	ab = (t_ab *)malloc(sizeof(t_ab));
	if (!ab)
		return (free(num));
	if (!init_ab(ab, num, size))
		return ;
	if (!convert(ab))
		return (delete_ab(ab));
	line = get_next_line(0);
	while (line)
	{
		execute(line, ab);
		free(line);
		line = get_next_line(0);
	}
	if (!is_empty(ab->b) || !sorted_ab(ab->a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	delete_ab(ab);
}

void	execute(char *line, t_ab *ab)
{
	if (!str_cmp(line, "sa\n") || !str_cmp(line, "sb\n"))
		swap(ab, line[1]);
	else if (!str_cmp(line, "ss\n"))
		ss(ab);
	else if (!str_cmp(line, "pa\n") || !str_cmp(line, "pb\n"))
		push(ab, line[1]);
	else if (!str_cmp(line, "ra\n") || !str_cmp(line, "rb\n"))
		rotate(ab, line[1]);
	else if (!str_cmp(line, "rr\n"))
		rr(ab);
	else if (!str_cmp(line, "rra\n") || !str_cmp(line, "rrb\n"))
		rev_rotate(ab, line[2]);
	else if (!str_cmp(line, "rrr\n"))
		rrr(ab);
	else
	{
		delete_ab(ab);
		free(line);
		print_error();
	}
}

int	str_cmp(char *s1, char *s2)
{
	unsigned char	*one;
	unsigned char	*two;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (*two)
	{
		if (*one != *two)
			return (*(unsigned char *)one - *(unsigned char *)two);
		one++;
		two++;
	}
	return (*(unsigned char *)(one - 1) - *(unsigned char *)(two - 1));
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
	int	size;

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
