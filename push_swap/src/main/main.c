/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:25:55 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/03 18:45:58 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	ps;

	ps.sb = NULL;
	ps.order_cmp = NULL;
	ps.size_sb = 0;
	if (check_args(argc, argv) == 0)
		return (-1);
	valid_args(argc, argv, &ps);
	duplicate(&ps);
	if (argc <= 4)
		order_three(&ps);
	ps.order_cmp = ft_array_dup(ps.sa, ps.size_sa);
	ft_sort_array(ps.order_cmp, ps.size_sa);
	if (argc <= 6)
		order_five(&ps);
	else if (argc <= 101)
		order_hundred(&ps, (float)ps.size_sa / 5);
	else
		order_large_numbers(&ps);
	free(ps.sa);
	free(ps.sb);
	free(ps.order_cmp);
	return (0);
}
