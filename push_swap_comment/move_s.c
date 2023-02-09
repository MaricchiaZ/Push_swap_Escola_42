/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:09:17 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 15:28:15 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_sa(t_ps *ps) //Troca os 2 primeiros elementos no topo do stack a. (Não fazer nada se houver apenas um ou nenhum elemento).
{
	int	temp;
	
	if (!(ps->size_sa >= 2)) // se tiver menos de dois elementos, não é possível fazer esse movimento
		return;
	temp = ps->sa[ps->size_sa - 1]; // temp recebe o topo
	ps->sa[ps->size_sa - 1] = ps->sa[ps->size_sa - 2]; // topo recebe a posição logo abaixo
	ps->sa[ps->size_sa - 2] = temp; // a posição logo abaixo recebe o topo (que estava salvo em temp)
	write(1, "sa\n", 3); // imprimimos o movimento feito
}

void	move_sb(t_ps *ps) //Troca os 2 primeiros elementos no topo do stack b. (Não fazer nada se houver apenas um ou nenhum elemento).
{
	int	temp;
	
	if (!(ps->size_sb >= 2)) // se tiver menos de dois elementos, não é possível fazer esse movimento
		return;
	temp = ps->sb[ps->size_sb - 1]; // temp recebe o topo
	ps->sb[ps->size_sb - 1] = ps->sb[ps->size_sb - 2]; // topo recebe a posição logo abaixo
	ps->sb[ps->size_sb - 2] = temp; // a posição logo abaixo recebe o topo (que estava salvo em temp)
	write(1, "sb\n", 3); // imprimimos o movimento feito
}

void	move_ss(t_ps *ps)
{
	int	temp;
	
	if (!(ps->size_sa >= 2) || !(ps->size_sb >= 2)) // se tiver menos de dois elementos, não é possível fazer esse movimento
		return;
	temp = ps->sa[ps->size_sa - 1]; // temp recebe o topo de a
	ps->sa[ps->size_sa - 1] = ps->sa[ps->size_sa - 2]; // topo de a recebe a posição logo abaixo
	ps->sa[ps->size_sa - 2] = temp; // a posição logo abaixo recebe o topo de a (que estava salvo em temp)
	temp = ps->sb[ps->size_sb - 1]; // temp recebe o topo de b
	ps->sb[ps->size_sb - 1] = ps->sb[ps->size_sb - 2]; // topo de b recebe a posição logo abaixo
	ps->sb[ps->size_sb - 2] = temp; // a posição logo abaixo recebe o topo de b(que estava salvo em temp)
	write(1, "ss\n", 3); // imprimimos o movimento feito
}
