/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:01:26 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 13:12:40 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rra(t_ps *ps)
{
	int	temp;
	int	i;

	if(ps->size_sa > 1)
	{
		i = ps->size_sa - 1;
		temp = ps->sa[i];
		while (i > 0)
		{
			ps->sa[i] = ps->sa[i - 1];
			i--;
		}
		ps->sa[i] = temp;
		write(1, "rra\n", 4);		
	}
}

void	move_rrb(t_ps *ps)
{
	int	temp;
	int	i;

	if(ps->size_sb > 1)
	{
		i = ps->size_sb - 1;
		temp = ps->sb[i];
		while (i > 0)
		{
			ps->sb[i] = ps->sb[i - 1];
			i--;
		}
		ps->sb[i] = temp;
		write(1, "rrb\n", 4);		
	}
}

void	move_rrr(t_ps *ps)
{
	int	temp;
	int	i;

	if(ps->size_sa > 1 && ps->size_sb > 1)
	{
		i = ps->size_sa - 1;
		temp = ps->sa[i];
		while (i > 0)
		{
			ps->sa[i] = ps->sa[i - 1];
			i--;
		}
		ps->sa[i] = temp;
		i = ps->size_sb - 1;
		temp = ps->sb[i];
		while (i > 0)
		{
			ps->sb[i] = ps->sb[i - 1];
			i--;
		}
		ps->sb[i] = temp;
		write(1, "rrr\n", 4);		
	}
}