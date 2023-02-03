/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:24:00 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/03 19:21:45 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR -3

typedef struct s_division
{
	int	min;
	int	max;
	int	half;
}	t_div;

typedef struct s_big_index
{
	int	a;
	int	b;
}	t_big_i;

typedef struct s_push_swap
{
	int	*sa;
	int	*sb;
	int	*order_cmp;
	int	size_sa;
	int	size_sb;
	int	temp;
}	t_ps;

// utils
void			exit_and_free(t_ps *ps);
int				ft_str_is_numeric(char *str);
void			ft_sort_array(int *tab, int size);
long int		ft_atolongi(const char *nptr);
int				*ft_array_dup(int *arr, int size);
int				ft_strcmp(char *s1, char *s2);
void			*ft_calloc(size_t nmemb, size_t size);

//check.c
int				check_args(int argc, char **argv);
t_ps			*valid_args(int argc, char **argv, t_ps *ps);
void			duplicate(t_ps *ps);
void			change_nb_to_index(t_ps *ps);

// move_s.c
void			move_sa(t_ps *ps);
void			move_sb(t_ps *ps);
void			move_ss(t_ps *ps);

// move_p.c
void			move_pa(t_ps *ps);
void			move_pb(t_ps *ps);

// move_r.c
void			move_ra(t_ps *ps);
void			move_rb(t_ps *ps);
void			move_rr(t_ps *ps);

// move_rr.c
void			move_rra(t_ps *ps);
void			move_rrb(t_ps *ps);
void			move_rrr(t_ps *ps);

// exec_moves.c
void			exec_moves(t_ps *ps, char *move);

// order.c
int				in_order(t_ps *ps);
void			order_three(t_ps *ps);
void			order_five(t_ps *ps);
void			order_hundred(t_ps *ps, int division);
void			order_large_numbers(t_ps *ps);

// best_move.c
char			*best_mov_r_or_rr(t_ps *ps, int *sa, int *sb, \
t_big_i big_index);

// order_hundred.c
void			choice_mov_hundred(t_ps *ps, int range);

// info_portion.c
t_div			info_portion_a(t_ps *ps, t_div portion);
t_div			info_portion_b(t_ps *ps, t_div portion);
t_div			re_info_portion_a(t_ps *ps, t_div portion);

// order_large_numbers.c
void			move_in_portion(char stack, t_ps *ps, t_div portion);

// aux.c
unsigned int	index_low_nb(t_ps *ps);
unsigned int	index_bigger(int *stack, int size_s);
int				near_pos_to_move(int *stack, int stack_size, \
int range, int min_range);
int				find_predecessor_in_b(t_ps *ps, int nb);
void			bigger_to_top(t_ps *ps, unsigned int index_bigger, \
unsigned int size, char stack);

#endif
