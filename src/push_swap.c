/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:21:00 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/15 16:30:08 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	int	num[500];
	int size;
	t_ab	ab;

	if (ac < 2)
		return (0);
	else
	{
		size = get_num(av, num);
		if (size < 2)
			return (0);
		init_stack(ab, num, size);
	}
}
