/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 12:51:38 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 15:25:19 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_ra(t_ps *ps) // Desloca todos os elementos da pilha a para cima, mandando o primeiro elemento (do topo) para o último (array[0]).
{
	int temp;
	int i;
	
	i = 0;
	if(!(ps->size_sa > 1)) // se tiver 1 ou menos elementos, não é possivel fazer esse movimento
		return;
	temp = ps->sa[ps->size_sa - 1]; //temp recebe o topo
	i = ps->size_sa - 1;
	while (i)
	{
		ps->sa[i] = ps->sa[i - 1]; // tudo avança uma casa
		i--;
	}
	ps->sa[i] = temp; // posição[0] recebe temp
	write(1, "ra\n", 3); // imprimimos na tela o movimento feito
}

void	move_rb(t_ps *ps) // Desloca todos os elementos da pilha b para cima, mandando o primeiro elemento (do topo) para o último (array[0]).
{
	int temp;
	int i;
	
	i = 0;
	if(!(ps->size_sb > 1)) // se tiver 1 ou menos elementos, não é possivel fazer esse movimento
		return;
	temp = ps->sb[ps->size_sb - 1]; //temp recebe o topo
	i= ps->size_sb - 1;
	while (i)
	{
		ps->sb[i] = ps->sb[i - 1];  // tudo avança uma casa
		i--;
	}
	ps->sb[i] = temp; // posição[0] recebe temp
	write(1, "rb\n", 3); // imprimimos na tela o movimento feito
}

// Desloca todos os elementos da pilha a e da pilha b para cima, mandando os primeiros elementos (do topo) para os últimos (array[0]).
void	move_rr(t_ps *ps)
{
	int temp;
	int i;
	
	i = 0;
	if(!(ps->size_sa > 1) || !(ps->size_sb > 1)) // se tiver 1 ou menos elementos, não é possivel fazer esse movimento
		return;
	temp = ps->sa[ps->size_sa -1]; //temp recebe o topo de a
	i = ps->size_sa - 1;
	while (i)
	{
		ps->sa[i] = ps->sa[i - 1]; // tudo avança uma casa
		i--;
	}
	ps->sa[i] = temp; // posição[0] recebe temp
	temp = ps->sb[ps->size_sb - 1]; //temp recebe o topo de b
	i= ps->size_sb - 1;
	while (i)
	{
		ps->sb[i] = ps->sb[i - 1]; // tudo avança uma casa
		i--;
	}
	ps->sb[i] = temp; // posição[0] recebe temp
	write(1, "rr\n", 3); // imprimimos na tela o movimento feito
}
