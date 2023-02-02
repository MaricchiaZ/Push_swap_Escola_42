/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:31:29 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/02 10:41:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_order(t_ps *ps)
{
	int	i;

	i = 0;
	while (i + 1 < ps->size_sa)
	{
		if (ps->sa[i] < ps->sa[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	order_three(t_ps *ps)
{
	if (ps->size_sa == 1)
		return ;
	if (ps->size_sa == 2 && ps->sa[0] < ps->sa[1])
		move_sa(ps);
	if (ps->size_sa == 2 && ps->sa[0] > ps->sa[1])
		return ;
	if (ps->sa[0] > ps->sa[1] && ps->sa[1] > ps->sa[2])
		return ;
	if ((ps->sa[0] < ps->sa[1] && ps->sa[2] < ps->sa[0]) || \
	(ps->sa[0] < ps->sa[1] && ps->sa[1] < ps->sa[2]) || \
	(ps->sa[0] > ps->sa[2] && ps->sa[2] > ps->sa[1]))
		move_sa(ps);
	if (ps->sa[1] > ps->sa[2] && ps->sa[0] < ps->sa[2])
		move_rra(ps);
	if (ps->sa[1] < ps->sa[0] && ps->sa[2] > ps->sa[0])
		move_ra(ps);
	if (ps->sa[0] > ps->sa[1] && ps->sa[1] > ps->sa[2])
		return ;
}

void	order_five(t_ps *ps)
{
	int	i_low_nb;

	while (!in_order(ps) || ps->size_sb)
	{
		i_low_nb = index_low_nb(ps);
		if (ps->size_sb == 2)
		{
			order_three(ps);
			move_pa(ps);
			move_pa(ps);
		}
		else if (i_low_nb == ps->size_sa -1 && ps->size_sb < 2)
			move_pb(ps);
		else if (ps->size_sb < 2 && i_low_nb > 2 && i_low_nb != ps->size_sa -1)
			move_ra(ps);
		else if (ps->size_sb < 2 && i_low_nb < 3 && i_low_nb != ps->size_sa -1)
			move_rra(ps);
	}
}

void	order_hundred(t_ps *ps, int division)
{
	int	portion;

	if (in_order(ps))
		return ;
	portion = 0;
	while (ps->size_sa > 1)
	{
		portion = portion + division;
		if ((float)ps->size_sa / 5 > 5)
			division = ps->size_sa / 5;
		while (ps->size_sa && ps->size_sb < portion)
		{
			choice_mov_hundred(ps, portion);
			bigger_to_top(ps, find_predecessor_in_b(ps, \
			ps->sa[ps->size_sa - 1]), ps->size_sb, 'b');
			move_pb(ps);
		}
	}
	bigger_to_top(ps, index_bigger(ps->sb, ps->size_sb), ps->size_sb, 'b');
	while (ps->size_sb)
		move_pa(ps);
}

void	order_large_numbers(t_ps *ps)
{
	t_div	portion;

	portion.max = 0;
	while (ps->size_sa)
	{
		portion = info_portion_a(ps, portion);
		move_in_portion('b', ps, portion);
	}
	portion.min = ps->size_sa + ps->size_sb;
	while (ps->size_sb)
	{
		portion = info_portion_b(ps, portion);
		move_in_portion('a', ps, portion);
	}
	portion.max = (ps->size_sa + ps->size_sb) / 48;
	while (ps->size_sa)
	{
		portion = re_info_portion_a(ps, portion);
		move_in_portion('b', ps, portion);
	}
	while (ps->size_sb)
	{
		bigger_to_top(ps, index_bigger(ps->sb, ps->size_sb), ps->size_sb, 'b');
		move_pa(ps);
	}
}
