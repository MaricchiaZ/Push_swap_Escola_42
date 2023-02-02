/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:42:41 by maclara-          #+#    #+#             */
/*   Updated: 2023/01/31 20:09:05 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_moves(t_ps *ps, char *move)
{
	//printf("move: %s\n", move);
	if (!ft_strcmp(move, "sa"))
		move_sa(ps);
	else if (!ft_strcmp(move, "sb"))
		move_sb(ps);
	else if (!ft_strcmp(move, "ss"))
		move_ss(ps);
	else if (!ft_strcmp(move, "pa"))
		move_pa(ps);
	else if (!ft_strcmp(move, "pb"))
		move_pb(ps);
	else if (!ft_strcmp(move, "ra"))
		move_ra(ps);
	else if (!ft_strcmp(move, "rb"))
		move_rb(ps);
	else if (!ft_strcmp(move, "rr"))
		move_rr(ps);
	else if (!ft_strcmp(move, "rra"))
		move_rra(ps);
	else if (!ft_strcmp(move, "rrb"))
		move_rrb(ps);
	else if (!ft_strcmp(move, "rrr"))
		move_rrr(ps);
}
