/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal_integer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/22 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		di_width(t_info *s, int nbr, int nbrlen, int z)
{
	if (s->flag[ZERO] == '1' && z == 0)
	{
		if (s->point != 0)
			while (--s->width > nbrlen)
				ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
		if (s->point == 0)
			while (--s->width > nbrlen)
				ft_putchar('0');
	}
	else
	{
		while (--s->width > nbrlen + z)
			ft_putchar(' ');
		if (nbr < 0)
			ft_putchar('-');
	}
	ft_putnchar('0', z);
	if (s->point != 1 || nbr != 0)
		ft_putnbr(nbr);
}

static int		di_length(t_info *s, int nbr)
{
	int		nbrlen;

	nbrlen = ft_nbrlen(nbr);
	if (s->point == 1 && nbr == 0)
		nbrlen--;
	if (nbr < 0)
		nbrlen++;
	return (nbrlen);
}

static void		di_minus(t_info *s, int nbr, int nbrlen, int z)
{
	if (nbr < 0)
		ft_putchar('-');
	ft_putnchar('0', z);
	if (s->point != 1 || nbr != 0)
		ft_putnbr(nbr);
	if (s->width > nbrlen)
		while (--s->width > nbrlen + z)
			ft_putchar(' ');
}

static void		di_nonminus(t_info *s, int nbr, int nbrlen, int z)
{
	if (s->width > nbrlen)
		di_width(s, nbr, nbrlen, z);
	else
	{
		if (nbr < 0)
			ft_putchar('-');
		ft_putnchar('0', z);
		if (s->point != 1 || nbr != 0)
			ft_putnbr(nbr);
	}
}

t_info			*print_decimal_integer(t_info *s)
{
	int		nbr;
	int		nbrlen;
	int		z;

	nbr = va_arg(s->ap, int);
	nbrlen = di_length(s, nbr);
	z = s->prec - ft_nbrlen(nbr);
	if (z < 0)
		z = 0;
	if (s->width <= s->prec)
		s->len += z;
	if (s->width > nbrlen && s->width > s->prec)
	{
		s->len += s->width - nbrlen;
		s->width++;
	}
	s->flag[MINUS] == '1' ? di_minus(s, nbr, nbrlen, z) :
		di_nonminus(s, nbr, nbrlen, z);
	s->len += nbrlen;
	return (s);
}
