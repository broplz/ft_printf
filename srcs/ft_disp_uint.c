/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:19:51 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:19:53 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab		ft_u_flag_minus(t_tab tab, unsigned int num)
{
	if (tab.zero)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	if (tab.j != 1337)
		ft_u_putnbr(num);
	if (tab.spc)
		while (tab.spc > 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
	return (tab);
}

t_tab		ft_u_noflag(t_tab tab, unsigned int num)
{
	if (tab.wid > tab.count)
	{
		if (tab.pre == 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
		while (tab.spc > 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
	}
	if (tab.zero)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	if (tab.j != 1337)
		ft_u_putnbr(num);
	return (tab);
}

t_tab		ft_u_flag_zero(t_tab tab, unsigned int num)
{
	if (tab.spc && tab.pre >= 0)
		while (tab.spc > 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
	if (tab.zero > 0)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	if (tab.j != 1337)
		ft_u_putnbr(num);
	if (tab.pre >= tab.count + 1 && tab.num < 0)
		tab.size++;
	return (tab);
}

t_tab		ft_disp_uint(va_list factor, t_tab tab)
{
	tab.num = va_arg(factor, unsigned int);
	if (!tab.num && !tab.pre)
		tab.j = 1337;
	tab.count = ft_int_ulen(tab.num);
	tab = ft_find_counts(tab);
	if (tab.flag == 1)
		tab = ft_u_flag_zero(tab, tab.num);
	else if (tab.flag == 2)
		tab = ft_u_flag_minus(tab, tab.num);
	else
		tab = ft_u_noflag(tab, tab.num);
	tab.len += tab.count + tab.size;
	return (tab);
}
