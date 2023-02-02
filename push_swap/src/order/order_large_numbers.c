/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_large_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:59:38 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/02 11:29:37 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_to_b(t_ps *ps, t_div portion, int aux)
{
	bigger_to_top(ps, near_pos_to_move(ps->sa, ps->size_sa, \
	portion.max, portion.min), ps->size_sa, 'a');
	move_pb(ps);
	aux = near_pos_to_move(ps->sa, ps->size_sa, portion.max, portion.min);
	if (ps->sb[ps->size_sb - 1] > portion.half && \
	aux >= ps->size_sa / 2 && aux != ps->size_sa - 1)
		move_rr(ps);
	else if (ps->sb[ps->size_sb - 1] > portion.half)
		move_rb(ps);
}

static void	move_to_a(t_ps *ps, t_div portion, int aux)
{
	bigger_to_top(ps, near_pos_to_move(ps->sb, ps->size_sb, \
	portion.max, portion.min), ps->size_sb, 'b');
	move_pa(ps);
	aux = near_pos_to_move(ps->sb, ps->size_sb, portion.max, portion.min);
	if (ps->sa[ps->size_sa - 1] > portion.half && \
	aux < ps->size_sb / 2 && aux != ps->size_sb - 1)
		move_rr(ps);
	else if (ps->sa[ps->size_sa - 1] > portion.half)
		move_ra(ps);
}

void	move_in_portion(char stack, t_ps *ps, t_div portion)
{
	int	aux;

	aux = 0;
	while (stack == 'b' && ps->size_sa && ps->size_sb < portion.max)
		move_to_b(ps, portion, aux);
	while (stack == 'a' && ps->size_sb && \
	ps->size_sa < (ps->size_sa + ps->size_sb) - portion.min)
		move_to_a(ps, portion, aux);
}
