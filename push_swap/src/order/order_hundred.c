/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:32:21 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/02 11:13:53 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choice_mov_hundred(t_ps *ps, int range)
{
	t_big_i	big_index;
	int		near_pos;
	char	*move;

	near_pos = near_pos_to_move(ps->sa, ps->size_sa, range, 0);
	while (near_pos != ps->size_sa - 1)
	{
		big_index.a = near_pos;
		big_index.b = find_predecessor_in_b(ps, ps->sa[near_pos]);
		move = best_mov_r_or_rr(ps, ps->sa, ps->sb, big_index);
		if (near_pos < ps->size_sb && !ft_strcmp(move, "ra") && \
		find_predecessor_in_b(ps, ps->sa[near_pos] != ps->size_sb -1))
			move_rr(ps);
		else if (ps->size_sa - near_pos < ps->size_sb && \
		!ft_strcmp(move, "rra") && find_predecessor_in_b(ps, \
		ps->sa[near_pos]) != ps->size_sb -1)
			move_rrr(ps);
		else
			exec_moves(ps, move);
		near_pos = near_pos_to_move(ps->sa, ps->size_sa, range, 0);
	}
}
