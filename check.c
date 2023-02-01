/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:30:30 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/01 13:39:20 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// confere se tem 2 ou mais argugumentos e se os args são compostos apenas por números
int check_args(int argc, char **argv)
{
	int	i;

	i = 1;
	if(argc >= 2) // se tivermos 2 ou mais argvs
	{
		while(i < argc) 
		{
			if (ft_str_is_numeric(argv[i]) == 1) // enquanto for algarismo do 0 ao 9
				i++;
			else 
			{
				write(2, "Error\n", 7); // se encontrar algo não numérico nos argumentos
				return (0); // aviso de erro
			}
		}
		if (i == argc) // percorremos todos os argvs
			return (1); // está td ok
	}
	return (0); // temos menos de 2 argumentos - NESTE CASO - não devemos dar mensagem de erro
}

// confere se os números estão dentro do range do INT, e transforma os argvs em ints (atoi) e malloca a pilha a e a pilha b
t_ps	*valid_args(int argc, char **argv, t_ps *ps)
{
	int			i;
	long int	nb_temp;

	i = 0;
	ps->size_sa = argc - 1;
	ps->size_sb = 0;
	ps->sa = (int *) ft_calloc (sizeof (int), (argc - 1)); //argc - 1 (sem o a.out)
	ps->sb = (int *) ft_calloc (sizeof (int), (argc - 1)); //argc - 1 (sem o a.out)
	while (argc - 1 > 0) // enquanto n acabarmos de percorrer os argvs
	{
		nb_temp = ft_atolongi(argv[argc - 1]);
		if ((nb_temp <= 2147483647) && (nb_temp >= -2147483648))
			ps->sa[i] = (int)nb_temp;
		else
		{
			ps->valid_args = 0; // a variável que recebe a checagem "valid_args", recebe 0 = erro
			free(ps->sa); // liberamos a pilha a
			free(ps->sb); // liberamos a pilha b
			write(2, "Error\n", 7); // mensagem de erro
			return (ps); // retornamos a struct
		}
		i++; // vamos para o próximo argv
		argc--;
	}
	ps->valid_args = 1; // a variável que recebe a checagem "valid_args", recebe 1 = tudo OK
	return (ps); // retornamos a struct
}

int	duplicate(t_ps *ps)
{
	int i; // índice percorre todos os elementos da stack a
	int	check; // checa se mais algum elemento se iguala a stack_a[i]
	
	i = 0; // da posição 0 até o fim dos elementos de a
	while (i < ps->size_sa) // até olhar tds elementos de a
	{
		check = i + 1; // compara ps->sa[i] com ps->sa[i + 1]
		while (check < ps->size_sa) // até olhar tds elementos de a
		{
			if (ps->sa[i] == ps->sa[check]) // se ps->sa[i] é igual a qqr elemento que vem depois dele ... erro encontrado
			{
				write(2, "Error\n", 7);
				return (0); // falso
			}
			check++; // próxima comparação
		}
		i++; // andamos mais um na pilha a
	}
	change_nb_to_index(ps);
	return (1); // ok, não temos nd duplicado
}

void	change_nb_to_index(t_ps *ps)
{
	int	i;
	int	check;
	int	index_nb;
	int	*new_sa; // calocca o tam da stack a
	
	check = 0;
	new_sa = (int *)ft_calloc(ps->size_sa, sizeof(int));
	if (!new_sa)  // se o calloc der erro
	{
		write(1, "Error\n", 7);
		exit (MALLOC_ERROR);
	}
	while (check < ps->size_sa) // enquanto check menor que a stackA
	{
		i = 0;
		index_nb = 0;
		while (i < ps->size_sa)// check - ciclo externo/ i ciclo interno (compara tdos os i com cada check, salva a posição no index)
		{
			if (ps->sa[i] < ps->sa[check]) // ele anda qnts elementos tiverem menor q ele...
				index_nb++;
			i++;
		}
		new_sa[check] = index_nb; // salvando assim as posições de cada elemento nessa pilha auxiliar
		check++;
	}
	free(ps->sa);
	ps->sa = new_sa; // salva as posiçoes na a->stk
	// printf("pilha: ");
	// for(int i=0; i < ps->size_sa; i++)
	// 	printf("%d ", ps->sa[i]);
	// printf("\n");
}