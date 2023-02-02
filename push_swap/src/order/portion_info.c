/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portion_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:16:06 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/02 11:16:36 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_div	info_portion_a(t_ps *ps, t_div portion)
{
	portion.min = portion.max;
	if (portion.max == 0)
		portion.max = (ps->size_sa + ps->size_sb) / 2;
	else if (portion.max < (ps->size_sa + ps->size_sb) - \
	(ps->size_sa + ps->size_sb) / 24)
		portion.max = portion.max + portion.max / 2;
	else
		portion.max = ps->size_sa + ps->size_sb;
	portion.half = portion.min + (portion.max - portion.min) / 2;
	return (portion);
}

t_div	info_portion_b(t_ps *ps, t_div portion)
{
	portion.max = portion.min;
	if (portion.max == 0)
		portion.max = (ps->size_sa + ps->size_sb);
	portion.min = portion.min - (ps->size_sa + ps->size_sb) / 12;
	if (portion.min > (ps->size_sa + ps->size_sb))
		portion.min = 0;
	portion.half = portion.min + (portion.max - portion.min) / 2;
	return (portion);
}

t_div	re_info_portion_a(t_ps *ps, t_div portion)
{
	portion.min = portion.max;
	if (portion.min == (ps->size_sa + ps->size_sb) / 48)
		portion.min = 0;
	portion.max = portion.max + ((ps->size_sa + ps->size_sb) / 48);
	portion.half = portion.min + (portion.max - portion.min) / 2;
	return (portion);
}
