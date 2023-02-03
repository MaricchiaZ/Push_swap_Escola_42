/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 11:35:48 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/03 22:07:34 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// funçao que econtra e retorna a posição na pilha em que se encontra o menor elemento
unsigned int	index_low_nb(t_ps *ps)
{
	int				i; // índice que percorre a pilha a
	int				low_nb; // vai salvar o menor valor encontrado na pilha a
	unsigned int	index_low_nb; // vai salvar a posição [índice] do menor número da pilha a

	i = 0; // índice começa em zer
	low_nb = ps->sa[0]; //vamos comparar com a posiçao 1
	index_low_nb = 0; // salvamos o índice da posição que estamos analisando
	while (i < ps->size_sa) // enquanto não acabarmos de olhar toda a pilha a
	{
		if (ps->sa[i] < low_nb) // se a posição que estamos tem um elemento menor que o menor salvo em low_nb
		{
			low_nb = ps->sa[i]; // salvamos esse menor elemento
			index_low_nb = i; // e salvamos a posição de onde se encontra esse menor elemento
		}
		i++; // seguimos até o fim da pilha/stack a
	}
	return (index_low_nb); // retornamos o índice do menor elemento
}

// função que encontra a posição do maior número da pilha/stack e retorna o índice de onde se encontra esse número
unsigned int	index_bigger_nb(int *stack, int size_s) // recebe a pilha e o tamanho da pilha
{
	unsigned int	i; // índice que vai percorrer a pilha
	int				bigger_nb; // variável que vai salvar o maior número encontrado
	unsigned int	index_bigger_nb; // variável que vai salvar o índice do maior número

	if (!size_s) // se n tiver nada na pilha, ou o tamanho da pilha for 0
		return (0); // retorna-se zero
	i = 1; // vamos comparar a posição 1 com a zero
	bigger_nb = stack[0]; // salvamos o valor zero na variável bigger_nb
	index_bigger_nb = 0; // e o índice da posição 0 é salvo aqui
	while (i < (unsigned int)size_s) // enquanto não acabarmos de observar a pilha
	{
		if (stack[i] > bigger_nb) //se o número que estamos olhando da pilha for maior do que o já salvo, vamos sobrescrevê-lo
		{
			bigger_nb = stack[i]; // salvamos no número atual em the_bigger
			index_bigger_nb = i; // e seu índice em index_bigger_nb 
		}
		i++; // continuamos olhando a pilha
	}
	return (index_bigger_nb); // retornamos o índice do maior número da pilha
}

// buscamos um menor número dentro da faixa escolhida, e vemos se está no início ou no fim da pilha, se a posição for == size - 1, veremos um pb, se for próximo ao topo r, proximo ao fim rr
int	near_pos_to_move(int *stack, int stack_size, int range, int min_range)
{
	int	i; // percorre a pilha
	int	near_pos; // salva o índice do número de interesse

	i = 0;
	near_pos = 0;
	if (stack_size < 20)
		return(stack_size - 1);
	while (i < stack_size) // enquanto não acabarmos a pilha a
	{
		if (min_range <= stack[i] && stack[i] < range) // procuramos o primeiro número que tenha o valor dentre a faixa de números que estamos trabalhando que vai do min_range até o range
		{
			near_pos = i; // salvamos a posição em near_pos
			break ; // paramos o while
		}
		i++; // avançamos na pilha fazendo a nossa busca
	}
	i = stack_size - 1; // agora olhamos de traz pra frente a pilha 
	while (i < stack_size && i > stack_size - near_pos) // olhamos agora no fim da pilha se existe algum número de posição melhor para movimentar, e que esteja mais próxima do fim da pilha do que o número que encontramos no while de cima está do início da pilha 
	{
		if (min_range <= stack[i] && stack[i] < range) // se encontrarmos um número pertencente a faixa trabalhada
		{
			near_pos = i; // salvamos a posição dele em near_pos
			break ; // paramos o while
		}
		i--; // retrocedemos na pilha fazendo a nossa busca
	}
	// printf("min_range %d\n", min_range);
	// printf("range %d\n", range);
	// printf("size a %d\n", stack_size);
	// printf("near_pos %d\n", near_pos);
	return (near_pos); // entregamos a posição encontrada
}

// função que retorna o índice onde se encontra o antecessor do número passado
int	find_predecessor_in_b(t_ps *ps, int nb)
{
	int	i; // índice que percorre a stack
	int	predecessor; // antecessor (o número que vem antes do que estamos olhando)
	int	pred_i; // índice do antecessor encontrado
	int	check_pred; // var pra checar se encontramos o precessor (0 = n encontramos/ 1 = achamos)

	i = 0; 
	predecessor = -1; // começa em -1 pq o antecesor pode ser o 0
	pred_i = 0;
	check_pred = 0;
	while (ps->sb && i < ps->size_sb) // enquanto tiver pilha b, e i não tiver percorrido toda a pilha b
	{
		if (predecessor < ps->sb[i] && ps->sb[i] < nb) // se o número que estamos na pilha b ps->sb[i] for menor que o número de interesse nb, ele vai sendo reescrito até encontrarmos o antecessor de nb
		{
			predecessor = ps->sb[i]; // salvamos esse número no antecessor
			pred_i = i; // salvamos seu índice
			check_pred = 1; // checagem vale 1
		}
		i++;
	}
	if (!check_pred) // se for zero, não encontramos um número anterior a ele
		return (index_bigger_nb(ps->sb, ps->size_sb)); // rodamos essa outra função, e achamos o maior número da stack b
	return (pred_i); // senão retornamos o índice onde se encontra o antecessor
}

// função que leva o maior número para o topo da pilha trabalhada
void	bigger_to_top(t_ps *ps, unsigned int index_bigger, unsigned int size, char stack)
{
	int	distance; // distância da posição do índice até o topo
	
	if (index_bigger >= size / 2) // se o índice encontra-se até a metade da altura da pilha, 
		distance = size - index_bigger - 1; // a distância recebe o valor do índice
	else
		distance = index_bigger + 1; // caso contrário a distância recebe o tamanho menos o índice (mov reverso)
	while (distance > 0) // enquanto a distância for maior q zero
	{
		if (stack == 'a') // se estivermos trabalhando com a pilha a
			exec_moves(ps, best_mov_r_or_rr(ps, ps->sa, NULL, index_bigger, 0)); // executamos na pilha A o melhor movimento entre ra, rb, rr, rra, rrb e rrr
		else if (stack == 'b') // se estivermos trabalhando com a pilha b
			exec_moves(ps, best_mov_r_or_rr(ps, NULL, ps->sb, 0, index_bigger)); // executamos na pilha B o movimento entre ra, rb, rr, rra, rrb e rrr
		distance--;
	}
}

//./push_swap 6778990 10 -2 8 -1234 786 9