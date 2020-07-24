/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:20:34 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/18 16:22:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_puthex(unsigned int i, char c)
{
	if (i > 15)
	{
		ft_puthex(i / 16, c);
		ft_puthex(i % 16, c);
	}
	else
	{
		if (i <= 9)
			ft_putchar(i + '0');
		else
			c == 'x' ? ft_putchar(i - 10 + 'a') : ft_putchar(i - 10 + 'A');
	}
}
