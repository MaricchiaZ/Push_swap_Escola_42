/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:31:29 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/29 10:25:43 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_three(t_ps *ps)
{
	if (ps->sa[0] < ps->sa[1] && ps->sa[1] < ps->sa[2]) // 1,2,3
		return;
	if ((ps->sa[0] > ps->sa[1] && ps->sa[2] > ps->sa[0]) || \
	(ps->sa[0] > ps->sa[1] && ps->sa[1] > ps->sa[2]) || \
	(ps->sa[0] < ps->sa[2] && ps->sa[2] < ps->sa[1])) // 2,1,3 - 3,2,1 - 1,3,2 
		move_sa(ps);
	if (ps->sa[1] < ps->sa[2] && ps->sa[2] < ps->sa[0]) //  3,1,2
		move_ra(ps);
	if (ps->sa[1] > ps->sa[0] && ps->sa[0] > ps->sa[2]) // 2, 3, 1
		move_rra(ps);
	if (ps->sa[0] < ps->sa[1] && ps->sa[1] < ps->sa[2]) // 1, 2, 3
		return;
}

void	order_five(t_ps *ps)
{
	if (ft_array_cmp(ps->sa, ps->order_cmp, ps->size_sa) == 1)
		return;
	while (ps->size_sa > 4)
	{
		if (ps->sa[1] < ps->sa[0] && ps->sa[1] < ps->sa[0])
			move_pb;
		if (ps->sa[0] > ps->sa[1] && ps->sa[1] > ps->sa[ps->size_sa - 1])
			move_pb;
			
		
	}
}


/*
		if (ps->sa[0] > ps->sa[ps->size_sa - 1] && ps->sa[0] > ps->sa[ps->size_sa - 1])
			move_pb;
		if (ps->sa[0] > ps->sa[1] && ps->sa[0] > ps->sa[ps->size_sa - 1])
			move_pb;
*/