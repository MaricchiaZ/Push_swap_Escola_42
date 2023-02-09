/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:25:55 by maclara-          #+#    #+#             */
/*   Updated: 2023/02/09 12:21:22 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	ps; // declara a struct
	ps.sb = NULL; // inicializa a struct
	ps.size_sb = 0;
	
	if(check_args(argc, argv) == 0) // confere se os args existem
		return (-1);
	valid_args(argc, argv, &ps); // confere se os args são valores válidos
	if (ps.valid_args == 0)
		return (-1);
	if (duplicate(&ps) == 0) // confere se os números não são duplicados e indexa eles (troca os números pela sequêcia 0,1,2...)
		return (-1);
	if (argc <= 4) // até 3 números 
		order_three(&ps); // ordena por essa função
	if (argc <= 6) // até 5 números 
		order_five(&ps);
	else if (argc <= 101) // até 100 números
		order_hundred(&ps, (float)ps.size_sa / 5);
	else // mais de 100 números
		order_large_numbers(&ps);
	// printf("pilha a: ");
	// for(int i=0; i < ps.size_sa; i++)
	// 	printf("%d ", ps.sa[i]);
	// printf("\n");
	free(ps.sa); // libera a memória das pilhas
	free(ps.sb); // libera a memória das pilhas
	return (0);
}

/*

./push_swap 1 3 6 -52147483

./push_swap 63 88 69 15 94 11 93 3 49 76 5 80 44 20 58 13 62 82 23 79 9 2 73 60 66 72 4 37 39 27 51 83 19 16 87 90 8 53 98 25 45 61 74 71 17 86 78 95 31 56 30 26 70 40 68 47 33 38 41 28 18 29 84 65 6 42 96 21 52 55 14 35 1 89 99 75 59 22 64 48 92 50 34 36 57 85 97 100 7 12 67 32 77 43 10 54 91 24 46 81 

./push_swap 75 85 34 84 72 71 33 30 65 74 83 22 3 21 12 36 32 86 50 23 45 10 68 15 14 58 66 70 48 59 87 67 76 19 29 90 54 61 91 20 18 7 37 95 51 88 6 55 94 2 80 73 57 62 92 98 13 24 43 17 56 1 28 35 42 38 16 96 69 81 39 49 31 25 97 89 100 40 78 8 44 64 53 46 11 26 9 27 77 79 99 4 93 63 52 41 82 47 5 60 


valgrind --leak-check=full  ./push_swap 1 3 6 -52147483


*/

