/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:21:09 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/24 19:05:25 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
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
int		my_atoi(char *str, int *flag);
int		init_ab(t_ab *ab, int *arr, int size);
void	under_five(t_ab *ab, int size);
void	sort_three(t_stack *s);
int		*sort(t_stack *s);
int		sorted(int *num, int size);
int		convert(t_ab *ab);
void	copy(t_stack *s, int *t);
void	push_swap(t_ab *ab, int *num, int size);
void	a_to_b(t_ab *ab, int ch);
void	b_to_a(t_ab *b);
void	swap(t_stack *s, char ab);
void	ss(t_ab *ab);
void	rotate(t_stack *s, char c);
void	rr(t_ab *ab);
void	rev_rotate(t_stack *s, char c);
void	rrr(t_ab *ab);
int		push(t_ab *ab, char c);
int		is_empty(t_stack *s);
int		is_full(t_stack *s);
void	delete_ab(t_ab *ab);
void	add_front(t_stack *s, int val);
void	add_rear(t_stack *s, int val);
int		pop_front(t_stack *s);
int		pop_rear(t_stack *s);
int		get_front(t_stack *s);
int		get_rear(t_stack *s);
int		get_max(t_stack *s);

#endif