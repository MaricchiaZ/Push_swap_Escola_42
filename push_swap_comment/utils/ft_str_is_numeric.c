/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:19:23 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 11:38:56 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// confere se os elementos de uma string são números, retorna 1 quando só encontrar números, e retona 0 se encontrar algo diferente
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0') // se a string estiver vazia
		return (0);
	while (str[i] != '\0') // enquanto não acabar de percorrer a string 
	{
		if (str[0] == '-' || str[0] == '+' ) // se for sinal na primeira posição, avança uma casa
			i++;
		while (str[i] >= 48 && str[i] <= 57) // avança se encontrar apenas caracteres do 0 ao 9
			i++;
		if (str[i] == '\0') // se chegar no fim da string, só tinha números
			return (1); // retornamos ok
		else
			return (0);// caso contrário, retornamos erro
	}
	return (0);
}