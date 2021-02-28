/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disp_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:17:44 by hcherrie          #+#    #+#             */
/*   Updated: 2021/01/20 19:22:00 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tab	ft_disp_str(va_list factor, t_tab tab)
{
	char	*string;
	int		len;

	string = va_arg(factor, char *);
	if (string == NULL)
		string = "(null)";
	len = ft_strlen(string);
	if (tab.pre < len && tab.pre >= 0)
		len = tab.pre;
	if (tab.wid > len && tab.flag == 2)
	{
		write(1, string, len);
		while (tab.i++ < tab.wid - len)
			write(1, " ", 1);
	}
	else
	{
		while (tab.i++ < tab.wid - len)
			write(1, " ", 1);
		write(1, string, len);
	}
	tab.len += tab.wid > len ? tab.wid : len;
	return (tab);
}
