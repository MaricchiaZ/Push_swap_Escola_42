/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:01:26 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 15:25:10 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_rra(t_ps *ps) // (rotação reversa de a): Descer uma casa todos os elementos da pilha a passando o último elemento (array[0]) para o primeiro (TOPO).
{
	int	temp;
	int	i;

	if(!(ps->size_sa > 1)) // se tiver 1 ou menos elementos, não é possivel fazer esse movimento
		return;
	i = 0;
	temp = ps->sa[0]; // temp recebe a última posição
	while (i < ps->size_sa - 1)
	{
		ps->sa[i] = ps->sa[i + 1]; // tudo volta uma casa
		i++;
	}
	ps->sa[i] = temp; // o topo recebe a última posição (que estava salva em temp)
	write(1, "rra\n", 4); // imprimimos na tela o movimento feito
}

void	move_rrb(t_ps *ps) // (rotação reversa de b): Descer uma casa todos os elementos da pilha a passando o último elemento (array[0]) para o primeiro (TOPO).
{
	int	temp;
	int	i;

	i = 0;
	if(!(ps->size_sb > 1)) // se tiver 1 ou menos elementos, não é possivel fazer esse movimento
		return; 
	temp = ps->sb[0];  // temp recebe a última posição
	while (i < ps->size_sb - 1)
	{
		ps->sb[i] = ps->sb[i + 1]; // tudo volta uma casa
		i++;
	}
	ps->sb[i] = temp; // o topo recebe a última posição (que estava salva em temp)
	write(1, "rrb\n", 4); // imprimimos na tela o movimento feito
}

void	move_rrr(t_ps *ps)
{
	int	temp;
	int	i;

	if(!(ps->size_sa > 1) || !(ps->size_sb > 1)) // se tiver 1 ou menos elementos, não é possivel fazer esse movimento
		return;
	i = 0;
	temp = ps->sa[0];  // temp recebe a última posição de a
	while (i < ps->size_sa - 1)
	{
		ps->sa[i] = ps->sa[i + 1]; // tudo volta uma casa
		i++;
	}
	ps->sa[i] = temp; // o topo de a recebe a última posição (que estava salva em temp)
	i = 0;
	temp = ps->sb[0];  // temp recebe a última posição de b
	while (i < ps->size_sb - 1)
	{
		ps->sb[i] = ps->sb[i + 1]; // tudo volta uma casa
		i++;
	}
	ps->sb[i] = temp; // o topo de b recebe a última posição (que estava salva em temp)
	write(1, "rrr\n", 4); // imprimimos na tela o movimento feito
}