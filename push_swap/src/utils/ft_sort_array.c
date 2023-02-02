/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:25:07 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 13:25:51 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_array(int *tab, int size)
{
	int	k;
	int	i;
	int	temp;

	k = 0;
	while (k < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab [i + 1])
			{
				temp = tab [i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
		k++;
	}
}
