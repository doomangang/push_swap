/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:04:48 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 22:09:44 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define IMAX 2147483647
# define IMIN -2147483648

typedef struct s_stack
{
	int	*stack;
	int	front;
	int	rear;
	int	size;
}		t_stack;

typedef struct s_ab
{
	t_stack	*a;
	t_stack	*b;
	int		size;
}			t_ab;

int		*get_num(char **av, int *size);
int		count_height(char **arr);
void	dup_check(int *num, int size);
int		sorted(int *num, int size);
void	check(char *num, int size);
int		init_ab(t_ab *ab, int *arr, int size);
int		my_atoi(char *str, int *flag);
int		free_arr(char **arr);
void	print_error(void);
