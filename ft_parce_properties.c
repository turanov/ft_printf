#include "ft_printf.h"

void	get_long_short(t_data **pData, char **pString)
{
	if (*(*pString) == 'l')
	{
		(*pData)->lon = 'l';
		(*pString)++;
		if (*(*pString) == 'l')
		{
			(*pData)->lon = 'L';
			(*pString)++;
		}
	}
	else if (*(*pString) == 'h')
	{
		(*pData)->lon = 'h';
		(*pString)++;
		if (*(*pString) == 'h')
		{
			(*pData)->lon = 'H';
			(*pString)++;
		}
	}
}

int	get_type(t_data **pData, char **pString)
{
	char	*types;

	types = "ncspdiuxX%";
	get_long_short(pData, pString);
	while (*types)
	{
		if (types[0] == *(*pString))
		{
			(*pData)->tp = *(*pString);
			(*pString)++;
			return (0);
		}
		types++;
	}
	return (1);
}

void	get_precision_helper(t_data **pData, char **pString,
						  va_list list, int check)
{
	if (*(*pString) == '*')
	{
		(*pData)->precision = va_arg(list, int);
		if ((*pData)->precision < 0)
			(*pData)->precision = -1;
		(*pString)++;
	}
	if (check)
	{
		(*pData)->width = (*pData)->precision;
		(*pData)->precision = -1;
	}
}

void	get_precision(t_data **pData, char **pString, va_list list)
{
	int	check;

	check = 0;
	if (*(*pString) == '.')
	{
		(*pString)++;
		(*pData)->precision = 0;
		if (*(*pString) == '-')
		{
			(*pData)->f = '-';
			check = 1;
			(*pString)++;
		}
		while (*(*pString) >= '0' && *(*(pString)) <= '9')
		{
			(*pData)->precision = (*pData)->precision * 10 + (*(*pString) - 48);
			(*pString)++;
		}
		get_precision_helper(pData, pString, list, check);
	}
}

void	get_width(t_data **pData, char **pString, va_list list)
{
	while (*(*pString) >= '0' && *(*(pString)) <= '9')
	{
		if ((*pData)->width == -1)
			(*pData)->width = 0;
		(*pData)->width = (*pData)->width * 10 + (*(*pString) - 48);
		(*pString)++;
	}
	if (*(*pString) == '*')
	{
		(*pData)->width = va_arg(list, int);
		if ((*pData)->width < 0)
		{
			(*pData)->f = '-';
			(*pData)->width *= -1;
		}
		(*pString)++;
	}
}
