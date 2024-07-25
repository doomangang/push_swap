/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:06:46 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 02:46:39 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

int main(int ac, char **av)
{
	int		*num;
	int		size;
	char	**tmp;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		num = get_num(tmp, &size);
		free_arr(tmp);
	}
	else
		num = get_num(++av, &size);
	if (!num)
		print_error();
	dup_check(num, size);
	check(num, size);
	return (0);
}

int	*get_num(char **av, int *size)
{
	int	idx;
	int	flag;
	int	*arr;

	*size = count_height(av);
	if (!*size)
		return (0);
	arr = (int *)malloc(sizeof(int) * (*size + 1));
	if (!arr)
		return (0);
	idx = 1;
	while (idx != *size + 1)
	{
		arr[idx] = my_atoi(av[idx - 1], &flag);
		if (flag)
		{
			free(arr);
			return (0);
		}
		idx++;
	}
	return (arr);
}

int	count_height(char **arr)
{
	int		idx;
	int		cnt;

	idx = 0;
	cnt = 0;
	while (arr[idx] != NULL)
	{
		idx++;
		cnt++;
	}
	return (cnt);
}

void	dup_check(int *num, int size)
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
}
