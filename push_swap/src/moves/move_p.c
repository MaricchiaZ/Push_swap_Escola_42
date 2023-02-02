/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:24:59 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/02 10:02:57 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(t_ps *ps)
{
	if (!(ps->size_sb >= 1))
		return ;
	ps->size_sa++;
	ps->sa[ps->size_sa - 1] = ps->sb[ps->size_sb - 1];
	ps->size_sb--;
	write(1, "pa\n", 3);
}

void	move_pb(t_ps *ps)
{
	if (!(ps->size_sa >= 1))
		return ;
	ps->size_sb++;
	ps->sb[ps->size_sb - 1] = ps->sa[ps->size_sa - 1];
	ps->size_sa--;
	write(1, "pb\n", 3);
}
