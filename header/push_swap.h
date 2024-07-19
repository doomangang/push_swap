/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:21:09 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/19 21:06:00 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

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
int		free_arr(char **arr);
void	print_error(void);
size_t	s_cnt(const char *str, char chr);
int		my_atoi(char *str, int *flag);
int		sorted(int *num, int size);
void	init(int *num, int size);
void	under_five(int *num, int size);
int		init_ab(t_ab *ab, int *arr, int size);
void	swap(t_stack *s, char ab);
void	rotate(t_stack *s, char c);
void	rev_rotate(t_stack *s, char c);
void	push(t_ab *ab, char c);
int		is_empty(t_stack *s);
int		is_full(t_stack *s);
void	delete_ab(t_ab *ab);
void	add_front(t_stack *s, int val);
void	add_rear(t_stack *s, int val);
int		pop_front(t_stack *s);
int		pop_rear(t_stack *s);

#endif