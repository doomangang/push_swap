/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 19:06:08 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 20:52:04 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	is_valid(int sign, int itgr, char *str)
{
	if (!ft_isdigit(*str))
		return (0);
	if (sign == 1 && itgr > IMAX / 10)
		return (0);
	if (sign == 1 && itgr * 10 > IMAX - *str + '0')
		return (0);
	if (sign == -1 && -1 * itgr < IMIN / 10)
		return (0);
	if (sign == -1 && itgr * -10 < IMIN + *str - '0')
		return (0);
	return (1);
}

int	my_atoi(char *str, int *flag)
{
	int		sign;
	int		itgr;

	sign = 1;
	itgr = 0;
	*flag = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (is_valid(sign, itgr, str))
			itgr = itgr * 10 + *str - '0';
		else
			return (0);
		str++;
	}
	*flag = 0;
	return (sign * itgr);
}

int	*sort(t_stack *s)
{
	int	index;
	int	cmp;
	int	temp;
	int	*tab;

	tab = (int *)malloc(sizeof(int) * (s->size - 1));
	if (!tab)
		return (0);
	copy(s, tab);
	index = -1;
	while (++index < s->size - 2)
	{
		cmp = index;
		while (++cmp < s->size - 1)
		{
			if (tab[index] > tab[cmp])
			{
				temp = tab[cmp];
				tab [cmp] = tab[index];
				tab[index] = temp;
			}
		}
	}
	return (tab);
}

void	copy(t_stack *s, int *t)
{
	int	index;

	index = -1;
	while (++index != s->size - 1)
	{
		t[index] = s->stack[(s->front + index + 1) % s->size];
	}
}

int	sorted(int *num, int size)
{
	int	idx;
	int	cmp;

	idx = 0;
	while (++idx < size)
	{
		cmp = idx;
		while (++cmp < size + 1)
		{
			if (num[idx] == num[cmp])
			{
				free(num);
				print_error();
			}
		}
	}
	idx = 1;
	while (idx != size)
	{
		if (num[idx] > num[idx + 1])
			return (0);
		idx++;
	}
	free(num);
	return (1);
}
