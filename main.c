/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 19:22:26 by romain            #+#    #+#             */
/*   Updated: 2021/05/23 21:37:42 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pushswap.h"
/*
**Permitted functions are write, read, malloc, free, exit
**sort numbers
**Remember argc is always 1 more and argv[0] is ./a.out
**COMMAND LISTS:
**sa/sb == swap top 2 ints of stack A/B;
**ss == sa and sb simultaneously
**pa/pb == push top int from B onto top of A
**ra/rb == shift everything up by one, first element goes to the back
**rr == ra and rb at the same time
**rra/rrb == shift everything down by one, last element goes to the front
**rrr == rra and rrb at the same time
*/
int main(int argc, char **argv)
{
	printf("%d\n", argc);
	if (argc <= 1)
		return (printf("ERROR\n"));
	else if (argc == 2)
		return (0);
	ft_pushswap(argc, argv);
	
}