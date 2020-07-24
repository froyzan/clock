/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/16 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		length(t_info *s, unsigned int nbr)
{
	int		nbrlen;

	nbrlen = 0;
	if (nbr == 0 && s->point != 1)
		nbrlen++;
	while (nbr > 0)
	{
		nbrlen++;
		nbr /= 16;
	}
	return (nbrlen);
}

static void		minus(t_info *s, unsigned int nbr, int nbrlen, int z)
{
	ft_putnchar('0', z);
	if (s->point != 1 || nbr != 0)
		ft_puthex(nbr, *s->fm);
	if (s->width > nbrlen)
		while (--s->width > nbrlen + z)
			ft_putchar(' ');
}

static void		nonminus(t_info *s, unsigned int nbr, int nbrlen, int z)
{
	if (s->width > nbrlen && (s->flag[ZERO] != '1' || s->point != 0))
		while (--s->width > nbrlen + z)
			ft_putchar(' ');
	if (s->width > nbrlen && s->flag[ZERO] == '1' && s->point == 0)
		while (--s->width > nbrlen + z)
			ft_putchar('0');
	ft_putnchar('0', z);
	if (s->point != 1 || nbr != 0)
		ft_puthex(nbr, *s->fm);
}

t_info			*print_hexadecimal(t_info *s)
{
	unsigned int	nbr;
	int				nbrlen;
	int				z;

	nbr = va_arg(s->ap, unsigned int);
	nbrlen = length(s, nbr);
	z = s->prec - nbrlen;
	if (z < 0)
		z = 0;
	if ((s->width <= s->prec) || (nbr != 0 && s->width <= s->prec))
		s->len += z;
	if (s->width > nbrlen && s->width > s->prec)
	{
		s->len += s->width - nbrlen;
		s->width++;
	}
	s->flag[MINUS] == '1' ? minus(s, nbr, nbrlen, z) :
		nonminus(s, nbr, nbrlen, z);
	s->len += nbrlen;
	return (s);
}
