#include "ft_printf.h"

void	parce_int_x(t_data **pData, va_list list)
{
	(*pData)->v = get_16(va_arg(list, unsigned int));
	if ((*pData)->tp != 'X')
		ft_to_lower_case((*pData)->v);
}

void	parce_long_int_x(t_data **pData, va_list list)
{
	(*pData)->v = get_16(va_arg(list, unsigned long int));
	if ((*pData)->tp != 'X')
		ft_to_lower_case((*pData)->v);
}

void	parce_long_long_int_x(t_data **pData, va_list list)
{
	(*pData)->v = get_16(va_arg(list, unsigned long long int));
	if ((*pData)->tp != 'X')
		ft_to_lower_case((*pData)->v);
}

void	parce_short_int_x(t_data **pData, va_list list)
{
	(*pData)->v = get_16((unsigned short int)va_arg(list, int));
	if ((*pData)->tp != 'X')
		ft_to_lower_case((*pData)->v);
}

void	parce_short_short_int_x(t_data **pData, va_list list)
{
	(*pData)->v = get_16((unsigned char) va_arg(list, int));
	if ((*pData)->tp != 'X')
		ft_to_lower_case((*pData)->v);
}
