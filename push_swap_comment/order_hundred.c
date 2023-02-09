/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_hundred.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:32:21 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 15:35:56 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// função que escoolhe o melhor movimento a ser feito, e devolve uma str com o nome do movimento. Ela pode operar na stack a, se nao for passada a pilha b, pode operar só na stack b, se nao for passada a stack a, ou pode operar nas duas pilhas ao mesmo tempo se as duas pilhas forem enviadas (ou seja, nenhuma delas for null)
char	*best_mov_r_or_rr(t_ps *ps, int *sa, int *sb, int near_pos_a, int near_pos_b)
{
	if (sa && sb && ps->size_sa > 1 && ps->size_sb > 1 && near_pos_a != ps->size_sa - 1 && near_pos_b > (ps->size_sb -1) / 2) // se exitir a pilha e a pilha b, e a melhor posição de a e b não estiver no topo...
	{
		if (near_pos_a >= (ps->size_sa - 1) /2 && near_pos_b >= (ps->size_sb - 1) / 2) // .. e se o movimento de interesse estiver da metada pra cima das pilhas recomenadamos o movimento rr
			return ("rr"); // retornamos a indicação do mov sugerido
		else if (near_pos_a < (ps->size_sa - 1) / 2 && near_pos_b < (ps->size_sb - 1) / 2) // se o movimento de interesse estiver da metada pra baixo das pilhas damos o movimento rrr
			return ("rrr"); // retornamos a indicação do mov sugerido
	}
	if (sa && ps->sa && near_pos_a != ps->size_sa - 1) // se tivermos a pilha a e a melhor posição de a não estiver no topo..
	{
		if (near_pos_a >= ps->size_sa /2) // se a posição estiver perto do topo
			return ("ra");
		else  if (near_pos_a < ps->size_sa /2) // senão rotacionamos reversamente
			return ("rra");
	}
	if (sb && near_pos_b != ps->size_sb - 1) // se tivermos a pilha b e ae a melhor posição de b não estiver no topo..
	{
		if (near_pos_b >= ps->size_sb /2) // se a posição estiver perto do topo
			return ("rb");
		else if (near_pos_b < ps->size_sb /2)// senão rotacionamos reversamente
			return ("rrb");
	}

	return (NULL);
}

// função que escolhe o melhor movimento para ser feito
void	choice_mov_hundred(t_ps *ps, int range)
{
	int		near_pos; // buscamos um menor número dentro da faixa escolhida, e vemos se está no início ou no fim da pilha, se a posição for 0, veremos um pb, se for próximo ao topo ra, proximo ao fim rra 
	char	*move; // recebe a sugestão de movimento

	near_pos = near_pos_to_move(ps->sa, ps->size_sa, range , 0); // recebemos o índice do numero a se mexer dentro do range indicado 
	while (near_pos != ps->size_sa - 1) // enquanto a near_pos não for o topo da pilha
	{
		// // printa a pilha a e b pra ajudar a entender
		// printf("pilha a: ");
		// for(int a=0; a < ps->size_sa; a++)
		// 	printf("%d ", ps->sa[a]);
		// printf("\n");
		// printf("pilha b: ");
		// for(int b=0; b < ps->size_sb; b++)
		// 	printf("%d ", ps->sb[b]);
		// printf("\n");
		// sleep(1); // dá uma pausa para podermos ver as etapas ocorrendo
		move = best_mov_r_or_rr(ps, ps->sa, ps->sb, near_pos, \
		find_predecessor_in_b(ps, ps->sa[near_pos])); // move recebe a indicaçao do melhor movimento considerando as duas pilhas '2'
		//printf("move: %s\n", move);
		if (near_pos < ps->size_sb && !ft_strcmp(move, "ra") && \
		 find_predecessor_in_b(ps, ps->sa[near_pos] != ps->size_sb - 1)) // se posição indicada para mexermos for maior que a qnt de itens da pilha b E a sugestão de mov não for ra E o número antecessor de ps->sa[near_pos] não está no topo de b, rotacionamos as duas pilhas
			move_rr(ps);
		else if (ps->size_sa - near_pos < ps->size_sb && \
		 !ft_strcmp(move, "rra") && find_predecessor_in_b(ps, ps->sa[near_pos]) != ps->size_sb -1) // se o tamanho da pilha a - posiçao indicada for maior que a pilha b E a sugestão de movimento não for rra E  E o número antecessor de ps->sa[near_pos] não está no topo de b, rotacionamos reversamente as duas pilhas
			move_rrr(ps);
		else
		{
			exec_moves(ps, move); // senão apenas executamos o movimento indicado
		}
		near_pos = near_pos_to_move(ps->sa, ps->size_sa, range , 0);  // recebemos a nova posição pra mover
	}
}