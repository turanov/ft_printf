#include "ft_printf.h"

void	get_value_from_long(t_data **pData, va_list list)
{
	if ((*pData)->tp == 'n')
		parce_long_int_n(pData, list);
	else if ((*pData)->tp == 'd' || (*pData)->tp == 'i')
		parce_long_int(pData, list);
	else if ((*pData)->tp == 'u')
		parce_unsigned_long_int(pData, list);
	else
		parce_long_int_x(pData, list);
}

void	get_value_from_long_long(t_data **pData, va_list list)
{
	if ((*pData)->tp == 'n')
		parce_long_long_int_n(pData, list);
	else if ((*pData)->tp == 'd' || (*pData)->tp == 'i')
		parce_long_long_int(pData, list);
	else if ((*pData)->tp == 'u')
		parce_unsigned_long_long_int(pData, list);
	else
		parce_long_long_int_x(pData, list);
}

void	get_value_from_short(t_data **pData, va_list list)
{
	if ((*pData)->tp == 'n')
		parce_short_int_n(pData, list);
	else if ((*pData)->tp == 'd' || (*pData)->tp == 'i')
		parce_short_int(pData, list);
	else if ((*pData)->tp == 'u')
		parce_unsigned_short_int(pData, list);
	else
		parce_short_int_x(pData, list);
}

void	get_value_from_short_short(t_data **pData, va_list list)
{
	if ((*pData)->tp == 'n')
		parce_short_short_int_n(pData, list);
	else if ((*pData)->tp == 'd' || (*pData)->tp == 'i')
		parce_short_short_int(pData, list);
	else if ((*pData)->tp == 'u')
		parce_unsigned_short_short_int(pData, list);
	else
		parce_short_short_int_x(pData, list);
}

void	get_value_from_int(t_data **pData, va_list list)
{
	if ((*pData)->tp == 'n')
		parce_int_n(pData, list);
	else if ((*pData)->tp == 'd' || (*pData)->tp == 'i')
		parce_int(pData, list);
	else if ((*pData)->tp == 'u')
		parce_usigned_int(pData, list);
	else
		parce_int_x(pData, list);
}
