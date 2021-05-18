#include "ft_printf.h"

void	get_flags(t_data **pData, char **pString)
{
	while (*(*pString) == '-' || *(*(pString)) == '0'
		   || *(*pString) == ' ' || *(*(pString)) == '+'
		   || *(*(pString)) == '#' )
	{
		if (*(*pString) == '-')
			(*pData)->f = '-';
		else if ((*pData)->f != '-' && *(*(pString)) == '0')
			(*pData)->f = '0';
		if (*(*pString) == '#')
			(*pData)->p_s = '#';
		else if (*(*pString) == '+' && (*pData)->p_s != '#')
			(*pData)->p_s = '+';
		else if (*(*pString) == ' ' && (*pData)->p_s != '+'
			&& (*pData)->p_s != '#')
			(*pData)->p_s = ' ';
		(*pString)++;
	}
}

void	solve_helper(t_data **data, char **str, va_list list)
{
	get_flags(data, str);
	get_width(data, str, list);
	get_precision(data, str, list);
}

int	solve(char **str, va_list list, int printed)
{
	t_data	*data;
	int		cnt;

	data = new_data();
	if (!data)
		return (-1);
	solve_helper(&data, str, list);
	if (*(*str) == '\0')
	{
		free(data);
		return (-1);
	}
	data->printed = printed;
	if (get_type_and_value(&data, str, list))
	{
		free(data);
		return (-1);
	}
	cnt = ftPrintData(data);
	if (data->v != NULL)
		free(data->v);
	free(data);
	return (cnt);
}

int	iterator(char *str, va_list list, int printed)
{
	int	cnt;
	int	cnt2;

	cnt = 0;
	while (*str != '\0' && *str != '%')
	{
		ft_putchar_fd(*str++, 1);
		cnt++;
	}
	if ((*str) == '%')
		str++;
	if (*str == '\0')
		return (cnt);
	cnt2 = solve(&str, list, printed + cnt);
	if (cnt2 == -1)
		return (-1);
	cnt += cnt2;
	if ((*str) == '\0')
		return (cnt);
	cnt2 = iterator(str, list, printed + cnt);
	if (cnt2 == -1)
		return (-1);
	return (cnt + cnt2);
}

int	ft_printf(const char *s, ...)
{
	int		cnt;
	va_list	list;

	va_start(list, s);
	cnt = iterator((char *)s, list, 0);
	va_end(list);
	return (cnt);
}
