/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:21:05 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:21:06 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	ft_find_counts(t_tab tab)
{
	if (tab.pre > tab.count)
		tab.zero = tab.pre - tab.count;
	else if (tab.flag == 1 && tab.wid > tab.count && tab.pre < 0)
		tab.zero = tab.wid - tab.count;
	if (tab.pre == 0 && tab.num == 0)
		tab.count = 0;
	if (tab.wid)
	{
		tab.spc = tab.wid - tab.zero - tab.count;
		tab.spc -= (tab.num < 0 && tab.pre > tab.count \
		&& tab.pre < tab.wid) ? 1 : 0;
	}
	return (tab);
}

int		ft_type(int ch)
{
	char	*str;

	str = "cspiduxX%";
	while (*str)
	{
		if (*str == ch)
			return (1);
		str++;
	}
	return (0);
}

t_tab	ft_parse_types(va_list factor, t_tab tab)
{
	if (tab.type == '%' || tab.type == 'c')
		tab = ft_disp_char(factor, tab);
	if (tab.type == 'd' || tab.type == 'i')
		tab = ft_disp_int(factor, tab);
	if (tab.type == 's')
		tab = ft_disp_str(factor, tab);
	if (tab.type == 'u')
		tab = ft_disp_uint(factor, tab);
	if (tab.type == 'x' || tab.type == 'X')
		tab = ft_disp_hex(factor, tab);
	if (tab.type == 'p')
		tab = ft_disp_p(factor, tab);
	return (tab);
}

t_tab	ft_parse(const char **str, t_tab tab, va_list factor)
{
	tab = ft_flaginit(tab, str, factor);
	if (ft_isdigit(**str))
	{
		tab.wid = ft_atoi(*str);
		(*str) += ft_int_len(tab.wid);
	}
	if (**str == '.' && *(*str)++)
	{
		tab.pre = 0;
		if (**str == '*' && *(*str)++)
			tab.pre = va_arg(factor, int);
		while ((**str == '-' && (tab.pre = -1)) || **str == '0')
			(*str)++;
		if (ft_isdigit(**str) && tab.pre != -1)
			tab.pre = ft_atoi(*str);
		if (ft_isdigit(**str))
			(*str) += ft_int_len(ft_atoi(*str));
	}
	tab.type = **str && ft_type(**str) ? *(*str)++ : -1;
	return (tab);
}
