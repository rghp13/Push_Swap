/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:57:50 by romain            #+#    #+#             */
/*   Updated: 2021/05/27 19:32:16 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_exit(t_cont *cont)
{
	if (cont != NULL)
	{
		if (cont->A != NULL)
		{
			if (cont->A->stack != NULL)
				free(cont->A->stack);
			free(cont->A);
		}
		if (cont->B != NULL)
		{
			if (cont->B->stack != NULL)
				free(cont->B->stack);
			free(cont->B);
		}
		free(cont);
	}
	ft_exit();
}

void	ft_exit(void)
{
	printf("Error\n");
	exit(1);
}