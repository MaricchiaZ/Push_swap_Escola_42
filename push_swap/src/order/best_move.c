/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 08:36:31 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/02 10:27:34 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*best_mov_r_or_rr(t_ps *ps, int *sa, int *sb, t_big_i big_index)
{
	if (sa && sb && ps->size_sa > 1 && ps->size_sb > 1 && \
	big_index.a != ps->size_sa - 1 && big_index.b > (ps->size_sb -1) / 2)
	{
		if (big_index.a >= (ps->size_sa - 1) / 2 && \
		big_index.b >= (ps->size_sb - 1) / 2)
			return ("rr");
		else if (big_index.a < (ps->size_sa - 1) / 2 && \
		big_index.b < (ps->size_sb - 1) / 2)
			return ("rrr");
	}
	if (sa && ps->sa && big_index.a != ps->size_sa - 1)
	{
		if (big_index.a >= ps->size_sa / 2)
			return ("ra");
		else if (big_index.a < ps->size_sa / 2)
			return ("rra");
	}
	if (sb && big_index.b != ps->size_sb - 1)
	{
		if (big_index.b >= ps->size_sb / 2)
			return ("rb");
		else if (big_index.b < ps->size_sb / 2)
			return ("rrb");
	}
	return (NULL);
}
