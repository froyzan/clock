/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/22 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		output(t_info *s, unsigned long long ptr, int ptrlen, int z)
{
	if (s->flag[MINUS] == '1' || (s->flag[ZERO] == '1' && z == 0))
	{
		ft_putstr("0x");
		ft_putnchar('0', z);
	}
	if (s->flag[MINUS] == '1' && (ptr != 0 || s->point != 1))
		ft_puthex(ptr, 'x');
	if (s->width > ptrlen && s->width > s->prec)
	{
		s->len += s->width - ptrlen;
		s->width++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1' && z != 0)
			while (--s->width > ptrlen)
				ft_putchar('0');
		else
			while (--s->width > ptrlen + z)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1' && (s->flag[ZERO] != '1' || z != 0))
	{
		ft_putstr("0x");
		ft_putnchar('0', z);
	}
	if (s->flag[MINUS] != '1' && (ptr != 0 || s->point != 1))
		ft_puthex(ptr, 'x');
}

t_info			*print_pointer(t_info *s)
{
	unsigned long long	ptr;
	unsigned long long	temp;
	int					ptrlen;
	int					z;

	ptr = (unsigned long long)va_arg(s->ap, void *);
	temp = ptr;
	ptrlen = 2;
	if (temp == 0 && s->point != 1)
		ptrlen++;
	while (temp > 0)
	{
		ptrlen++;
		temp /= 16;
	}
	z = s->prec - ptrlen + 2;
	if (z < 0)
		z = 0;
	if (s->width <= s->prec && z != 0)
		s->len += z;
	output(s, ptr, ptrlen, z);
	s->len += ptrlen;
	return (s);
}
