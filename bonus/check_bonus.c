/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:31:19 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 22:08:24 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

void	check(char *num, int size)
{
	t_ab	*ab;
	char	**inst;
	int		chunk;

	ab = (t_ab *)malloc(sizeof(t_ab));
	if (!ab)
		return (free(num));
	if (!init_ab(ab, num, size))
		return ;
	if (!convert(ab))
		return (delete_ab(ab));
	inst = get_inst();
	op(inst, ab);
	if (!sorted_ab(ab))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	delete_ab(ab);
}

int	init_ab(t_ab *ab, int *arr, int size)
{
	ab->a = (t_stack *)malloc(sizeof(t_stack));
	ab->b = (t_stack *)malloc(sizeof(t_stack));
	if (ab->a && ab->b)
	{
		ab->size = size + 1;
		ab->a->stack = arr;
		ab->b->stack = (int *)malloc(sizeof(int) * (size + 1));
		if (ab->b)
		{
			ab->a->front = 0;
			ab->a->rear = size;
			ab->b->front = 0;
			ab->b->rear = 0;
			ab->a->size = size + 1;
			ab->b->size = size + 1;
			return (1);
		}
	}
	free(ab->b->stack);
	free(ab->b);
	free(ab->a);
	free(ab);
	return (0);
}
