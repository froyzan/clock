/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/16 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_strnbr(char *sp)
{
	int		nb;
	int		flag;

	nb = 0;
	flag = 0;
	while (*sp)
	{
		while (*sp >= '0' && *sp <= '9')
		{
			flag = 1;
			nb = nb * 10 + *sp - '0';
			sp++;
		}
		if (flag == 1)
			break ;
		sp++;
	}
	return (nb);
}
