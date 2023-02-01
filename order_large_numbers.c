/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_large_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:59:38 by maclara-          #+#    #+#             */
/*   Updated: 2023/01/31 11:21:40 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_div	info_portion_a(t_ps *ps, t_div portion)
{
	portion.min = portion.max; // inicialmente estão em 0 os dois...
	if (portion.max == 0)
		portion.max = (ps->size_sa + ps->size_sb) / 2; // recebe metade do tamanho total
	else if (portion.max < (ps->size_sa + ps->size_sb) - (ps->size_sa + ps->size_sb)/24)
		portion.max = portion.max + portion.max / 2;
	else
		portion.max = ps->size_sa + ps->size_sb; // tamanho total (tam das pilhas a + b)
	portion.half = portion.min + (portion.max - portion.min) / 2;
	return (portion); //retorna os detalhes da subporção preenchidos
}

t_div	info_portion_b(t_ps *ps, t_div portion)
{
	portion.max = portion.min;
	if (portion.max == 0)
		portion.max = (ps->size_sa + ps->size_sb);
	portion.min = portion.min - (ps->size_sa + ps->size_sb) / 12;
	if (portion.min > (ps->size_sa + ps->size_sb))
		portion.min = 0;
	portion.half = portion.min + (portion.max - portion.min) / 2;
	return (portion);
}

t_div	re_info_portion_a(t_ps *ps, t_div portion)
{
	portion.min = portion.max; // estão em 0 os dois...
	if (portion.min == (ps->size_sa + ps->size_sb) / 48)
		portion.min = 0;
	portion.max = portion.max + ((ps->size_sa + ps->size_sb) / 48);
	portion.half = portion.min + (portion.max - portion.min) / 2;
	return (portion);
}

void	move_in_portion(char stack, t_ps *ps, t_div portion)
{
	int	aux;

	while (stack == 'b' && ps->size_sa && ps->size_sb < portion.max)
	{
		bigger_to_top(ps, near_pos_to_move(ps->sa, ps->size_sa, portion.max, portion.min), ps->size_sa, 'a');
		move_pb(ps);
		aux = near_pos_to_move(ps->sa, ps->size_sa, portion.max, portion.min);
		if (ps->sb[0] > portion.half && aux < ps->size_sa / 2 && aux > 0)
			move_rr(ps);
		else if (ps->sb[0] > portion.half)
			move_rb(ps);
	}
	while (stack == 'a' && ps->size_sb && ps->size_sa < (ps->size_sa + ps->size_sb) - portion.min)
	{
		bigger_to_top(ps, near_pos_to_move(ps->sb, ps->size_sa, portion.max, portion.min), ps->size_sb, 'b');
		move_pa(ps);
		aux = near_pos_to_move(ps->sb, ps->size_sb, portion.max, portion.min);
		if (ps->sa[0] > portion.half && aux < ps->size_sb / 2 && aux > 0)
			move_rr(ps);
		else if (ps->sa[0] > portion.half)
			move_ra(ps);
	}
}