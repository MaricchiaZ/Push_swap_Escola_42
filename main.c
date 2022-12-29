/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maclara- <maclara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 21:25:55 by maclara-          #+#    #+#             */
/*   Updated: 2022/12/28 19:53:03 by maclara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_ps	ps;
	ps.sb = NULL;
	ps.order_cmp = NULL;
	ps.size_sb = 0;
	
	if(check_args(argc, argv) == 0)
		return (-1);
	valid_args(argc, argv, &ps);
	if(ps.valid_args == 0)
		return (-1);
	// move_sa(&ps);
	// move_pb(&ps);
	// move_rra(&ps);
	if (argc == 4)
	{
		order_three(&ps);
		//return (0);		
	}
	ps.order_cmp = ft_array_dup(ps.sa, ps.size_sa);
	ft_sort_array(ps.order_cmp, ps.size_sa);
	int i = 0;
	printf("Print main|size sa: %d\nStack a: ", ps.size_sa);
	while(ps.sa && i < ps.size_sa)
	{
		printf("%d, ", ps.sa[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("Print main|size_sb: %d\nStack b: ", ps.size_sb);
	while(ps.order_cmp && i < ps.size_sb)
	{
		printf("%d, ", ps.sb[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("Print main|size_sb: %d\nStack sort_a: ", ps.size_sa);
	while(ps.sb && i < ps.size_sa)
	{
		printf("%d, ", ps.order_cmp[i]);
		i++;
	}
	printf("\n");
	//ver se for 3
	//e for 5
	//se for outros;;;
	//free(ps.sb); // ---------- AINDA N SEI COMO DAR FREE NESSA VARIÁVEL -------------
	write(1, "MAIN LIDA\n", 11);
	return (0);
}

/*

./push_swap 1 3 6 -52147483

valgrind --leak-check=full  ./push_swap 1 3 6 -52147483


*/

