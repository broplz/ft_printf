/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:18:54 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:23:55 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	ft_disp_char(va_list factor, t_tab tab)
{
	char dot;

	if (tab.type == '%')
	{
		dot = '%';
		if (!tab.wid)
		{
			tab.len++;
			write(1, &dot, 1);
			return (tab);
		}
	}
	else
		dot = va_arg(factor, int);
	if (tab.wid > 1 || tab.flag == 2)
	{
		if (tab.flag == 2 && ++tab.len)
			write(1, &dot, 1);
		while (--tab.wid > 0 && ++tab.len)
			tab.flag != 1 ? write(1, " ", 1) : write(1, "0", 1);
	}
	if (tab.flag != 2 && ++tab.len)
		write(1, &dot, 1);
	return (tab);
}
