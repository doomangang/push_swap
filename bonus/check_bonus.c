/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:31:19 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/25 01:32:51 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

void	check(char *num, int size)
{
	t_ab	*ab;
	char	**inst;

	ab = (t_ab *)malloc(sizeof(t_ab));
	if (!ab)
		return (free(num));
	if (!init_ab(ab, num, size))
		return ;
	if (!convert(ab))
		return (delete_ab(ab));
	inst = get_inst();
	op(inst, ab);
	if (!is_empty(ab->b) || !sorted_ab(ab->a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	delete_ab(ab);
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
