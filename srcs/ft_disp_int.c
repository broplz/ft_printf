/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:19:31 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:19:33 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	ft_noflag(t_tab tab, long num)
{
	if (tab.wid > tab.count)
	{
		if (tab.pre == 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
		while (tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
	}
	if (num < 0)
		write(1, "-", 1);
	if (tab.zero)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	if (tab.count > 0)
		ft_putnbr(num);
	if (tab.pre >= tab.count + 1 && tab.num < 0)
		tab.size++;
	return (tab);
}

t_tab	ft_flag_zero(t_tab tab, long num)
{
	if (tab.spc && tab.pre >= 0)
		while (tab.spc > 0 && tab.size++ >= 0 && tab.spc-- > 0)
			write(1, " ", 1);
	if (num < 0)
		write(1, "-", 1);
	if (tab.zero > 0)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	if (tab.count > 0)
		ft_putnbr(num);
	if (tab.pre >= tab.count + 1 && tab.num < 0)
		tab.size++;
	return (tab);
}

t_tab	ft_flag_minus(t_tab tab, long num)
{
	if (num < 0)
		write(1, "-", 1);
	if (tab.zero)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	if (tab.count)
		ft_putnbr(num);
	if (tab.spc)
		while (tab.spc > 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
	if (tab.pre >= tab.count + 1 && tab.num < 0)
		tab.size++;
	return (tab);
}

t_tab	ft_disp_int(va_list factor, t_tab tab)
{
	tab.num = va_arg(factor, int);
	tab.count = ft_int_len(tab.num);
	if (tab.pre >= tab.count && tab.num < 0)
		tab.count--;
	tab = ft_find_counts(tab);
	if (tab.flag == 1)
		tab = ft_flag_zero(tab, tab.num);
	else if (tab.flag == 2)
		tab = ft_flag_minus(tab, tab.num);
	else
		tab = ft_noflag(tab, tab.num);
	tab.len += tab.count + tab.size;
	return (tab);
}
