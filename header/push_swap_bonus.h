/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:04:48 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/07/26 04:54:14 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"

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
int		*sort(t_stack *s);
void	copy(t_stack *s, int *t);
void	check(int *num, int size);
void	execute(char *line, t_ab *ab);
int		str_cmp(char *s1, char *s2);
int		convert(t_ab *ab);
int		sorted_ab(t_stack *s);
int		init_ab(t_ab *ab, int *arr, int size);
int		my_atoi(char *str, int *flag);
int		free_arr(char **arr);
void	print_error(void);
void	delete_ab(t_ab *ab);
int		is_empty(t_stack *s);
void	rr(t_ab *ab);
void	rrr(t_ab *ab);
void	swap(t_ab *ab, char c);
int		push(t_ab *ab, char c);
void	rotate(t_ab *ab, char c);
void	rev_rotate(t_ab *ab, char c);
void	ss(t_ab *ab);
void	add_front(t_stack *s, int val);
void	add_rear(t_stack *s, int val);
int		pop_front(t_stack *s);
int		pop_rear(t_stack *s);
int		get_front(t_stack *s);

#endif