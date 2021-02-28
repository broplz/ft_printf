/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:20:15 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:25:12 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	ft_flaginit(t_tab tab, const char **str, va_list factor)
{
	while (**str == '0' && **str && (*str)++)
		tab.flag = 1;
	while (**str == '-' && **str && (*str)++)
		tab.flag = 2;
	while (**str == '-' || **str == '0')
		(*str)++;
	if (**str == '*' && (*str)++)
		tab.wid = va_arg(factor, int);
	if (tab.wid < 0 && (tab.flag = 2))
		tab.wid *= -1;
	return (tab);
}

t_tab	ft_init(t_tab tab)
{
	tab.flag = 0;
	tab.wid = 0;
	tab.pre = -1;
	tab.type = 0;
	tab.size = 0;
	tab.zero = 0;
	tab.spc = 0;
	tab.count = 0;
	tab.num = 0;
	tab.i = 0;
	tab.j = 0;
	return (tab);
}
