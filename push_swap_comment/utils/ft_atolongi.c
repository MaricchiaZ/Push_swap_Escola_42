/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:05:43 by maclara-          #+#    #+#             */
/*   Updated: 2022/09/01 12:05:43 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// atoi - passa um número de string char para um int -que consegue lidar com um long int (evita segmentation fault com números maiores que INT_MAX e INT_MIN
long int	ft_atolongi(const char *nptr)
{
	int	i; // índex
	int	signal; // recebe os sinais dos números
	long int	nb; // armazena o número

	i = 0;
	signal = 1;
	nb = 0;
	if (!nptr[i]) // se não tiver nada na string
		return (0);
	while ((nptr[i] == '\t') || (nptr[i] == '\v') || (nptr[i] == '\f') || \
	(nptr[i] == '\n') || (nptr[i] == '\r') || (nptr[i] == ' ')) // se for espaço ou tabulação
		i = i + 1; // pulamos
	if (nptr[i] == '+' || nptr[i] == '-') // se for sinal
	{
		if (nptr[i] == '-') // e for negativo
			signal *= -1; // signal passa a valer -1
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57) // se for algo entre 0 e 9 
	{
		nb = (nb * 10) + (nptr[i] - 48); // convertemos para int e vemos seu valor relativo
		i++;
	}
	return (nb * signal); // retornamos o número multiplicado pelo sinal
}
