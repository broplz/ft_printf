/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 20:10:40 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 20:10:44 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MIN_INT -2147483648
# define MAX_INT 2147483647
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_tab
{
	size_t		len;
	long		num;
	int			wid;
	int			spc;
	int			pre;
	int			flag;
	int			type;
	int			count;
	int			zero;
	int			size;
	int			i;
	int			j;
}				t_tab;

int				ft_printf(const char *str, ...);
int				ft_type(int ch);
int				ft_int_len(long i);
int				ft_int_ulen(unsigned long i);
t_tab			ft_init(t_tab tab);
t_tab			ft_parse(const char **str, t_tab tab, va_list factor);
t_tab			ft_parse_types(va_list factor, t_tab tab);
t_tab			ft_disp_char(va_list args, t_tab tab);
t_tab			ft_disp_str(va_list factor, t_tab tab);
t_tab			ft_putstr(const char **str, t_tab tab);
t_tab			ft_flaginit(t_tab tab, const char **str, va_list factor);
void			ft_putchar(char c);
void			ft_putnbr(long n);
void			ft_u_putnbr(unsigned int n);
t_tab			ft_flag_minus(t_tab tab, long num);
t_tab			ft_u_flag_minus(t_tab tab, unsigned int num);
t_tab			ft_find_counts(t_tab tab);
t_tab			ft_disp_hex(va_list factor, t_tab tab);
t_tab			ft_u_flag_zero(t_tab tab, unsigned int num);
t_tab			ft_u_noflag(t_tab tab, unsigned int num);
t_tab			ft_flag_zero(t_tab tab, long num);
t_tab			ft_noflag(t_tab tab, long num);
t_tab			ft_disp_uint(va_list factor, t_tab tab);
t_tab			ft_disp_int(va_list factor, t_tab tab);
t_tab			ft_x_noflag(t_tab tab, unsigned int num);
t_tab			ft_x_flag_minus(t_tab tab, unsigned int num);
t_tab			ft_x_flag_zero(t_tab tab, unsigned int num);
int				ft_x_ulen(unsigned int num);
void			ft_recursion_x(unsigned int num, t_tab tab);
void			ft_recursion_p(unsigned long num, t_tab tab);
t_tab			ft_disp_p(va_list factor, t_tab tab);
t_tab			ft_p_flag_zero(t_tab tab, unsigned long num);
t_tab			ft_p_flag_minus(t_tab tab, unsigned long num);
t_tab			ft_p_noflag(t_tab tab, unsigned long num);
int				ft_p_ulen(unsigned long num);
int				ft_atoi(const char *str);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int ch);

#endif
