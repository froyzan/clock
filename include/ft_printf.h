/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psafflow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 10:19:59 by psafflow          #+#    #+#             */
/*   Updated: 2020/07/22 16:40:37 by psafflow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define MINUS		0
# define ZERO		1

typedef	struct		s_info
{
	va_list		ap;
	const char	*fm;
	char		flag[2];
	int			width;
	int			prec;
	int			len;
	int			point;
}					t_info;

/*
** Function call
*/
int			ft_printf(const char *format, ...);

/*
** Check flags, width, precision, type
*/
t_info		*search_spec_format(t_info *s);
t_info		*search_flag(t_info *s);
t_info		*search_width(t_info *s);
t_info		*search_precision(t_info *s);
t_info		*search_type(t_info *s);

/*
** Print type "cspdiuxX%"
*/
t_info		*print_char(t_info *s);
t_info		*print_string(t_info *s);
t_info		*print_pointer(t_info *s);
t_info		*print_decimal_integer(t_info *s);
t_info		*print_unsigned_int(t_info *s);
t_info		*print_hexadecimal(t_info *s);
t_info		*print_percentage(t_info *s);

/*
** Utils (libft)
*/
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_nbrlen(long long nbr);
void		ft_putchar(char c);
void		ft_puthex(unsigned int i, char c);
void		ft_putnbr(int i);
void		ft_putnchar(char c, int n);
void		ft_putstr(const char *s);
void		ft_putui(unsigned int i);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(const char *s);
int			ft_strnbr(char *sp);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strnew(size_t size);

#endif