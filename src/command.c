/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:51:15 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/19 21:08:12 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ss(t_ab *ab)
{
	swap(ab->a, 0);
	swap(ab->b, 0);
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_ab *ab)
{
	rotate(ab->a, 0);
	rotate(ab->b, 0);
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_ab *ab)
{
	rev_rotate(ab->a, 0);
	rev_rotate(ab->b, 0);
	ft_putstr_fd("rrr\n", 1);
}