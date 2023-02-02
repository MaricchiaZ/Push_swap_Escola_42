/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:55:07 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 19:01:32 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_array_dup(int *arr, int size)
{
	int	*arr_cpy;
	int	i;

	i = 0;
	arr_cpy = (int *) malloc (sizeof(int) * size);
	while (i < size)
	{
		arr_cpy[i] = arr[i];
		i++;
	}
	return (arr_cpy);
}
