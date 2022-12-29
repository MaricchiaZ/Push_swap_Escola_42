/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:51:38 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 13:07:54 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_ra(t_ps *ps)
{
	int temp;
	int i;
	
	i = 0;
	if(ps->size_sa > 1)
	{
		temp = ps->sa[0];
		while (i < ps->size_sa - 1)
		{
			ps->sa[i] = ps->sa[i + 1];
			i++;
		}
		ps->sa[i] = temp;
		write(1, "ra\n", 3);
	}
}

void	move_rb(t_ps *ps)
{
	int temp;
	int i;
	
	i = 0;
	if(ps->size_sb > 1)
	{
		temp = ps->sb[0];
		while (i < ps->size_sb - 1)
		{
			ps->sb[i] = ps->sb[i + 1];
			i++;
		}
		ps->sb[i] = temp;
		write(1, "rb\n", 3);
	}
}

void	move_rr(t_ps *ps)
{
	int temp;
	int i;
	
	i = 0;
	if(ps->size_sa > 1 && ps->size_sb > 1)
	{
		temp = ps->sa[0];
		while (i < ps->size_sa - 1)
		{
			ps->sa[i] = ps->sa[i + 1];
			i++;
		}
		ps->sa[i] = temp;
		temp = ps->sa[0];
		while (i < ps->size_sa - 1)
		{
			ps->sa[i] = ps->sa[i + 1];
			i++;
		}
		ps->sa[i] = temp;
		write(1, "rr\n", 3);
	}
}
