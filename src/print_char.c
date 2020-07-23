/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/22 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info	*print_char(t_info *s)
{
	char	c;

	c = (char)va_arg(s->ap, int);
	if (s->flag[MINUS] == '1')
		ft_putchar(c);
	if (s->width > 1)
	{
		s->len += s->width - 1;
		s->width++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
			while (--s->width > 1)
				ft_putchar('0');
		else
			while (--s->width > 1)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1')
		ft_putchar(c);
	s->len++;
	return (s);
}
