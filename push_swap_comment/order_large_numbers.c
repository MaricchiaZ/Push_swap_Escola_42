/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_large_numbers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:59:38 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 18:10:47 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// recebe as informações da porção trabalhada da pilha a (com essas infos serão mandados os números da pilha a para a b)
t_div	info_portion_a(t_ps *ps, t_div portion)
{
	portion.min = portion.max; // inicialmente estão em 0 os dois...
	if (portion.max == 0) // primeira vez que está rodando
		portion.max = (ps->size_sa + ps->size_sb) / 2; // recebe metade do tamanho total
	else if (portion.max < (ps->size_sa + ps->size_sb) - (ps->size_sa + ps->size_sb)/24) // se a porção máxima encontra-se antes dos 1/24 finais
		portion.max = portion.max + portion.max / 2; // máximo recebe ele mesmo + 1/2 dele
	else
		portion.max = ps->size_sa + ps->size_sb; // tamanho total (tam das pilhas a + b)
	portion.half = portion.min + (portion.max - portion.min) / 2; // recebe o valor médio da faixa trabalhada
	return (portion); //retorna os detalhes da subporção preenchidos
}

// recebe as informações da porção trabalhada da pilha b (com essas infos serão mandados os números da pilha b para a a)
t_div	info_portion_b(t_ps *ps, t_div portion)
{
	portion.max = portion.min; // inicialmente o min é a qnt total de elementos passados
	if (portion.max == 0) // se é a primeira vez que está rodando
		portion.max = (ps->size_sa + ps->size_sb); // recebe metade do tamanho total
	portion.min = portion.min - (ps->size_sa + ps->size_sb) / 12; // minimo recebe 1/12 do tamanho trabalhado
	if (portion.min > (ps->size_sa + ps->size_sb)) // se o mín é maior do que a soma de a e b
		portion.min = 0; // ele é zerado
	portion.half = portion.min + (portion.max - portion.min) / 2; // recebe o valor médio da faixa trabalhada/
	return (portion);
}

// recebe de novo as informações da porção trabalhada da pilha a (com essas infos serão mandados os números NOVAMENTE da pilha a para a b)
t_div	re_info_portion_a(t_ps *ps, t_div portion)
{
	portion.min = portion.max; // estão em 0 os dois...
	if (portion.min == (ps->size_sa + ps->size_sb) / 48) // se o min for 1/48 do total
		portion.min = 0; // ele é zerado
	portion.max = portion.max + ((ps->size_sa + ps->size_sb) / 48); // max reccebe ele mesmo mais 1/48 dele
	portion.half = portion.min + (portion.max - portion.min) / 2; // recebe o valor médio da faixa trabalhada
	return (portion);
}

// movimenta os números dentro da faixa trabalhada
void	move_in_portion(char stack, t_ps *ps, t_div portion)
{
	int	aux;

	while (stack == 'b' && ps->size_sa && ps->size_sb < portion.max) // se estivermos trabalhando c a pilha b e ainda n estivermos atingindo o valor máximo da porção
	{
		bigger_to_top(ps, near_pos_to_move(ps->sa, ps->size_sa, portion.max, portion.min), ps->size_sa, 'a'); // passamos o maior para o topo
		move_pb(ps); // movemos para a pilha b
		aux = near_pos_to_move(ps->sa, ps->size_sa, portion.max, portion.min); // aux recebe o índice do próximo número que se deve mover
		if (ps->sb[ps->size_sb - 1] > portion.half && aux >= ps->size_sa / 2 && aux != ps->size_sa - 1) //se o número do topo for maior que o 1/2 da porção E aux estiver perto do topo E não for o topo
			move_rr(ps); // movemos as duas
		else if (ps->sb[ps->size_sb - 1] > portion.half) // se o topo for maior que a metade da porção
			move_rb(ps); // movemos apenas a b
	}
	while (stack == 'a' && ps->size_sb && ps->size_sa < (ps->size_sa + ps->size_sb) - portion.min) // se estivermos trabalhando c a pilha a e ainda n estivermos atingindo o valor máximo da porção
	{
		bigger_to_top(ps, near_pos_to_move(ps->sb, ps->size_sb, portion.max, portion.min), ps->size_sb, 'b'); // passamos o maior para o topo
		move_pa(ps); // movemos para a pilha b
		aux = near_pos_to_move(ps->sb, ps->size_sb, portion.max, portion.min); // aux recebe o índice do próximo número que se deve mover
		if (ps->sa[ps->size_sa - 1] > portion.half && aux < ps->size_sb / 2 && aux != ps->size_sb - 1) //se o número do topo for maior que o 1/2 da porção E aux for menor q o tamanho de b E não for o topo
			move_rr(ps); // movemos as duas
		else if (ps->sa[ps->size_sa - 1] > portion.half) // se o topo for maior que a metade da porção
			move_ra(ps); // movemos apenas a a
	}
}