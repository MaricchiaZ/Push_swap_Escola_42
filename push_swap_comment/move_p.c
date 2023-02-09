/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:24:59 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 15:25:27 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_pa(t_ps *ps) // move a última posição (ou o TOPO) da pilha b para a pilha a
{
	if(!(ps->size_sb >= 1)) // se não tiver pelo menos um elemento na pilha b
		return;
	ps->size_sa++; //tamanho da pilha a ganha uma unidade
	ps->sa[ps->size_sa - 1] = ps->sb[ps->size_sb - 1]; // topo da pilha a recebe o topo da pilha b
	ps->size_sb--; // o tamanho do array b perde uma unidade
	write(1, "pa\n", 3); // imprimimos na tela o movimento feito
}

void	move_pb(t_ps *ps) // move a última posição (ou o TOPO) da pilha a para a pilha b
{
	if(!(ps->size_sa >= 1)) // se não tiver pelo menos um elemento na pilha a
		return;
	ps->size_sb++; //tamanho da pilha b ganha uma unidade
	ps->sb[ps->size_sb - 1] = ps->sa[ps->size_sa - 1]; // o topo da pilha b recebe o topo da pilha a
	ps->size_sa--; // o tamanho do array a perde uma unidade
	write(1, "pb\n", 3); // imprimimos na tela o movimento feito
}
