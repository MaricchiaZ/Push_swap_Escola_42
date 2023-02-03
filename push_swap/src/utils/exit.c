/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:41:25 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/03 21:36:26 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_and_free(t_ps *ps)
{
	write(2, "Error\n", 6);
	if (ps->sa)
		free (ps->sa);
	if (ps->sb)
		free (ps->sb);
	exit(ERROR);
}
