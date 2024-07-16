/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:45:26 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/16 21:47:21 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	push_swap(t_ab *ab, int *num, int size)
{
	if (size <= 5)
	{
		under_five(num, size);
		return ;
	}
	if (!init_stack(&ab, num, size))
		return ;
}

void	under_five(int *num, int size)
{
	
}