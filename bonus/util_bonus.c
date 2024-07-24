/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:21:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 22:07:30 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap_bonus.h"

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
