/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:40:22 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 19:47:11 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_array_cmp(int *arr1, int *arr2, int size_a)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (arr1[i] == arr2[i])
			i++;
		else
			return (0); // falso
	}
	if (i == size)
		return (1);
}
