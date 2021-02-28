/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:19:39 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:19:41 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	ft_p_noflag(t_tab tab, unsigned long num)
{
	if (tab.wid > tab.count)
	{
		if (tab.pre == 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
		tab.spc -= 2;
		while (tab.spc > 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
	}
	if (tab.zero)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	write(1, "0x", 2);
	tab.size += 2;
	if (tab.count > 0)
		ft_recursion_p(num, tab);
	if (tab.pre >= tab.count + 1 && tab.num < 0)
		tab.size++;
	return (tab);
}

t_tab	ft_p_flag_zero(t_tab tab, unsigned long num)
{
	if (tab.spc && tab.pre >= 0)
	{
		if (num < 0)
			tab.spc--;
		tab.spc -= 2;
		while (tab.spc > 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
	}
	if (tab.zero > 0)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	write(1, "0x", 2);
	tab.size += 2;
	if (tab.count > 0)
		ft_recursion_p(num, tab);
	if (tab.pre >= tab.count + 1 && tab.num < 0)
		tab.size++;
	return (tab);
}

t_tab	ft_p_flag_minus(t_tab tab, unsigned long num)
{
	if (tab.zero)
		while (tab.zero > 0 && tab.zero-- > 0 && tab.size++ >= 0)
			write(1, "0", 1);
	write(1, "0x", 2);
	tab.size += 2;
	tab.spc -= 2;
	if (tab.count)
		ft_recursion_p(num, tab);
	if (tab.spc)
		while (tab.spc > 0 && tab.spc-- > 0 && tab.size++ >= 0)
			write(1, " ", 1);
	if (tab.pre >= tab.count + 1 && tab.num < 0)
		tab.size++;
	return (tab);
}

t_tab	ft_disp_p(va_list factor, t_tab tab)
{
	tab.num = va_arg(factor, unsigned long);
	if (!tab.num && !tab.pre && tab.wid <= 2)
	{
		write(1, "0x", 2);
		tab.len += 2;
		return (tab);
	}
	tab.count = ft_p_ulen(tab.num);
	tab = ft_find_counts(tab);
	if (tab.flag == 1)
		tab = ft_p_flag_zero(tab, tab.num);
	else if (tab.flag == 2)
		tab = ft_p_flag_minus(tab, tab.num);
	else
		tab = ft_p_noflag(tab, tab.num);
	tab.len += tab.count + tab.size;
	return (tab);
}
