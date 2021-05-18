#include "ft_printf.h"

int	ft_put_n(char c, int n)
{
	int	i;

	i = 0;
	while (n-- > 0)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}

int	ft_max(int precision, int num)
{
	if (precision < num)
		return (num);
	return (precision);
}

int	is_char_in_str(char symbol, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == symbol)
			return (1);
		i++;
	}
	return (0);
}

void	get_value_from_num(t_data **pData, va_list list)
{
	if ((*pData)->tp == 'p')
		parce_p(pData, list);
	else if ((*pData)->lon == 'l')
		get_value_from_long(pData, list);
	else if ((*pData)->lon == 'L')
		get_value_from_long_long(pData, list);
	else if ((*pData)->lon == 'h')
		get_value_from_short(pData, list);
	else if ((*pData)->lon == 'H')
		get_value_from_short_short(pData, list);
	else
		get_value_from_int(pData, list);
}

int	get_type_and_value(t_data **pData, char **pString, va_list list)
{
	get_type(pData, pString);
	if ((*pData)->tp == 'c')
		parce_char(pData, list);
	else if ((*pData)->tp == 's')
		(*pData)->v = ft_strdup(va_arg(list, char *));
	else if ((*pData)->tp == '%')
	{
		(*pData)->precision = -1;
		(*pData)->p_s = -1;
		(*pData)->v = ft_strdup("%");
	}
	else if (is_char_in_str((*pData)->tp, "ndiuxXp"))
	{
		get_value_from_num(pData, list);
	}
	else
		return (1);
	return (0);
}
