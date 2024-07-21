/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 02:00:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/21 11:08:41 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_swap(t_ab *ab)
{
	int	num;
	int	chunk;

	if (!convert(ab))
		return ;
}

int	convert(t_ab *ab)
{
	int	*new;
	int	i;
	int	j;

	new = (int *)malloc(sizeof(int) * (ab->size - 1));
	if (!new)
		return (0);
	quick_sort(ab->a->stack, new);
	i = 0;
	while (i != ab->size)
	{
		j = 0;
		while (j != ab->size)
		{
			if (new[i] == ab->a->stack[j])
				;
		}
	}
}
