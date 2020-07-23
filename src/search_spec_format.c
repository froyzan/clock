/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_spec_format.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/22 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info		*search_flag(t_info *s)
{
	s->flag[MINUS] = '0';
	s->flag[ZERO] = '0';
	while (*s->fm == '-' || *s->fm == '0')
	{
		if (*s->fm == '-')
			s->flag[MINUS] = '1';
		if (*s->fm == '0')
			s->flag[ZERO] = '1';
		s->fm++;
	}
	return (s);
}

t_info		*search_width(t_info *s)
{
	s->width = 0;
	if (*s->fm == '*')
	{
		s->width = va_arg(s->ap, int);
		if (s->width < 0)
		{
			s->width *= -1;
			s->flag[MINUS] = '1';
		}
		s->fm++;
	}
	if (*s->fm >= '0' && *s->fm <= '9')
		s->width = ft_strnbr((char *)s->fm);
	while (*s->fm >= '0' && *s->fm <= '9')
		s->fm++;
	return (s);
}

t_info		*search_precision(t_info *s)
{
	s->prec = 0;
	s->point = 0;
	if (*s->fm == '.')
	{
		s->point = 1;
		s->fm++;
		if (*s->fm == '*')
		{
			s->prec = va_arg(s->ap, int);
			if (s->prec < 0)
			{
				s->prec = 0;
				s->point = 0;
			}
			s->fm++;
		}
		if (*s->fm >= '0' && *s->fm <= '9' && s->prec == 0)
			s->prec = ft_strnbr((char *)s->fm);
		while (*s->fm >= '0' && *s->fm <= '9')
			s->fm++;
		if (s->prec > 0)
			s->point = 2;
	}
	return (s);
}

t_info		*search_type(t_info *s)
{
	if (*s->fm == 'c')
		s = print_char(s);
	else if (*s->fm == 's')
		s = print_string(s);
	else if (*s->fm == 'p')
		s = print_pointer(s);
	else if (*s->fm == 'd' || *s->fm == 'i')
		s = print_decimal_integer(s);
	else if (*s->fm == 'u')
		s = print_unsigned_int(s);
	else if (*s->fm == 'x' || *s->fm == 'X')
		s = print_hexadecimal(s);
	else if (*s->fm == '%')
		s = print_percentage(s);
	s->fm++;
	return (s);
}

t_info		*search_spec_format(t_info *s)
{
	s->fm++;
	s = search_flag(s);
	s = search_width(s);
	s = search_precision(s);
	s = search_type(s);
	return (s);
}
