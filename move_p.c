/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:24:59 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 12:42:52 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(t_ps *ps)
{
	if(ps->size_sb >=1)
	{
		ps->temp = ps->sb[0];
		ps->sb++;
		ps->size_sb--;
	}
	else
		return;
	ps->size_sa++;
	ps->sa--;
	ps->sa[0] = ps->temp;
	write(1, "pa\n", 3);
}

void	move_pb(t_ps *ps)
{
	if(ps->size_sa >=1)
	{
		ps->temp = ps->sa[0];
		ps->sa++;
		ps->size_sa--;
	}
	else
		return;
	ps->size_sb++;
	ps->sb--;
	ps->sb[0] = ps->temp;
	write(1, "pb\n", 3);
}
