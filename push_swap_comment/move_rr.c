/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:01:26 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/01 18:25:42 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rra(t_ps *ps) // (rotação reversa de a): Descer uma casa todos os elementos da pilha a passando o último elemento (array[0]) para o primeiro (TOPO).
{
	int	temp;
	int	i;

	if(!(ps->size_sa > 1))
		return;
	i = 0;
	temp = ps->sa[0];
	while (i < ps->size_sa - 1)
	{
		ps->sa[i] = ps->sa[i + 1];
		i++;
	}
	ps->sa[i] = temp;
	write(1, "rra\n", 4);
}

void	move_rrb(t_ps *ps) // (rotação reversa de b): Descer uma casa todos os elementos da pilha a passando o último elemento (array[0]) para o primeiro (TOPO).
{
	int	temp;
	int	i;

	i = 0;
	if(!(ps->size_sb > 1))
		return;
	temp = ps->sb[0];
	while (i < ps->size_sb - 1)
	{
		ps->sb[i] = ps->sb[i + 1];
		i++;
	}
	ps->sb[i] = temp;
	write(1, "rrb\n", 4);		
}

void	move_rrr(t_ps *ps)
{
	int	temp;
	int	i;

	//if(!(ps->size_sa > 1) || !(ps->size_sb > 1))
	//	return;
	i = 0;
	temp = ps->sa[0];
	while (i < ps->size_sa - 1)
	{
		ps->sa[i] = ps->sa[i + 1];
		i++;
	}
	ps->sa[i] = temp;
	i = 0;
	temp = ps->sb[0];
	while (i < ps->size_sb - 1)
	{
		ps->sb[i] = ps->sb[i + 1];
		i++;
	}
	ps->sb[i] = temp;
	write(1, "rrr\n", 4);
}