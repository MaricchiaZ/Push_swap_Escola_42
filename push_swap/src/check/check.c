/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:30:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/03 21:34:56 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			if (ft_str_is_numeric(argv[i]) == 1)
				i++;
			else
			{
				write(2, "Error\n", 6);
				return (0);
			}
		}
		if (i == argc)
			return (1);
	}
	return (0);
}

t_ps	*valid_args(int argc, char **argv, t_ps *ps)
{
	int			i;
	long int	nb_temp;

	i = 0;
	ps->size_sa = argc - 1;
	ps->size_sb = 0;
	ps->sa = (int *) ft_calloc (sizeof (int), (argc - 1));
	if (!ps->sa)
		exit_and_free(ps);
	while (argc - 1 > 0)
	{
		nb_temp = ft_atolongi(argv[argc - 1]);
		if ((nb_temp <= 2147483647) && (nb_temp >= -2147483648))
			ps->sa[i] = (int)nb_temp;
		else
			exit_and_free(ps);
		i++;
		argc--;
	}
	return (ps);
}

void	duplicate(t_ps *ps)
{
	int	i;
	int	check;

	i = 0;
	while (i < ps->size_sa)
	{
		check = i + 1;
		while (check < ps->size_sa)
		{
			if (ps->sa[i] == ps->sa[check])
				exit_and_free(ps);
			check++;
		}
		i++;
	}
	ps->sb = (int *) ft_calloc (sizeof (int), ps->size_sa);
	if (!ps->sb)
		exit_and_free(ps);
	change_nb_to_index(ps);
}

void	change_nb_to_index(t_ps *ps)
{
	int	i;
	int	check;
	int	index_nb;
	int	*new_sa;

	check = 0;
	new_sa = (int *)ft_calloc(ps->size_sa, sizeof(int));
	if (!new_sa)
		exit_and_free(ps);
	while (check < ps->size_sa)
	{
		i = 0;
		index_nb = 0;
		while (i < ps->size_sa)
		{
			if (ps->sa[i] < ps->sa[check])
				index_nb++;
			i++;
		}
		new_sa[check] = index_nb;
		check++;
	}
	free(ps->sa);
	ps->sa = new_sa;
}
