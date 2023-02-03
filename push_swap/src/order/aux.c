/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:35:48 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/03 20:49:13 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	index_low_nb(t_ps *ps)
{
	int				i;
	int				low_nb;
	unsigned int	index_low_nb;

	i = 0;
	low_nb = ps->sa[0];
	index_low_nb = 0;
	while (i < ps->size_sa)
	{
		if (ps->sa[i] < low_nb)
		{
			low_nb = ps->sa[i];
			index_low_nb = i;
		}
		i++;
	}
	return (index_low_nb);
}

unsigned int	index_bigger(int *stack, int size_s)
{
	unsigned int	i;
	int				bigger_nb;
	unsigned int	index_bigger_nb;

	if (!size_s)
		return (0);
	i = 1;
	bigger_nb = stack[0];
	index_bigger_nb = 0;
	while (i < (unsigned int)size_s)
	{
		if (stack[i] > bigger_nb)
		{
			bigger_nb = stack[i];
			index_bigger_nb = i;
		}
		i++;
	}
	return (index_bigger_nb);
}

int	near_pos_to_move(int *stack, int stack_size, int range, int min_range)
{
	int	i;
	int	near_pos;

	i = -1;
	near_pos = 0;
	if (stack_size < 20)
		return (stack_size - 1);
	while (++i < stack_size)
	{
		if (min_range <= stack[i] && stack[i] < range)
		{
			near_pos = i;
			break ;
		}
	}
	i = stack_size;
	while (--i < stack_size && i > stack_size - near_pos)
	{
		if (min_range <= stack[i] && stack[i] < range)
		{
			near_pos = i;
			break ;
		}
	}
	return (near_pos);
}

int	find_predecessor_in_b(t_ps *ps, int nb)
{
	int	i;
	int	predecessor;
	int	pred_i;
	int	check_pred;

	i = 0;
	predecessor = -1;
	pred_i = 0;
	check_pred = 0;
	while (ps->sb && i < ps->size_sb)
	{
		if (predecessor < ps->sb[i] && ps->sb[i] < nb)
		{
			predecessor = ps->sb[i];
			pred_i = i;
			check_pred = 1;
		}
		i++;
	}
	if (!check_pred)
		return (index_bigger(ps->sb, ps->size_sb));
	return (pred_i);
}

void	bigger_to_top(t_ps *ps, unsigned int index_bigger, \
unsigned int size, char stack)
{
	int		distance;
	t_big_i	big_index;

	if (index_bigger >= size / 2)
		distance = size - index_bigger - 1;
	else
		distance = index_bigger + 1;
	while (distance > 0)
	{
		if (stack == 'a')
		{
			big_index.a = index_bigger;
			big_index.b = 0;
			exec_moves(ps, best_mov_r_or_rr(ps, ps->sa, NULL, big_index));
		}
		else if (stack == 'b')
		{
			big_index.a = 0;
			big_index.b = index_bigger;
			exec_moves(ps, best_mov_r_or_rr(ps, NULL, ps->sb, big_index));
		}
		distance--;
	}
}
