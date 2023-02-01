/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:40:22 by maclara-          #+#    #+#             */
/*   Updated: 2023/01/03 13:05:05 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_array_cmp(int *arr1, int *arr2, int size_a)
{
	int	i;

	i = 0;
	while(i < size_a)
	{
		if (arr1[i] == arr2[i])
			i++;
		else
		{
			printf("\n comparação errada1\n");
			return (0); // falso
		}
	}
	if (i == size_a)
	{
		printf("\n comparação certa\n");
		return (1);
	}
	printf("\n comparação errada2\n");
	return (0); // falso
}
