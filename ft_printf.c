#include "includes/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		factor;
	t_tab		tab;

	if (!str)
		return (-1);
	va_start(factor, str);
	tab.len = 0;
	while(*str)
	{
		tab = ft_init(tab);
		tab = ft_putstr(&str, tab);
		if (*str)
			tab = ft_parse(&str, tab, factor);
		if (tab.type == -1)
			return (-1);
		tab = ft_parse_types(factor, tab);
	}
	va_end(factor);
	return (tab.len);
}
