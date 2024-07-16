/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:21:00 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/16 21:46:48 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	main(int ac, char **av)
{
	int		*num;
	int		size;
	t_ab	ab;
	char	**tmp;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		if (s_cnt(av[1], ' ') == 1)
			return (0);
		tmp = ft_split(av[1], ' ');
		num = get_num(tmp, &size);
		free_arr(tmp);
	}
	else
		num = get_num(++av, &size);
	if (!num)
		print_error();
	push_swap(&ab, num, size);
	free(num);
	num = NULL;
	return (0);
}

int	*get_num(char **av, int *size)
{
	int	idx;
	int	flag;
	int	*arr;

	*size = count_height(av);
	arr = (int *)malloc(sizeof(int) * *size);
	if (!arr)
		return (0);
	idx = 0;
	while (idx != *size)
	{
		arr[idx] = my_atoi(av[idx], &flag);
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

int	free_arr(char **arr)
{
	int	row;

	row = 0;
	while (arr[row])
	{
		free(arr[row]);
		arr[row] = 0;
		row++;
	}
	free(arr);
	arr = 0;
	return (0);
}

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
