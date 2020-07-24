/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/16 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		length(t_info *s, unsigned long long nbr)
{
	int		nbrlen;

	nbrlen = 0;
	if (nbr == 0 && s->point != 1)
		nbrlen++;
	while (nbr > 0)
	{
		nbrlen++;
		nbr /= 10;
	}
	return (nbrlen);
}

static t_info	*print_unsigned_int_3
	(t_info *s, unsigned long long nbr, int nbrlen, int z)
{
	s->width++;
	if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1' && z == 0)
	{
		if (s->point != 0)
			while (--s->width > nbrlen)
				ft_putchar(' ');
		else
			while (--s->width > nbrlen)
				ft_putchar('0');
	}
	else
	{
		if (s->point != 1 || nbr != 0)
			while (--s->width > nbrlen + z)
				ft_putchar(' ');
		else
			while (--s->width > 0)
				ft_putchar(' ');
	}
	return (s);
}

static t_info	*print_unsigned_int_2
	(t_info *s, unsigned long long nbr, int nbrlen, int z)
{
	if (s->flag[MINUS] == '1' && (s->point != 1 || nbr != 0))
	{
		ft_putnchar('0', z);
		ft_putui(nbr);
	}
	if (s->width <= s->prec)
		s->len += z;
	if (s->width > nbrlen && s->width > s->prec)
		s->len += s->width - nbrlen;
	if (s->width > nbrlen)
		s = print_unsigned_int_3(s, nbr, nbrlen, z);
	if (s->flag[MINUS] != '1' && (s->point != 1 || nbr != 0))
	{
		ft_putnchar('0', z);
		ft_putui(nbr);
	}
	return (s);
}

t_info			*print_unsigned_int(t_info *s)
{
	unsigned long long	nbr;
	int					nbrlen;
	int					z;

	nbr = va_arg(s->ap, unsigned long long);
	nbrlen = length(s, nbr);
	z = s->prec - nbrlen;
	if (z < 0)
		z = 0;
	s = print_unsigned_int_2(s, nbr, nbrlen, z);
	s->len += nbrlen;
	return (s);
}
