/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/22 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_info	*s;
	int		len;

	if (!(s = (t_info *)ft_calloc(1, sizeof(t_info))) || !format)
		return (-1);
	va_start(s->ap, format);
	s->fm = format;
	while (*s->fm)
	{
		while (*s->fm && *s->fm != '%')
		{
			ft_putchar(*s->fm);
			s->len++;
			s->fm++;
		}
		if (*s->fm && *s->fm == '%')
			s = search_spec_format(s);
	}
	va_end(s->ap);
	len = s->len;
	free(s);
	return (len);
}
