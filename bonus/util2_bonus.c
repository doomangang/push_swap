/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 02:07:07 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 04:27:20 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

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

void	copy(t_stack *s, int *t)
{
	int	index;

	index = -1;
	while (++index != s->size - 1)
	{
		t[index] = s->stack[(s->front + index + 1) % s->size];
	}
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
