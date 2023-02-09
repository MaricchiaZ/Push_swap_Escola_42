/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:30:05 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 11:31:50 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// função auxiliar que coloca o byte nulo numa string, até o tamanho n
static void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (n && s)
	{
		*(unsigned char *)(s + i) = '\0'; // percorre a string colocando byte nulo
		i++;
		n--;
	}
}

// função que malloca espaço para n membros de tamanho size
void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	aux;
	void	*tab;

	if (nmemb == 0)
		return (NULL);
	if (nmemb > 2147483647 || size > 2147483647 || size * nmemb > 2147483647) // se estourar o INT_MAX
		return (NULL);
	aux = (size) * (nmemb);
	tab = malloc(aux); // malloca o tamanho desejado
	if (tab == NULL) // se der erro no malloc
		return (NULL);
	ft_bzero(tab, aux); // coloca byte nulo em todos os espaços mallocados
	return (tab);
}