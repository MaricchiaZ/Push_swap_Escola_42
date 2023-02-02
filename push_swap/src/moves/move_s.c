/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:09:17 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/02 10:08:12 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_ps *ps)
{
	int	temp;

	if (!(ps->size_sa >= 2))
		return ;
	temp = ps->sa[ps->size_sa - 1];
	ps->sa[ps->size_sa - 1] = ps->sa[ps->size_sa - 2];
	ps->sa[ps->size_sa - 2] = temp;
	write(1, "sa\n", 3);
}

void	move_sb(t_ps *ps)
{
	int	temp;

	if (!(ps->size_sb >= 2))
		return ;
	temp = ps->sb[ps->size_sb - 1];
	ps->sb[ps->size_sb - 1] = ps->sb[ps->size_sb - 2];
	ps->sb[ps->size_sb - 2] = temp;
	write(1, "sb\n", 3);
}

void	move_ss(t_ps *ps)
{
	int	temp;

	if (!(ps->size_sa >= 2) || !(ps->size_sb >= 2))
		return ;
	temp = ps->sa[ps->size_sa - 1];
	ps->sa[ps->size_sa - 1] = ps->sa[ps->size_sa - 2];
	ps->sa[ps->size_sa - 2] = temp;
	temp = ps->sb[ps->size_sb - 1];
	ps->sb[ps->size_sb - 1] = ps->sb[ps->size_sb - 2];
	ps->sb[ps->size_sb - 2] = temp;
	write(1, "ss\n", 3);
}
