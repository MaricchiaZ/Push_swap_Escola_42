/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 10:19:23 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/02 11:31:21 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
	{
		if (str[0] == '-' || str[0] == '+' )
			i++;
		while (str[i] >= 48 && str[i] <= 57)
			i++;
		if (str[i] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}
