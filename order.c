/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 14:31:29 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/01 19:04:49 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// função que confere se a pilha está em ordem, comparando a posição atual com a próxima
int	in_order(t_ps *ps)
{
	int	i; // índice para percorrer a pilha

	i = 0; // iniciamos no zero
	while (i + 1 < ps->size_sa)
	{
		if (ps->sa[i] < ps->sa[i + 1]) // comparamos se a posição atual é maior que a próxima
			return (0); // avisamos que está errado
		i++; // se for menor comparamos as próximas
	}
	return (1); // acabou a comparação e está td ok
}

void	order_three(t_ps *ps)
{
	// com só 1 número
	if (ps->size_sa == 1) //1
		return ;
	// com só 2 números
	if (ps->size_sa == 2 &&  ps->sa[0] < ps->sa[1]) // foi passado 2,1 -> salvamos na pilha 1, 2
		move_sa(ps);
	if (ps->size_sa == 2 &&  ps->sa[0] > ps->sa[1]) // foi passado 1,2 -> salvamos na pilha 2, 1
		return;
	// com 3 números
	if (ps->sa[0] > ps->sa[1] && ps->sa[1] > ps->sa[2]) // foi passado 1,2,3 -> salvamos na pilha 3, 2, 1
		return;
	// foi passado 2,1,3 -> salvamos na pilha 3, 1, 2 SA 321ok
	// foi passado 3,2,1 -> salvamos na pilha 1, 2, 3 SA RRA 132
	// foi passado 1,3,2 -> salvamos na pilha 2, 3, 1 SA RA 213
	if ((ps->sa[0] < ps->sa[1] && ps->sa[2] < ps->sa[0]) || \
	(ps->sa[0] < ps->sa[1] && ps->sa[1] < ps->sa[2]) || \
	(ps->sa[0] > ps->sa[2] && ps->sa[2] > ps->sa[1]))
		move_sa(ps);
	if (ps->sa[1] > ps->sa[2] && ps->sa[0] < ps->sa[2]) //se salvo na pilha 132
		move_rra(ps);
	if (ps->sa[1] < ps->sa[0] && ps->sa[2] > ps->sa[0]) // se salvo na pilha 213
		move_ra(ps);
	if (ps->sa[0] > ps->sa[1] && ps->sa[1] > ps->sa[2]) // se salvo na pilha 321
		return;
}

// mandamos os 2 menores elementos para a pilha b, ordenamos a pilha a (pela regra de 3), devolvemos os 2 elementos para a pilha a, reordenamos a pilha a
void	order_five(t_ps *ps)
{
	int	i_low_nb; // rebererá o índice do menor elemento

	while(!in_order(ps) || ps->size_sb) // enquanto ainda não estiver arrumado, ou ainda tiver elementos na pilha b, segue-se com as ações abaixo
	{
		i_low_nb = index_low_nb(ps); // rebere o índice do menor elemento da pilha a
		if (ps->size_sb == 2) // se tiver 2 elementos na pilha b, temos então 3 na pilha a
		{
			order_three(ps); // ordenamos os 3 da pilha a
			move_pa(ps); // trazemos de volta o topo da pilha b, pra pilha a 
			move_pa(ps); // trazemos de volta o topo da pilha b, pra pilha a 
		}
		else if (i_low_nb == ps->size_sa -1 && ps->size_sb < 2) // se o índice for 0, e a pilha b tiver menos de 2 elemnetos
			move_pb(ps); // passamos o elemento do topo da pilha a pro topo da pilha do lado	
		else if (ps->size_sb < 2 && i_low_nb > 2 && i_low_nb != ps->size_sa -1) // se tiver 0 ou 1 elemento na pilha b, e o menor elemento da pilha A estiver em no índice 3 ou 4 (isto é tá quase no topo da pilha), e não for o topo
			move_ra(ps); // jogamos o elemento do topo pilha a pro fim dessa mesma pilha
		else if (ps->size_sb < 2 && i_low_nb < 3 && i_low_nb != ps->size_sa -1) // se tiver 0 ou 1 elemento na pilha b, e o menor elemento da pilha A estiver em no índice 0 ou 1, e não for o topo
			move_rra(ps);
	}
}

// divide a pilha de até 100 números em blocos (subdivide por 5)
void	order_hundred(t_ps *ps, int division)
{
	int	portion; // porções da pilha a 

	if (in_order(ps))
		return;
	portion = 0; // inicia em zero
	while (ps->size_sa > 1) // enquanto ainda tiver algo na pilha a // economiza mandar o maior pra lá
	{
		portion = portion + division; // a porção trabalhada ganha mais um bloco (divisão)
		if ((float)ps->size_sa / 5 > 5) // se o tamanho da pilha a ainda for divisivel por 5 
			division = ps->size_sa / 5; // divisão recebe o tam da pilha a divivido por 5
		while (ps->size_sa && ps->size_sb < portion ) // enquanto houver elementos na pilha a, e a pilha b for menor do que a porção trabalhada...
		{
			choice_mov_hundred(ps, portion); // escolhemos o melhor movimento a se fazer
			bigger_to_top(ps, find_predecessor_in_b(ps, ps->sa[ps->size_sa - 1]), ps->size_sb, 'b'); // levamos o maior número pro topo
			move_pb(ps); // movemos para a pilha b
			// printf("pilha a: ");
			// for(int i=0; i < ps->size_sa; i++)
			// 	printf("%d ", ps->sa[i]);
			// printf("\n");
			// printf("pilha b: ");
			// for(int i=0; i < ps->size_sb; i++)
			// 	printf("%d ", ps->sb[i]);
			// printf("\n");
			//sleep (1);
		}
	}
	bigger_to_top(ps, index_bigger_nb(ps->sb, ps->size_sb), ps->size_sb, 'b'); // levamos o maior número pro topo
	while (ps->size_sb) // enquanto tiver algo na pilha b
		move_pa(ps); // movemos toda a pilha b para a pilha a
}

void	order_large_numbers(t_ps *ps)
{
	t_div	portion; // as pilhas serão trabalhadas em porções/ ou subdivisões
	
	portion.max = 0;
	while (ps->size_sa)
	{
		portion = info_portion_a(ps, portion);
		move_in_portion('b', ps, portion);
	}
	portion.min = ps->size_sa + ps->size_sb;
	while (ps->size_sb)
	{
		portion = info_portion_b(ps, portion);
		move_in_portion('a', ps, portion);
	}
	portion.max = (ps->size_sa + ps->size_sb) / 48;
	while (ps->size_sa)
	{
		portion = re_info_portion_a(ps, portion);
		move_in_portion('b', ps, portion);
	}
	while (ps->size_sb)
	{
		bigger_to_top(ps, index_bigger_nb(ps->sb, ps->size_sb), ps->size_sb, 'b');
		move_pa(ps);
	}
}
