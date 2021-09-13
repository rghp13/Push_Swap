/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:57:50 by romain            #+#    #+#             */
/*   Updated: 2021/09/13 23:30:36 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_exit(t_cont *cont)
{
	ft_free(cont);
	ft_exit();
}

void	ft_free(t_cont *cont)
{
	int	i;

	i = 0;
	if (cont != NULL)
	{
		if (cont->a != NULL)
		{
			if (cont->a->stack != NULL)
				free(cont->a->stack);
			free(cont->a);
		}
		if (cont->b != NULL)
		{
			if (cont->b->stack != NULL)
				free(cont->b->stack);
			free(cont->b);
		}
		if (cont->separated != NULL)
		{
			while (cont->separated[i])
				free(cont->separated[i++]);
			free(cont->separated);
		}
		free(cont);
	}
}

void	ft_exit(void)
{
	printf("Error\n");
	exit(1);
}
