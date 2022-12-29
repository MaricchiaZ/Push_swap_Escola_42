/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:09:17 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 12:45:05 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_ps *ps)
{
	int	temp;
	
	if (ps->size_sa >= 2)
	{
	temp = ps->sa[0];
	ps->sa[0] = ps->sa[1];
	ps->sa[1] = temp;
	}
	write(1, "sa\n", 3);
}

void	move_sb(t_ps *ps)
{
	int	temp;
	
	if (ps->size_sb >= 2)
	{
	temp = ps->sb[0];
	ps->sb[0] = ps->sb[1];
	ps->sb[1] = temp;
	}
	write(1, "sb\n", 3);
}

void	move_ss(t_ps *ps)
{
	int	temp;
	
	if (ps->size_sa >= 2 && ps->size_sb >= 2)
	{
	temp = ps->sa[0];
	ps->sa[0] = ps->sa[1];
	ps->sa[1] = temp;
	temp = ps->sb[0];
	ps->sb[0] = ps->sb[1];
	ps->sb[1] = temp;
	}
	write(1, "ss\n", 3);
}
