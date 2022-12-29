/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:24:00 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 19:50:41 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <unistd.h> // write
# include <stdlib.h> // malloc, free
# include <stdio.h> // RETIRAR  *   RETIRAR  *   RETIRAR  *   RETIRAR  *   RETIRAR  *

typedef struct	s_push_swap
{
	int	*sa;
	int	*sb;
	int	*order_cmp;
	int	size_sa;
	int	size_sb;
	int	temp;
	int	valid_args;
}	t_ps;

// ./utils
int			ft_str_is_numeric(char *str);
void		ft_sort_array(int *tab, int size);
long int	ft_atolongi(const char *nptr);
int			*ft_array_dup(int *arr, int size);
int			ft_array_cmp(int *arr1, int *arr2, int size_a);

//check.c
int		check_args(int argc, char **argv);
t_ps	*valid_args(int argc, char **argv, t_ps *ps);

// move_s.c
void	move_sa(t_ps *ps);
void	move_sb(t_ps *ps);
void	move_ss(t_ps *ps);

// move_p.c
void	move_pa(t_ps *ps);
void	move_pb(t_ps *ps);

// move_r.c
void	move_ra(t_ps *ps);
void	move_rb(t_ps *ps);
void	move_rr(t_ps *ps);

// move_rr.c
void	move_rra(t_ps *ps);
void	move_rrb(t_ps *ps);
void	move_rrr(t_ps *ps);

// order.c
void	order_three(t_ps *ps);
void	order_five(t_ps *ps);

#endif
