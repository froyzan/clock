/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 16:20:34 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/18 16:22:24 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_putnbr(long long i)
{
	if ((unsigned long long)i == -9223372036854775808U)
		ft_putstr("9223372036854775808");
	else if (i < 0)
		ft_putnbr(i * -1);
	else if (i >= 0 && i <= 9)
		ft_putchar('0' + i);
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}
