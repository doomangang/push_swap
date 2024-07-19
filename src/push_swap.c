/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:45:26 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/19 20:23:30 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	init(int *num, int size)
{
	t_ab	*ab;

	if (size <= 5)
	{
		under_five(num, size);
		return ;
	}
	ab = (t_ab *)malloc(sizeof(t_ab));
	if (!ab)
		return ;
	if (!init_ab(ab, num, size))
		return ;
	delete_ab(ab);
}

void	under_five(int *num, int size)
{
	if (size > 5)
		num++;
	free(num);
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
