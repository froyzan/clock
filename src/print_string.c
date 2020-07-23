/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/22 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_info	*print_string_2(t_info *s, char *str, char *temp, int strlen)
{
	if (s->flag[MINUS] == '1' && s->point != 1)
		ft_putstr(str);
	if (s->width > strlen)
	{
		s->len += s->width - strlen;
		s->width++;
		if (s->flag[ZERO] == '1' && s->flag[MINUS] != '1')
			while (--s->width > strlen)
				ft_putchar('0');
		else
			while (--s->width > strlen)
				ft_putchar(' ');
	}
	if (s->flag[MINUS] != '1' && s->point != 1)
		ft_putstr(str);
	s->len += strlen;
	free(str);
	if (ft_strcmp(temp, "(null)") == 0)
		free(temp);
	return (s);
}

t_info			*print_string(t_info *s)
{
	char	*str;
	char	*temp;
	int		strlen;

	temp = va_arg(s->ap, char *);
	if (temp == NULL)
	{
		temp = ft_strnew(6);
		ft_strcpy(temp, "(null)");
	}
	if (s->prec == 0)
	{
		str = ft_strnew(ft_strlen(temp));
		ft_strcpy(str, temp);
	}
	else
	{
		str = ft_strnew(s->prec);
		ft_strncpy(str, temp, s->prec);
	}
	if (s->point != 1)
		strlen = ft_strlen(str);
	else
		strlen = 0;
	return (print_string_2(s, str, temp, strlen));
}
