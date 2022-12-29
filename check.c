/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:30:30 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 11:54:49 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc >= 2)
	{
		while(i < argc)
		{
			if (ft_str_is_numeric(argv[i]) == 1)
				i++;
			else 
			{
				write(1, "Error\nnon-numeric arguments found\n", 35);
				return (0);
			}
		}
		if (i == argc)
			return (1);
	}
	write(1, "Error\ninvalid argument number\n", 31);
	return (0);
}

t_ps	*valid_args(int argc, char **argv, t_ps *ps)
{
	int			i;
	long int	nb_temp;

	i = 1;
	ps->size_sa = argc - 1;
	ps->size_sb = 0;
	ps->sa = (int *) malloc (sizeof (int) * (argc - 1)); //argc - 1 (sem o a.out)
	ps->sb = (int *) malloc (sizeof (int) * (argc - 1)); //argc - 1 (sem o a.out)
	while (i < argc)
	{
		nb_temp = ft_atolongi(argv[i]);
		if ((nb_temp <= 2147483647) && (nb_temp >= -2147483648))
			ps->sa[i - 1] = (int)nb_temp;
		else
		{
			ps->valid_args = 0;
			free(ps->sa);
			write(1, "Error\nthe numbers exceed the value of int\n", 43);
			return (ps);
		}
		i++;
	}
	ps->valid_args = 1;
	return (ps);
}