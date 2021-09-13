/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rponsonn <rponsonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 00:57:50 by romain            #+#    #+#             */
/*   Updated: 2021/09/13 16:53:19 by rponsonn         ###   ########.fr       */
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
	int i;

	i = 0;
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
