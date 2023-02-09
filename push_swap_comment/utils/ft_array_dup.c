/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:55:07 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 12:17:42 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ACABOU NÃO SENDO USADA
// duplica um array até o tamanho passado
int	*ft_array_dup(int *arr, int size)
{
	int	*arr_cpy; // vai armazenar o novo array
	int	i; // índex

	i = 0;
	arr_cpy = (int *) malloc (sizeof(int) * size); // aloca o novo array
	while (i < size) // enquanto não acabar
	{
		arr_cpy[i] = arr[i]; // copia o array pra cópia
		i++;
	}
	return (arr_cpy); // retorna o array copiado
}
