/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:25:07 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 12:17:52 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ACABOU NÃO SENDO USADA
// função que ordena um array de tamanho size, de maneira crescente, pela técnica do Bubble sort
void	ft_sort_array(int *tab, int size)
{
	int	k; //contador do loop externo
	int	i; //contador do  loop interno 
	int	temp;

	k = 0;
	while (k < size - 1) // loop externo
	{
		i = 0;
		while (i < size - 1) // loop interno 
		{
			if (tab[i] > tab [i + 1]) // compara uma posição com a seguinte, se for maior
			{
				temp = tab [i]; // troca elas de posição
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		k++;
	}
}
